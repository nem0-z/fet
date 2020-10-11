#include <stdio.h>

int sum(int a, int b);
/* { */
/*   if(b==0) return a; */
/*   else return sum(a+1,b-1); */
/* } */

int main(void)
{
  int a = 296;
  int b = 273;
  printf("%d",sum(a,b));
  return 0;
}
