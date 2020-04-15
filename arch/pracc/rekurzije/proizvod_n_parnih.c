#include <stdio.h>
int proizvod(int n);
/* { */
/*   if(n==2) */
/*     return 2; */
/*   if(n%2==0) */
/*     return n*proizvod(n-1); */
/*   return proizvod(n-1); */
/* } */

int main()
{
  int  n = 5;
  printf("%d", proizvod(n));
}
