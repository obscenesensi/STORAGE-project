#include <stdio.h>
#include "stdlib.h""
int main()
{
 int m, n, i=0, k;
 printf("m~n까지를 한 줄에 k개씩 출력프로그램입니다.\n");
 printf("m 과 n 을 입력하세요. : ");
 scanf("%d %d", &m, &n);
 printf("k를 입력하세요. : ");
 scanf("%d", &k);
 if (m > n)
 {
  for (i = n; i <= m; i++)
  {
   printf("\t%d", i);
   if ((i - n + 1) % k == 0){
    printf("\n");
  }
  }
 }
 if (m < n)
 {
  for (i = m; i <= n; i++)
  {
   printf("\t%d", i);
   if ((i - m + 1) % k == 0){
    printf("\n");
   }
  }
 }


}
