#include <stdio.h>
int djeljitelj(int n1, int n2);
/* { */
/*  if(n2!=0) */
/*    return djeljitelj(n2, n1%n2); */
/*  return n1; */
/* } */

int main() {
  int n1 = 100, n2 = 50, n3;
  printf("%d", djeljitelj(n1, n2));
  return 0;
}
