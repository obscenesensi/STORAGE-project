#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
#include "omok_engine.h"
#include "omok_protocol.h"

#define BUF_SIZE		500
#define NAME_SIZE		20
#define CHAT_SIZE		5


#define GAME_MY_TURN	0
#define GAME_YOUR_TURN	1

#define GAME_WAIT		2
#define GAME_READY		3
#define GAME_START		4
#define GAME_OVER		5


void* send_message(void* arg);
void* recv_message(void* arg);

void send_process(int sock);
void recv_process(struct omok_server_to_client s_frame);
void error_handling(char* message);
int isDigit(char* str);

void clrscr(void);
void init_chat_dialog(void);
void print_chat_dialog(void);
void add_chat_dialog(char* message);

void init_room_dialog(void);
void print_room_dialog(void);

void print_command(void);
void print_main_panel(void);

char name[NAME_SIZE] = "[NoName]";
char message[BUF_SIZE];
char list_dialog[BUF_SIZE];
char chat_dialog[CHAT_SIZE][BUF_SIZE];
int my_stone;
int my_turn;
int room_number = -1;

int main(int argc, char** argv)
{
	int sock;
	struct sockaddr_in serv_addr;
	pthread_t snd_thread, rcv_thread;
	void* thread_result;

	if (argc != 4) {
		printf("Usage : %s <IP> <PORT> <NAME>\n", argv[0]);
		exit(1);
	}

	sprintf(name, "[%s]", argv[3]);

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");

	init_omok();
	init_chat_dialog();

	pthread_create(&snd_thread, NULL, send_message, (void*)sock);
	pthread_create(&rcv_thread, NULL, recv_message, (void*)sock);

	pthread_join(snd_thread, &thread_result);
	pthread_join(rcv_thread, &thread_result);

	close(sock);
	return 0;
}

void* send_message(void* arg)
{
	int sock = (int)arg;

	while (1) {
		print_main_panel();
		send_process(sock);
	}
}

void* recv_message(void* arg)
{
	int sock = (int)arg;
	int str_len;
	struct omok_server_to_client s_frame;

	while (1) {
		str_len = recv(sock, (struct omok_server_to_client*) &s_frame, sizeof(struct omok_server_to_client), 0);
		if (str_len == -1)
			return (void*)1;

		recv_process(s_frame);
		print_main_panel();
	}
}

