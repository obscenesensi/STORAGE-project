#include <stdio.h>
#include <string.h>
#include "omok_engine.h"

int omok_status[OMOK_ROW_SIZE][OMOK_COL_SIZE];

void init_omok()
{
	int i, j;
	
	for (i=0; i<OMOK_ROW_SIZE; i++) {
		for (j=0; j<OMOK_COL_SIZE; j++) {
			if (i == 0) {
				if (j == 0)
					omok_status[i][j] = LINE_LEFT_UP;
				else if (j == OMOK_COL_SIZE - 1)
					omok_status[i][j] = LINE_RIGHT_UP;
				else
					omok_status[i][j] = LINE_UP;
			}
			else if (i == OMOK_ROW_SIZE - 1) {
				if (j == 0)
					omok_status[i][j] = LINE_LEFT_DOWN;
				else if (j == OMOK_COL_SIZE - 1)
					omok_status[i][j] = LINE_RIGHT_DOWN;
				else
					omok_status[i][j] = LINE_DOWN;
			}
			else {
				if (j == 0)
					omok_status[i][j] = LINE_LEFT;
				else if (j == OMOK_COL_SIZE - 1)
					omok_status[i][j] = LINE_RIGHT;
				else
					omok_status[i][j] = LINE_CENTER;
			}
		}
	}
}

void print_omok()
{
	int i, j;

	printf("    ");
	for (i=1; i<OMOK_COL_SIZE+1; i++)
		printf("%2d", i);
	printf("\n");

	printf("  忙式式式式式式式式式式式式式式式式式式式忖\n");
	
	for (i=0; i<OMOK_ROW_SIZE; i++) {
		printf("%2d弛", i+1);
		for (j=0; j<OMOK_COL_SIZE; j++) {
			switch(omok_status[i][j]) {
			case LINE_LEFT_UP :
				printf("%s", "忙");
				break;
			case LINE_UP :
				printf("%s", "成");
				break;
			case LINE_RIGHT_UP :
				printf("%s", "忖");
				break;
			case LINE_LEFT :
				printf("%s", "戍");
				break;
			case LINE_CENTER :
				printf("%s", "托");
				break;
			case LINE_RIGHT	:
				printf("%s", "扣");
				break;
			case LINE_LEFT_DOWN	:
				printf("%s", "戌");
				break;
			case LINE_DOWN :
				printf("%s", "扛");
				break;
			case LINE_RIGHT_DOWN :
				printf("%s", "戎");
				break;
			case BLACK_STONE :
				printf("%s", "≒");
				break;
			case WHITE_STONE :
				printf("%s", "∞");
				break;
			}
		}
		printf("弛\n");
	}
	printf("  戌式式式式式式式式式式式式式式式式式式式戎\n");
}

void lay_omok(int x, int y, int stone)
{
	omok_status[x-1][y-1] = stone;	
}

int result_omok()
{
	int i, j, ret = FAILURE_OMOK;

	for (i=0; i<OMOK_ROW_SIZE; i++)
		for (j=0; j<OMOK_COL_SIZE; j++)
			if (omok_status[i][j] == BLACK_STONE || omok_status[i][j] == WHITE_STONE)
				if (find_omok(i, j) == SUCCESS_OMOK)
					ret = SUCCESS_OMOK;

	return ret;
}

int get_omok(int x, int y)
{
	return omok_status[x-1][y-1];
}

int find_omok(int x, int y)
{
	int res1 = FAILURE_OMOK, res2 = FAILURE_OMOK, res3 = FAILURE_OMOK, res4 = FAILURE_OMOK;

	if (y <= OMOK_COL_SIZE - OMOK_WIN_COUNT && omok_status[x][y] == omok_status[x][y+1])
		res1 = check_omok(x, y+1, DIRECTION_RIGHT, 2);
	if (x <= OMOK_ROW_SIZE - OMOK_WIN_COUNT && y <= OMOK_COL_SIZE - OMOK_WIN_COUNT && omok_status[x][y] == omok_status[x+1][y+1])
		res2 = check_omok(x+1, y+1, DIRECTION_RIGHT_DOWN, 2);
	if (x <= OMOK_ROW_SIZE - OMOK_WIN_COUNT && omok_status[x][y] == omok_status[x+1][y])
		res3 = check_omok(x+1, y, DIRECTION_DOWN, 2);
	if (x <= OMOK_ROW_SIZE - OMOK_WIN_COUNT && y >= OMOK_WIN_COUNT - 1 && omok_status[x][y] == omok_status[x+1][y-1])
		res4 = check_omok(x+1, y-1, DIRECTION_LEFT_DOWN, 2);

	return (res1 == SUCCESS_OMOK || res2 == SUCCESS_OMOK || res3 == SUCCESS_OMOK || res4 == SUCCESS_OMOK) ? SUCCESS_OMOK : FAILURE_OMOK;
}

int check_omok(int x, int y, int direction, int count)
{
	switch (direction){
	case DIRECTION_RIGHT :
		if (omok_status[x][y] == omok_status[x][y+1])
			return check_omok(x, y+1, DIRECTION_RIGHT, ++count);
		break;
	case DIRECTION_RIGHT_DOWN :
		if (omok_status[x][y] == omok_status[x+1][y+1])
			return check_omok(x+1, y+1, DIRECTION_RIGHT_DOWN, ++count);
		break;
	case DIRECTION_DOWN :
		if (omok_status[x][y] == omok_status[x+1][y])
			return check_omok(x+1, y, DIRECTION_DOWN, ++count);
		break;
	case DIRECTION_LEFT_DOWN :
		if (omok_status[x][y] == omok_status[x+1][y-1])
			return check_omok(x+1, y-1, DIRECTION_LEFT_DOWN, ++count);
		break;
	}

	if (count >= 5)
		return SUCCESS_OMOK;

	return FAILURE_OMOK;
}
