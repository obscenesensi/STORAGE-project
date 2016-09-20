  #include<stdio.h> 
  void  
  swap(int *a, int *b)  
  { 
      int tmp; 
      tmp = *a;  
      *a = *b;  
      *b = tmp; 
} 
   
  void quick_sort(int *a,  int left, int right) 
  { 
      if (left >= right) 
          return; 
   
      int i = left; 
      int j = right + 1; 
      int key = a[left]; 
   
      while (1)  
      {    
          do{  
              i++; 
          } while (i <= right && a[i] <= key); 
   
          do{  
              j--; 
          } while (a[j] > key); 
   
          if (i > j) 
              break; 
   
          swap(&a[i], &a[j]); 
      }    
   
      swap(&a[left], &a[j]); 
   
      quick_sort(a, left, j - 1); 
      quick_sort(a, j + 1, right); 
  } 
       
  int  
  main() 
  {    
      int i; 
      int a[] = {1, 9, 3, 2, 8, 7}; 
   
      quick_sort(a, 0, 5); 
       
      for(i = 0; i < 6; i++) 
          printf("%d\t", a[i]); 
      printf("\n"); 
       
      return 0; 
  }    
