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

	printf("size of of inumber is %d\n ", sizeof(inumber));
	printf("size of fnumber is %d\n", sizeof(fnumber));
	printf("size of ch is : %d \n", sizeof(ch));
	printf("size of of ip is %d\n ", sizeof(ip));
	printf("size of fp is %d\n", sizeof(fp));
	printf("size of cp is : %d \n", sizeof(cp));



	return 0;


}
