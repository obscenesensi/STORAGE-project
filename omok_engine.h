#define LINE_LEFT_UP			1
#define LINE_UP					2
#define LINE_RIGHT_UP			3
#define LINE_LEFT				4
#define LINE_CENTER				5
#define LINE_RIGHT				6
#define LINE_LEFT_DOWN			7
#define LINE_DOWN				8
#define LINE_RIGHT_DOWN			9
#define BLACK_STONE				10
#define WHITE_STONE				11

#define DIRECTION_RIGHT			1
#define DIRECTION_RIGHT_DOWN	2
#define DIRECTION_DOWN			3
#define DIRECTION_LEFT_DOWN		4

#define FAILURE_OMOK			-1
#define SUCCESS_OMOK			0

#define OMOK_WIN_COUNT			5

#define OMOK_ROW_SIZE			19
#define OMOK_COL_SIZE			19

void init_omok(void);
void print_omok(void);
void lay_omok(int x, int y, int stone);
int result_omok(void);
int get_omok(int x, int y);
int find_omok(int x, int y);
int check_omok(int x, int y, int direction, int count);
