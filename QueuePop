#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int queue[SIZE];
int top = 0;

void queue_push();
void queue_pop();
void queue_print();

void main() {
	int input;
	while (1){
		printf("\n\n1.Push (max 5) \n2.pop\n");
		scanf("%d", &input);
		switch (input) {
		case 1:queue_push(); break;
		case 2:queue_pop(); break;
		} 
		queue_print();
	}
}

void queue_push() {
	int n, i;
	if (top < SIZE){
		top++;
		for (i = top - 1; i > 0; i--) {
			queue[i] = queue[i - 1];
		}
		printf("\ninput : ");
		scanf("%d", &n);
		queue[0] = n;
	}
	else{
		printf("큐 오버 플로우\n");
	}

}


void queue_pop() {
	if (top == 0) {
		printf("Empty\n\n");
	}
	else
	{
		top--;
		printf("pop : %d\n\n", queue[top]);
	}
}


void queue_print() {
	int i;
	for (i = 0; i < top; i++)
		printf("%d ", queue[i]);
}
