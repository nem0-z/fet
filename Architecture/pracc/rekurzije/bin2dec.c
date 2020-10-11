
#include <stdio.h>
/* int konverzija2(int n) */
/* { */
/*  if(n==0) */
/*    return 0; */
/*  return n%10 + 2*konverzija2(n/10); */
/* } */
int konverzija2(int);

int main()
{
  int n=1010;
  printf("%d", konverzija2(n));
  return 0;
}
