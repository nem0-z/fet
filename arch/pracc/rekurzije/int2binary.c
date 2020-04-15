// napisati rekurzivnu funkciju koja vrsi konverziju iz decimalnog broja u
// binarni
#include <stdio.h>
/* int int2bin(int n) { */
/*   static int x = 0; */
/*   if (n == 0) */
/*     return 0; */
/*   else { */
/*     x = n % 2 + 10 * int2bin(n / 2); */
/*   } */
/*   return x; */
/* } */

int int2bin(int);

int main(void) {
  int n = 17;
  printf("%d", int2bin(n));
  return 0;
}
