#include <stdio.h>

/* static double d = 10.25; */

/* double foo(int a, double b) { */
/*   if (b < a) */
/*     return a + b - d; */
/*   else if (b == a) */
/*     return a + b; */
/*   return a + b + d; */
/* } */

double foo(int,double);

int main(void)
{
  double result = foo(5,7.5);
  printf("%f\n", result);
  return 0;
}
