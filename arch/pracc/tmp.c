#include <stdio.h>

float foo(double*,int);

int main(int argc, char *argv[])
{
  const int num = 7;
  double x = 5.59;
  printf("%f",foo(&x,num));
  return 0;
}
