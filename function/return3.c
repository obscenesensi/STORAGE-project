#define pi 3.14

#include <stdio.h>
float area(float r);




int main()
{
	float x,y;
	printf("원의 반지름을 입력받아서 원의 넓이를 구하는 프로그램 입니다.\n\n\n");
	printf("반지름을 입력해 주세요 : ");
	scanf("%f", &x);
	y = area(x);
	printf("\n\n원의 넓이는 : %.1f\n\n", y);
	return 0;
}


float area(float r)
{
	float circlearea;
	
	circlearea = pi * r * r;
	
	return circlearea;

}
