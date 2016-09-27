#include "stdafx.h"
#include "stdlib.h"

long power(int a, int b);

int main()
{
	int num1, num2, n;
	num1, num2 = 0;
	printf("두 수를 입력하시오 : ");
	scanf("%d %d", &num1, &num2);
	n = power(num1, num2);
	printf("\n%d의 %d승 : %d", num1, num2, n);
}

long power(int a, int b)
{

	if (b == 1)
		return a;
	else
    	return a * power(a, b - 1);


}
