#include <stdio.h>

int main()
{
	int a=0;

	printf(" 정수를 입력하여 주세요 : ");
	scanf("%d", &a);

	if (a >0)
	{
		printf(" %d is a negative.\n",a);
	}
	else if(a<0)
	{
		printf(" %d is a positive.\n",a);
	}
	else
	{
		printf("0 is zero\n");
	}

	return 0;
}