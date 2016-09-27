// ConsoleApplication12.c : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
// 0 ~ 360사이 각을 입력받아 radian을 구하는 프로그램 주소전달함수이용. 
// get_radian()함수로 rad 는 메인에서 중심각을나타내는 변수
// radian = (degree / 180) * PI
// void get_radian (int degree, float *rad

#include "stdafx.h"
#include "stdlib.h"
#define PI 3.14

void get_radian(int degree, float *rad);


int main()
{
	int d = 0;
	float r = 0;
	printf(" 0 ~ 360사이 각을 입력받아 radian을 구하는 프로그램\n");
	printf(" 0 ~ 360사이 각을 입력하세요 : ");
	scanf("%d", &d);

	get_radian(d,&r);
	printf("\n radian은 : %f", r);

	return 0;
}
void get_radian(int degree, float *rad)
{
	*rad = (float)degree / 180 * PI;
}


