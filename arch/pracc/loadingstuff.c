#include <stdio.h>

void foo(double* x);
/* { */
/*   *x = *x * 2; */
/* } */
//*double = *double * 2;

int main(void)
{
  double x = 378.123; 
  foo(&x);
  printf("%f",x);
  return 0;
}
