//대문자를 소문자로 소문자를 대문자로 바꾸는 프로그램.

#include <stdio.h>

#include "stdlib.h"

int main()

{

	

	char n;

	while(1){

		

		printf("\n\n대문자를 소문자로 소문자를 대문자로 바꿔주는 프로그램입니다.\n\n");

		printf("문자를 입력하시오.  : ");

		fflush(stdin);

		scanf("%c",&n);

 

	if(n>='A' && n<= 'Z')

	{

		printf("\n\n대문자를 입력하셧습니다.\n");

		printf("\n소문자는 %c 입니다.\n\n",n+'a'-'A');

		system("pause");

		system("cls");

	}

	else if(n<='z' && n>= 'a')

	{

		printf("\n\n소문자를 입력하셨습니다. \n");

		printf("\n대문자는 %c입니다. \n\n\n",n+'A'-'a');

		system("pause");

		system("cls");

	}

	else

	{

		printf("\n\n잘못입력했습니다. 문자를 입력하십시오.\n\n");

		printf("\n\n");

		system("pause");

		system("cls");

	}

	

	}

	return 0;

	}
