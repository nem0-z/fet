#include <stdio.h>

float foo(double*,float*);

int main(void)
{
  double y = 10.5;
  float z = 11.5;
  printf("%f",foo(&y,&z));
  return 0;
}
