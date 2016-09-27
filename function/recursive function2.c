#include "stdafx.h"
#include "stdlib.h"

int up(int i);

int main()
{
	
	int num = 0 ,n;
	n = 1;
	
	while (1)
	{
		
		printf("n : ");
		scanf_s("%d", &num);
		if (num == 0)
			break;
		n = up(num);
		printf("\n");
		
	}
	return 0;
}

int up(int i)
{
	if (i == 100)
	{
		printf("%d", i);
		return 1;
	}
	else
		printf("%d ",i);
		return i * up(i + 1);

}