void send_process(int sock)
{
	struct omok_client_to_server c_frame;
	char cmd_buffer1[BUF_SIZE];
	char* command1;

	fgets(message, BUF_SIZE, stdin);
	
	if (!strcmp(message, "q\n") || !strcmp(message, "ㅂ\n")) {
		close(sock);
		exit(0);
	}
	else if (!strcmp(message, "\n")) {
		return;
	}
	
	message[strlen(message) - 1] = '\0';
	strcpy(cmd_buffer1, message);
	command1 = strtok(cmd_buffer1, " ");

	if (room_number > -1) {
		if (isDigit(command1) == 0) {
			int coord_x = atoi(command1);
			char* command2 = strtok(NULL, " ");
			
			if (my_turn != GAME_MY_TURN) {
				add_chat_dialog("안내 : 내 차례에만 두어야 합니다.");
				return;
			}

			else if (isDigit(command2) == 0) {
				int coord_y = atoi(command2);

				if (coord_x < 0 || coord_x >= OMOK_ROW_SIZE || coord_y < 0 && coord_y >= OMOK_COL_SIZE) {
					add_chat_dialog("안내 : 좌표의 범위가 잘못 되었습니다.");
					return;
				}

				else if (get_omok(coord_x, coord_y) == BLACK_STONE || get_omok(coord_x, coord_y) == WHITE_STONE) {
					add_chat_dialog("안내 : 그 위치에는 돌이 놓여져 있습니다.");
					return;
				}

				else {
					c_frame.game_status = GAME_STATUS_GAME;
					c_frame.game_command = GAME_COMMAND_COORDINATE;
					c_frame.room_number = room_number;
					c_frame.coordinate_x = coord_x;
					c_frame.coordinate_y = coord_y;
					c_frame.stone_color = my_stone;
				}
			}

			else {
				add_chat_dialog("안내 : 잘못 입력하였습니다.");
				return;
			}

		}

		else if (strcmp(command1, "chat") == 0 || strcmp(command1, "채팅") == 0) {
			char* command2 = message + strlen(command1) + 1;
			
			c_frame.game_status = GAME_STATUS_GAME;
			c_frame.game_command = GAME_COMMAND_CHAT;
			c_frame.room_number = room_number;
			strcpy(c_frame.sender_name, name);
			strcpy(c_frame.message, command2);
		}

		else if (strcmp(command1, "g") == 0 || strcmp(command1, "ㅎ") == 0) {
			c_frame.game_status = GAME_STATUS_GAME;
			c_frame.game_command = GAME_COMMAND_GIVEUP;
			c_frame.room_number = room_number;
		}

		else if ((strcmp(command1, "ready") == 0 || strcmp(command1, "레디") == 0) && my_turn == GAME_READY) {
			c_frame.game_status = GAME_STATUS_GAME;
			c_frame.game_command = GAME_COMMAND_READY;
			c_frame.room_number = room_number;

			my_turn = GAME_YOUR_TURN;
		}

		else if ((strcmp(command1, "start") == 0 || strcmp(command1, "스타트") == 0) && my_turn == GAME_START) {
			c_frame.game_status = GAME_STATUS_GAME;
			c_frame.game_command = GAME_COMMAND_START;
			c_frame.room_number = room_number;

			my_turn = GAME_MY_TURN;
		}

		else {
			add_chat_dialog("잘못 입력하였습니다.");
			return;
		}
		
	}
	
	else {
		if (strcmp(command1, "c") == 0 || strcmp(command1, "ㅊ") == 0) { // message에 방의 이름
			char* command2 = message + strlen(command1) + 1;

			c_frame.game_status = GAME_STATUS_WAIT;
			c_frame.game_command = WAIT_COMMAND_CREATE;
			strcpy(c_frame.sender_name, name);
			strcpy(c_frame.message, command2);

			// 게임시작 순서를 정한다.
			my_turn = GAME_WAIT;
		}

		else if (strcmp(command1, "j") == 0 || strcmp(command1, "ㅓ") == 0) {
			char* command2 = message + strlen(command1) + 1;
			int room_number = atoi(command2);

			c_frame.game_status = GAME_STATUS_WAIT;
			c_frame.game_command = WAIT_COMMAND_JOIN;
			c_frame.room_number = room_number;
			strcpy(c_frame.sender_name, name);

			// 게임시작 순서를 정한다.
			my_turn = GAME_READY;
		}

		else if (strcmp(command1, "chat") == 0 || strcmp(command1, "채팅") == 0) {
			char* command2 = message + strlen(command1) + 1;

			c_frame.game_status = GAME_STATUS_WAIT;
			c_frame.game_command = WAIT_COMMAND_CHAT;
			strcpy(c_frame.sender_name, name);
			strcpy(c_frame.message, command2);
		}

		else {
			add_chat_dialog("잘못 입력하였습니다.");
			return;
		}
	}

	send(sock, (struct omok_client_to_server*) &c_frame, sizeof(struct omok_client_to_server), 0);
}

