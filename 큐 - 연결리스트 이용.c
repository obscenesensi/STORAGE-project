//큐 - 연결리스트 이용
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node //노드 정의
{
    int data;
    struct Node *next;
}Node;

#define NEXT(index,QSIZE)   ((index+1)%QSIZE)  //원형 큐에서 인덱스를 변경하는 매크로 함수

typedef struct Queue //Queue 구조체 정의
{
    Node *front; //맨 앞(꺼낼 위치)
    Node *rear; //맨 뒤(보관할 위치)
    int count;//보관 개수
}Queue;

void InitQueue(Queue *queue);//큐 초기화
int IsEmpty(Queue *queue); //큐가 비었는지 확인
void Enqueue(Queue *queue, int data); //큐에 보관
int Dequeue(Queue *queue); //큐에서 꺼냄

int main(void)
{
    int i;
    Queue queue;

    InitQueue(&queue);//큐 초기화
    for (i = 1; i <= 5; i++)//1~5까지 큐에 보관
    {
        Enqueue(&queue, i);
    }
    while (!IsEmpty(&queue))//큐가 비어있지 않다면 반복
    {
        printf("%d ", Dequeue(&queue));//큐에서 꺼내온 값 출력
    }
    printf("\n");
    return 0;
}

void InitQueue(Queue *queue)
{
    queue->front = queue->rear = NULL; //front와 rear를 NULL로 설정
    queue->count = 0;//보관 개수를 0으로 설정
}

int IsEmpty(Queue *queue)
{
    return queue->count == 0;    //보관 개수가 0이면 빈 상태
}

void Enqueue(Queue *queue, int data)
{
    Node *now = (Node *)malloc(sizeof(Node)); //노드 생성
    now->data = data;//데이터 설정
    now->next = NULL;

    if (IsEmpty(queue))//큐가 비어있을 때
    {
        queue->front = now;//맨 앞을 now로 설정       
    }
    else//비어있지 않을 때
    {
        queue->rear->next = now;//맨 뒤의 다음을 now로 설정
    }
    queue->rear = now;//맨 뒤를 now로 설정   
    queue->count++;//보관 개수를 1 증가
}

int Dequeue(Queue *queue)
{
    int re = 0;
    Node *now;
    if (IsEmpty(queue))//큐가 비었을 때
    {
        return re;
    }
    now = queue->front;//맨 앞의 노드를 now에 기억
    re = now->data;//반환할 값은 now의 data로 설정
    queue->front = now->next;//맨 앞은 now의 다음 노드로 설정
    free(now);//now 소멸
    queue->count--;//보관 개수를 1 감소
    return re;
}