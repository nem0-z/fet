#include <stdio.h>

int fakt(int n);
/* { */
/*   if(n<=1) return 1; */
/*   else return n*fakt(n-1); */
/* } */

int main(void)
{
  int n = 5;
  printf("%d",fakt(n));
  return 0;
}
