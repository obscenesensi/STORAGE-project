#include <stdio.h>
#define SIZE 5
int top=0;
int s[SIZE];


void push(int d)
{
	if(top >= SIZE) {printf("overflow\n");
	}
	
	else {
		s[top] = d;
		top++;
	}
	
}

void pop()
{
	if(top == 0) {printf("empty\n"); }		
	else {
		printf("pop된 값은 ? %d\n", s[top-1]);
		s[top-1]=0;
		top--;
		
	}
}


void dis()
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%d\t",s[i]);
	}
	printf("\n\n");
}


void main()
{
	int menu;
	int data;
	


	while(menu <= 3)
	{	printf("메뉴 선택 1. 푸시    2. 팝    3. 종료\n");
		scanf("%d", &menu);
		
		switch (menu)
		{
		case 1:
			printf("스택에 푸시할 값을 입력하세요");
			scanf("%d",&data);
			push(data);
			break;
		case 2:
			pop();
			break;
		case 3:
			menu = 5;
			break;
		default :
			printf("잘못된 메뉴 입력");
			break;

		}
		dis();
	}
	

}
