#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include "omok_protocol.h"

#define BUF_SIZE				500
#define LIST_SIZE				100
#define NAME_SIZE				20
#define STAT_SIZE				5

#define ROOM_SIZE				10
#define ROOM_NAME_SIZE			20

#define GAME_ROOM_NOT_EXIST		0
#define GAME_ROOM_WAIT			1
#define GAME_ROOM_PROCESS		2

#define PLAYER_TURN_HOST		0
#define PLAYER_TURN_GUEST		1

#define BLACK_STONE				10
#define WHITE_STONE				11

void init_game_room();
void* clnt_connection(void* arg);
void recv_message(int sock);

void command_process(struct omok_client_to_server c_frame, int sock);
int create_room(char* c_name, char* r_name, int sock);
void join_room(char* j_name, int num, int sock);
void send_list(void);
void make_frame(struct omok_server_to_client* s_frame, short status, short number, short x, short y, short color, char* name, char* message);

void send_users(struct omok_server_to_client s_frame);
void send_user(struct omok_server_to_client s_frame, int sock);
void send_room_users(struct omok_server_to_client s_frame, int num);

void error_handling(char* message);

struct game_room {
	char	room_name[ROOM_NAME_SIZE];
	int		host_sock;
	int		guest_sock;
	char	host_name[NAME_SIZE];
	char	guest_name[NAME_SIZE];
	int		game_status;
	int		player_turn;
} game_room_info[10];

int clnt_number = 0;
int clnt_socks[10];

int main(int argc, char** argv)
{
	int serv_sock;
	int clnt_sock;
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr;
	int clnt_addr_size;
	pthread_t thread;

	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind() error");

	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	// game_room 초기화
	init_game_room();

	while (1) {
		clnt_addr_size = sizeof(clnt_addr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);

		clnt_socks[clnt_number++] = clnt_sock;

		pthread_create(&thread, NULL, clnt_connection, (void*)clnt_sock);
		printf("새로운 연결, 클라이언트 IP : %s\n", inet_ntoa(clnt_addr.sin_addr));

		send_list();
	}
	return 0;
}

void* clnt_connection(void* arg)
{
	int clnt_sock = (int)arg;
	int i;

	write(clnt_sock, "room -1", strlen("room -1"));
	
	recv_message(clnt_sock);

	for (i=0; i<clnt_number-1; i++) {
		if (clnt_sock == clnt_socks[i]) {
			for (; i<clnt_number; i++)
				clnt_socks[i] = clnt_socks[i+1];
			break;
		}
	}

	clnt_number--;

	close(clnt_sock);
	return 0;
}

void recv_message(int sock) {
	int str_len = 0;
	struct omok_client_to_server c_frame;

	
	while ((str_len = recv(sock, (struct omok_client_to_server*) &c_frame, sizeof(struct omok_client_to_server), 0)) != 0) {
		command_process(c_frame, sock);
		bzero((struct omok_client_to_server*) &c_frame, sizeof(struct omok_client_to_server));
	}
}

void init_game_room()
{
	int i;

	for (i=0; i<ROOM_SIZE; i++) {
		game_room_info[i].game_status = GAME_ROOM_NOT_EXIST;
		strcpy(game_room_info[i].host_name, "");
		strcpy(game_room_info[i].guest_name, "");
	}
}

void command_process(struct omok_client_to_server c_frame, int sock)
{
	int room_number = c_frame.room_number;
	struct omok_server_to_client s_frame;

	switch (c_frame.game_status) {
	case GAME_STATUS_WAIT :
		switch (c_frame.game_command) {
		case WAIT_COMMAND_CREATE :
			create_room(c_frame.sender_name, c_frame.message, sock);
			break;

		case WAIT_COMMAND_JOIN :
			join_room(c_frame.sender_name, room_number, sock);
			break;

		case WAIT_COMMAND_CHAT :
			make_frame(&s_frame, CMD_STATUS_WAIT_CHAT, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_OPTION, c_frame.sender_name, c_frame.message);;
			send_users(s_frame);
			break;

		}
		break;
		
	case GAME_STATUS_GAME :
		switch (c_frame.game_command) {
		case GAME_COMMAND_COORDINATE :
			make_frame(&s_frame, CMD_STATUS_COORDINATE, NO_SELECT_OPTION, c_frame.coordinate_x, c_frame.coordinate_y, c_frame.stone_color, NO_SELECT_STRING, NO_SELECT_STRING);
			send_room_users(s_frame, room_number);
			break;

		case GAME_COMMAND_CHAT :
			make_frame(&s_frame, CMD_STATUS_CHAT, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_OPTION, c_frame.sender_name, c_frame.message);;
			send_room_users(s_frame, room_number);
			break;

		case GAME_COMMAND_GIVEUP :
			// 호스트가 나가게 되면 방을 초기화..
			if (sock == game_room_info[room_number].host_sock) {
				game_room_info[room_number].game_status = GAME_ROOM_NOT_EXIST;
				make_frame(&s_frame, CMD_STATUS_ROOM, WAIT_ROOM_NUMBER, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_STRING, NO_SELECT_STRING);
				send_room_users(s_frame, room_number);

				// guest에게 host가 나갔음을 알린다.
				make_frame(&s_frame, CMD_STATUS_CHAT, WAIT_ROOM_NUMBER, NO_SELECT_OPTION, NO_SELECT_OPTION, STONE_COLOR_WHITE, game_room_info[room_number].guest_name, "방을 나갔습니다.");
				send_user(s_frame, game_room_info[room_number].guest_sock);
			}
			// 게스트가 나가게 되면 방을 대기 상태로..
			else {
				game_room_info[room_number].game_status = GAME_ROOM_WAIT;
				strcpy(game_room_info[room_number].guest_name, "");
				make_frame(&s_frame, CMD_STATUS_ROOM, WAIT_ROOM_NUMBER, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_STRING, NO_SELECT_STRING);
				send_user(s_frame, sock);
				
				// host에게 guest가 나갔음을 알린다.
				make_frame(&s_frame, CMD_STATUS_CHAT, room_number, NO_SELECT_OPTION, NO_SELECT_OPTION, STONE_COLOR_WHITE, game_room_info[room_number].host_name, "방을 나갔습니다.");
				send_user(s_frame, game_room_info[room_number].host_sock);
			}

			send_list();
			break;
			
		case GAME_COMMAND_GAMEOVER :
			
			break;

		case GAME_COMMAND_START : 
			make_frame(&s_frame, CMD_STATUS_START, room_number, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_STRING, NO_SELECT_STRING);
			send_user(s_frame, game_room_info[room_number].guest_sock);
			break;

		case GAME_COMMAND_READY : 
			make_frame(&s_frame, CMD_STATUS_READY, room_number, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_OPTION, NO_SELECT_STRING, NO_SELECT_STRING);
			send_user(s_frame, game_room_info[room_number].host_sock);
			break;
			
		}
		break;
	}
}