void recv_process(struct omok_server_to_client s_frame)
{
	char buffer[BUF_SIZE];

	switch(s_frame.cmd_status) {			
	case CMD_STATUS_ROOM :
		room_number = s_frame.room_number;
		break;

	case CMD_STATUS_CHAT :
		sprintf(buffer, "%s %s", s_frame.sender_name, s_frame.message);
		add_chat_dialog(buffer);
		break;

	case CMD_STATUS_LIST :
		strcpy(list_dialog, s_frame.message);
		break;

	case CMD_STATUS_COORDINATE :
		lay_omok(s_frame.coordinate_x, s_frame.coordinate_y, s_frame.stone_color);
		if (result_omok() == SUCCESS_OMOK) {
			if (my_turn == GAME_MY_TURN) {
				add_chat_dialog("안내 : 게임에서 승리하였습니다.");
			}
			else {
				add_chat_dialog("안내 : 게임에서 패배하였습니다.");
			}
			my_turn = GAME_OVER;
		} 
		else  {
			// 돌이 놓여졌으므로 순서가 변경된다.
			my_turn = (my_turn + 1) % 2;
		}
		break;

	case CMD_STATUS_STONE :
		my_stone = s_frame.stone_color;
		break;

	case CMD_STATUS_ROOM_STONE :
		room_number = s_frame.room_number;
		my_stone = s_frame.stone_color;
		break;

	case CMD_STATUS_START :
		my_turn = GAME_YOUR_TURN;
		break;	

	case CMD_STATUS_READY :
		my_turn = GAME_START;
		break;	

	case CMD_STATUS_WAIT_CHAT :
		if (room_number == -1) {
			sprintf(buffer, "%s %s", s_frame.sender_name, s_frame.message);
			add_chat_dialog(buffer);
		}
		break;	
	}
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}


int isDigit(char* str)
{
	int i;
	int len = strlen(str);

	if ((str[0] >= '0' && str[0] <= '9') || str[0] == '+' || str[0] == '-') {
		for (i=1; i<len; i++) {
			if (str[i] < '0' || str[i] > '9')
				return -1;
		}

		return 0;
	}

	return -1;
}

void clrscr() 
{ 
   printf ("%c[2J%c[1;1H", 27, 27); 
}

void init_chat_dialog() 
{
	int i;

	for (i=0; i<CHAT_SIZE; i++)
		strcpy(chat_dialog[i], "");
}

void add_chat_dialog(char* message)
{
	int i;

	for (i=0; i<CHAT_SIZE-1; i++)
		strcpy(chat_dialog[i], chat_dialog[i+1]);

	strcpy(chat_dialog[CHAT_SIZE-1], message);
}

void print_chat_dialog()
{
	int i;

	printf("┌──────────────────────────────┐\n");
	for (i=0; i<CHAT_SIZE; i++)
		printf("│%-60s│\n", chat_dialog[i]);
	printf("├──────────────────────────────┤\n");
}

void init_room_dialog()
{

}

void print_room_dialog() 
{
	int i;

	printf("┌─┬───────────────┬────┬────┬──┐\n");
	printf("│No│      Room Name               │  host  │ guest  │stat│\n");
	printf("├─┴───────────────┴────┴────┴──┤\n");
	if (strcmp(list_dialog, "\n"))
		printf("%s", list_dialog);
	printf("└──────────────────────────────┘\n");
	

}

void print_command()
{
	if (room_number > -1) {
		printf("│[x좌표 y좌표], [chat 대화내용], [g(기권)] ");


		if (my_turn == GAME_WAIT)
			printf("%18s│\n", " guest 대기중");
		else if (my_turn == GAME_READY)
			printf("%18s│\n", " [ready]");
		else if (my_turn == GAME_START)
			printf("%18s│\n", " [start]");
		else if (my_turn == GAME_MY_TURN)
			printf("%18s│\n", " ★my turn★");
		else
			printf("                  │\n");

	}
	else
		printf("│방개설(c 방이름), 방참여(j 방번호), 나가기(q)               │\n");

	printf("└──────────────────────────────┘\n >> ");
}

void print_main_panel() {
	clrscr();
	if (room_number > -1)
		print_omok();
	else
		print_room_dialog();

	print_chat_dialog();
	print_command();
}
