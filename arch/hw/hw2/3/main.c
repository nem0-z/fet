#include <stdio.h>

float q_rsqrt(float);

  /* long i; */
/*   float Q_rsqrt(float number) { */
/*   float x2, y; */
/*   const float threehalfs = 1.5F; */
/*  */
/*   x2 = number * 0.5F; */
/*   y = number; */
/*  */
/*   float* c = &y; */
/*  */
/*   i = *(long *)c; */
/*   printf("%ld\n",i); */
/*   i = 0x5f3759df - (i >> 1); */
/*  */
/*   y = *(float *)&i; */
/*   y = y * (threehalfs - (x2 * y * y)); */
/*  */
/*   return y; */
/* } */

int main() {
  printf("%f\n", q_rsqrt(100));

  return 0;
}

