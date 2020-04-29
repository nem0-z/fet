#include <stdio.h>

void foo(float x,double* pd,double d)
{
  // $f12 -> x, $a1 -> *pd, $a2$a3 -> d
  int y = 4;
  y = y + 2.f * x - d;
  *pd = y;
  //rez je 95.000
}

int main(void)
{
  double x = 932.99;
  foo(46.8,&x,2.5);
  printf("%f",x);
  return 0;
}
