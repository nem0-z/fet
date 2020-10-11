#include <stdio.h>
/* int sum (int* array,int n){ */
/*   else  */
/*   return array[n-1]+sum(array,n-1); */
/* } */

int sum(int*,int);


int main(void)
{
  int array[] = {1, 2 , 3, 4,5 };
  printf("%d", sum(array, 5));
  return 0;
}
