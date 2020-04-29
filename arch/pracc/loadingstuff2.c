#include <stdio.h>

double foo(double x);
/* { */
/*   return x*3; */
/* } */

int main(void)
{
  printf("%f",foo(4.5));
  return 0;
}
