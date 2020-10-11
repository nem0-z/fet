#include <stdio.h>

double baz(float f1, double* p1, float f2, int n);

int main(void)
{
  double x = 10.2;
  printf("%f",baz(4.5,&x,5.5,7));
  return 0;
}
