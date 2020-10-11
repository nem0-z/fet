#include <stdio.h>

int sumNumber(int num);

/*   int sum=0;  */
/*   if(num == 0) */
/*     return 0; */
/*   else{ */
/*     sum = num + sumNumber(num-1); */
/*   } */
/*   return sum; */
/*  */
/* } */

int main(void)
{
  printf("%d", sumNumber(7));
  return 0;
}
