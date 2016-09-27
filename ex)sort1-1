#include <stdio.h> 
  
  void 
  insert_sort(int *a, const unsigned int n) 
  { 
      int i, j; 
      int tmp; 
   
      for (i=1; i<n; i++) { 
          tmp = a[i]; 
          for (j=i-1; j>=0 && a[j]>tmp; j--) { 
              a[j+1] = a[j]; 
          } 
          a[j+1] = tmp; 
      } 
  } 
   
  int 
  main(int argc, char *argv[]) 
  { 
      int i; 
      unsigned int len; 
      int ar[] = {2,3,1,4,5,8,7,6,9}; 
   
      len = sizeof(ar)/sizeof(int); 
      insert_sort(ar, len); 
   
      for (i=0; i<len; i++) { 
          printf("%d ", ar[i]); 
      } 
      printf("\n"); 
       
    return 0; 
  } 
