#include <stdio.h>

int mult(int a, int b) {
  if (a == 1 && b == 1)
    return 1;
  else if (a == 1)
    return b;
  else if (b == 1)
    return a;
  else
    return a + mult(a, b - 1);
}

int divide(int a, int b) {
  static int x = 0;
  if (a == 0 || b > a)
    return 0;
  else if (a == b)
    return 1;
  else if (b == 1)
    return a;
  else
    x = 1 + divide(a - b, b);
  return x;
}

int main(void) {
  int c;
  c = mult(14, 5);
  printf("%d", c);
  int d;
  d = divide(24, 5);
  printf("%d", d);
  return 0;
}
