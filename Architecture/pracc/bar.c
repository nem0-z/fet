#include <stdio.h>
float foo(double*,int);

int main(void)
{
  const int num = 7;
  double x = 5.59;
  float f = foo(&x,num);
  printf("%f",f);
  return 0;
}
