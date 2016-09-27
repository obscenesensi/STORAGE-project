#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define N 10000 


int main(void)
{

	char c[N];
	char temp;
	int leng = 0;

	printf("문자열을 입력하세요 : ");
	gets(c);


	while (c[leng] != '\0') // 길이 알아냄
		leng++;

	//반복문은 문자열의 역순을 만들어내는 역할
	//leng/2를 하는 이유는 역순을 만들기위해 반복을 절반만 해야하기 때문
	for (int i = 0; i < leng / 2; i++) {
		temp = c[i]; // temp 0
		//-1을 하는 이유는 문자열의 끝에 \0가 있기때문
		//그 \0를 무시하고 나머지 문자열들만 자리를 바꾸기 위함임
		c[i] = c[leng - i - 1]; 
		c[leng - i - 1] = temp; 
	}
	
	printf("변경된 문자 : %s\n", c);

}
