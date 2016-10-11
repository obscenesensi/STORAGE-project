#include <stdio.h>
#include <stdlib.h>


const int MAXN = 50;
int queue [50];

int main()
{
   int n, front, rear;
   scanf("%d", &n);
   int i;
   
   for(i = 0; i < n; i++)
   {
   queue[i] = i+1;
   front = 0;
   rear = n;
   }
   
   while(front < rear)
   {
   printf("%d",queue[front++]);
   printf("  front is %d",front);
   queue[rear++] = queue[front++];
   printf(" rear is  %d\n", rear);
   }
  system("PAUSE");
  return 0;
}
