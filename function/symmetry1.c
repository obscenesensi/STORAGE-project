#include <stdio.h>

#include "stdlib.h"

int main()

{

 

	int i = 0, j,n=0,sum=0,k=0;

	char a[100], e[100], temp[100];

 

	printf("이 프로그램은 대칭판별하는 프로그램 입니다. \n\n");

	printf("대칭을 판별할 문자열을 입력하시오. : ");

	scanf("%s", &a);

 

	while (a[i] != 0){

		i++;

	

	}

	

	for (j = i - 1; j >= 0; j--){

		

 

		

		if (a[n] == a[j])

			sum = 1;

		else

			sum = 0;

		n++;

	}

	if (sum == 1)

		printf("\n\n이 문자열은 대칭입니다.\n\n");

	else

		printf("\n\n이 문자열은 대칭이아닙니다.\n\n");

			

	

	return 0;

}
