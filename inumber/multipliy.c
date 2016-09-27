#include <stdio.h>
int main()
{
	int inumber = 25;
	float fnumber = 34.5f;
	char ch = 'g';

	int *ip;
	float *fp;
	char *cp;

	ip = &inumber;
	fp = &fnumber;
	cp = &ch;
	
	printf("Please enter a integer : ");
	scanf("%d", &inumber);
	printf("Multiplied integer is : %d\n\n", *ip * 2);

	return 0;


}
