// 원의 반지름을 입력받아서 둘레를 산출하는 프로그램을 주소전달함수를 이용하여 작성하라. 둘레를 구하는 
// circumference()함수의 표제부는 다음과 같다. void circumference ( int radius, double *circle)

#include "stdafx.h"
#include "stdlib.h"


void circumference(int radius, double *circle);


int main()
{
	
	int r = 0;
	double pc = 0;
	
	
	printf("원의 반지름을 입력받아서 둘레를 산출하는 프로그램");
	printf("\n원의 반지름을 입력하세요 : ");
	scanf("%d",&r);

	circumference(r,&pc);
		

	printf("\n원의 둘레는 %.2lf입니다.", pc);


    return 0;
}

void circumference(int radius, double *circle)
{
	*circle = (2) * (radius) * (3.14);

}
