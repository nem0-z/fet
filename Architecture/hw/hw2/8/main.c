#include <inttypes.h>
#include <stdio.h>

void roundtotick(double*, uint32_t);
double gettick(double);
double calcamount(double, int);

/* void roundtotick(double* p, uint32_t precision) { */
/*   uint32_t r = *p * precision; */
/*   *p = (double)r / precision; */
/* } */

/* double gettick(double num) { */
/*   if (num == 0) return 0.; */
/*   if (num < 10) return 0.001; */
/*   if (num < 100) return 0.01; */
/*   if (num < 1000) return 0.1; */
/*   return 1.; */
/* } */

/* double calcamount(double price, int quantity) { */
/*   roundtotick(&price, 1 / gettick(price)); */
/*   return price * quantity; */
/* } */

int main(void) {
  for (double i = 3.451748; i < 4000.; i *= 10) {
    printf("Amount(%f, 307) = %f\n", i, calcamount(i, 307));
  }
  return 0;
}

