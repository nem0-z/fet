#include <stdio.h>

double baz(float, double*, float, int);

int main(void) {
  double x = 10.2;
  printf("%f", baz(4.5, &x, 7.0, 6));
  return 0;
}
