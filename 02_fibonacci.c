/*
Name    :Babu Malagaveli
Date    :20.05.2023
Desc    : Code to find even/odd
Input   : 10
Output  : 0 1 1 2 3 5 8
*/

#include<stdio.h>
int main() 
{
  int n, first = 0, second = 1, next = 0, count = 1;                    //declaration of variables
  printf("Enter n ");
  scanf("%d", & n);                                                     //reading variables
  if (n == 0)
  {
      printf("%d ", first); 
  }
  if (n == 1)
  {
      printf("%d %d %d", first, second,count);
  }
  if (n < 0)
  {
      printf("Invalid input");
  }
  while (count < n)                                                     //while condtion till count < n
  {
    printf("%d ", next);                                                
    first = second;
    second = next;
    next = first + second;
    count += 1;
  }
  
  return 0;

}