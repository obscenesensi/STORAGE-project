
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

	printf("address of ip is : %p\n",ip,&ip);
	printf("adress of fp is : %p\n",fp,&fp);
	printf("address of cp is : %p\n",cp,&cp);

	return 0;


}
