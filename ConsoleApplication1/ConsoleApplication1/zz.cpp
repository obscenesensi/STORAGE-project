#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a=0;

	printf(" Á¤¼ö¸¦ ÀÔ·ÂÇÏ¿© ÁÖ¼¼¿ä : ");
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
	system("pause");
	return 0;
	
}