int create_room(char* c_name, char* r_name, int sock)
{
	int i;
	struct omok_server_to_client s_frame;

	for (i=0; i<ROOM_SIZE; i++) {
		if (game_room_info[i].game_status == GAME_ROOM_NOT_EXIST) {
			game_room_info[i].game_status = GAME_ROOM_WAIT;
			game_room_info[i].player_turn = PLAYER_TURN_HOST;
			game_room_info[i].host_sock = sock;
			strcpy(game_room_info[i].room_name, r_name);
			strcpy(game_room_info[i].host_name, c_name);
			strcpy(game_room_info[i].guest_name, "");

			make_frame(&s_frame, CMD_STATUS_ROOM_STONE, i, NO_SELECT_OPTION, NO_SELECT_OPTION, STONE_COLOR_BLACK, NO_SELECT_STRING, NO_SELECT_STRING);
			send_user(s_frame, sock);
			
			send_list();
			return i;
		}
	}

	return -1;
}

void join_room(char* j_name, int num, int sock)
{
	char cmd_buffer[BUF_SIZE];
	struct omok_server_to_client s_frame;
	
	if (game_room_info[num].game_status == GAME_ROOM_WAIT) {
		game_room_info[num].game_status = GAME_ROOM_PROCESS;
		game_room_info[num].guest_sock = sock;
		strcpy(game_room_info[num].guest_name, j_name);

		make_frame(&s_frame, CMD_STATUS_ROOM_STONE, num, NO_SELECT_OPTION, NO_SELECT_OPTION, STONE_COLOR_WHITE, NO_SELECT_STRING, NO_SELECT_STRING);
		send_user(s_frame, sock);

		// host에게 guest가 들어왔음을 알린다.
		make_frame(&s_frame, CMD_STATUS_CHAT, num, NO_SELECT_OPTION, NO_SELECT_OPTION, STONE_COLOR_WHITE, j_name, "방에 들어왔습니다.");
		send_user(s_frame, game_room_info[num].host_sock);

		send_list();
	}
}

void send_list()
{
	int i, check = 0;
	struct omok_server_to_client s_frame;
	char buf1[LIST_SIZE];

	s_frame.cmd_status = CMD_STATUS_LIST;
	strcpy(s_frame.message, "");
	
	for (i=0; i<ROOM_SIZE; i++) {
		if (game_room_info[i].game_status == GAME_ROOM_WAIT || game_room_info[i].game_status == GAME_ROOM_PROCESS) {
			char status[STAT_SIZE];

			if (check == 0)
				check = 1;

			if (game_room_info[i].game_status == GAME_ROOM_WAIT)
				strcpy(status, "1/2");
			else
				strcpy(status, "2/2");

			sprintf(buf1, "│%-4d%-32s%-10s%-10s%-4s│\n", i, game_room_info[i].room_name, game_room_info[i].host_name, game_room_info[i].guest_name, status);
			strcat(s_frame.message, buf1);
		}
	}

	if (check == 0)
		strcpy(s_frame.message, "\n");

	send_users(s_frame);
}

void make_frame(struct omok_server_to_client* s_frame, short status, short number, short x, short y, short color, char* name, char* message)
{
	s_frame->cmd_status = status;
	s_frame->room_number = number;
	s_frame->coordinate_x = x;
	s_frame->coordinate_y = y;
	s_frame->stone_color = color;
	strcpy(s_frame->sender_name, name);
	strcpy(s_frame->message, message);
}

void send_users(struct omok_server_to_client s_frame)
{
	int i;

	for (i=0; i<clnt_number; i++)
		send(clnt_socks[i], (struct omok_server_to_client*) &s_frame, sizeof(struct omok_server_to_client), 0);
}

void send_user(struct omok_server_to_client s_frame, int sock)
{
	send(sock, (struct omok_server_to_client*) &s_frame, sizeof(struct omok_server_to_client), 0);
}

void send_room_users(struct omok_server_to_client s_frame, int num)
{
	send(game_room_info[num].host_sock, (struct omok_server_to_client*) &s_frame, sizeof(struct omok_server_to_client), 0);
	send(game_room_info[num].guest_sock, (struct omok_server_to_client*) &s_frame, sizeof(struct omok_server_to_client), 0);
}


void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
