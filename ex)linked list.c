#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
 
typedef struct tagNode
{
       int data;
       struct tagNode *next;
} NODE;
 
NODE *head, *tail, *working;
 
// 리스트초기화
void InitList();
// 데이타하나추가
void Insert(int n);
// 주어진데이타를삭제
void Delete(int n);
// 데이타를모두삭제
void RemoveAll();
// 현재리스트의값들을모두더해서보여준다.
void AddAll();
// 주어진데이타와같은노드개수를카운트
int Count(int n);
// 현재리스트의모든내용을보여준다.
void DisplayList();
 
int main()
{
       // 리스트초기화
       InitList();
 
       Insert(10);
       Insert(20);
       Insert(30);
       Insert(40);
       Insert(50);
       Insert(10);
      
       // Display 함수를이용하여연결리스트의데이터들을출력한다.
       DisplayList();
 
       // 전체합출력
       AddAll();
 
       // 데이타값이10 인노드의개수를카운트
       Count(10);
 
       // 노드삭제
       Delete(10);
       DisplayList();
       Delete(50);
       DisplayList();
       Delete(20);
       DisplayList();
 
       RemoveAll();
 
       return 0;
}
 
void InitList()
{
       // 리스트초기화
       head = NULL;
       tail = NULL;
       working = NULL;
}
 
void Insert(int n)
{
       // 새로노드를하나만들어서값을대입
       working = (NODE *)malloc(sizeof(NODE));
       printf("Adding %d\n", n);
       working->data = n;
 
       // 이것이꼬리임
       working->next = NULL;
 
       // 만약머리가비었으면이것이머리임
       if ( head == NULL )
       {
             head = working;
             tail = working;
             return;
       }
 
       // 머리가아니라면마지막에노드를삽입하고
       tail->next = working;
       // 이것이꼬리임
       tail = working;
}
 
void Delete(int n)
{
       // 아무런데이타도없으면
       if ( head == NULL )
             // 지울일도없다.
             return;
 
       // 일단머리를가져온다.
       working = head;
       NODE* node;
 
       // 같은값을찾아서삭제
       while ( working )
       {
             if ( working->data == n )
             {
                    printf("Deleting %d...\n", working->data);
                    if ( working == head )
                    {
                           head = working->next;
                           delete working;
                    }
                    else
                    {
                           node->next = working->next;
                           delete working;
                    }
                    Delete(n);   // 다른값이있으면또지움
                    break;
             }
             node = working;
             working = working->next;
       }
}
 
void RemoveAll()
{
       // 머리를가져와서
       working = head;
 
       // 끝까지지움
       while ( working )
       {
             NODE *node = working;
             // 다음노드준비
             working = working->next;
             // 노드삭제
             printf("Deleting %d\n", node->data);
             free(node);
             node = NULL;
       }
 
       InitList();
       printf("All elements deleted.\n");
}
 
void AddAll()
{
       int sum = 0;
 
       working = head;
 
       while ( working )
       {
             sum += working->data;
             working = working->next;
       }
 
       printf("Sum of all : %d\n", sum);
}
 
int Count(int n)
{
       int count = 0;
 
       working = head;
 
       while ( working )
       {
             if ( working->data == n )
                    ++count;
             working = working->next;
       }
 
       printf("Count of %d : %d\n", n, count);
 
       return count;
}
 
void DisplayList()
{
       printf("Display all element : ");
 
       printf("head = ");
       working = head;
 
       while ( working )
       {
             printf("%d -> ", working->data);
             working = working->next;
       }
       printf("= tail\n");
}
[출처] 단순연결리스트(Single Linked List) 예제|작성자 xtElite
