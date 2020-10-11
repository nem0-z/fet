#include <stdio.h>
double foo(float a, int b);// { */
/*   if (a < b) return (double)a + b; */
/*   return (double)a - b; */
/* } */

int main(int argc, char *argv[]) {
  double s = foo(5.5, 16777220);
  double z = 5.5 + 16777220;
  printf("foo: %f\n", s);
  printf("double: %f\n", z);
  return 0;
}
