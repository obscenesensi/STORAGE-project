
#define NAME_SIZE					20
#define BUF_SIZE					500

#define STONE_COLOR_BLACK			10
#define STONE_COLOR_WHITE			11

#define NO_SELECT_STRING			""
#define NO_SELECT_OPTION			0
#define WAIT_ROOM_NUMBER			-1

#define GAME_STATUS_WAIT			1
#define GAME_STATUS_GAME			2
#define GAME_STATUS_INFOMATION		3

#define WAIT_COMMAND_CREATE			1
#define WAIT_COMMAND_JOIN			2
#define WAIT_COMMAND_CHAT			3

#define GAME_COMMAND_START			1
#define GAME_COMMAND_READY			2
#define GAME_COMMAND_COORDINATE		3
#define GAME_COMMAND_CHAT			4
#define GAME_COMMAND_GIVEUP			5
#define GAME_COMMAND_GAMEOVER		6

struct omok_client_to_server {
	short game_status;
	short game_command;
	short room_number;
	short coordinate_x;
	short coordinate_y;
	short stone_color;
	char sender_name[NAME_SIZE];
	char message[BUF_SIZE];
};

#define CMD_STATUS_ROOM				1
#define CMD_STATUS_CHAT				2
#define CMD_STATUS_LIST				3
#define CMD_STATUS_COORDINATE		4
#define CMD_STATUS_STONE			5
#define CMD_STATUS_ROOM_STONE		6
#define CMD_STATUS_READY			7
#define CMD_STATUS_START			8
#define CMD_STATUS_WAIT_CHAT		9

struct omok_server_to_client {
	short cmd_status;
	short room_number;
	short coordinate_x;
	short coordinate_y;
	short stone_color;
	char sender_name[NAME_SIZE];
	char message[BUF_SIZE];
};
