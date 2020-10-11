#include <stdio.h>


void foo(float* p);
double bar(int,double);

int main(void) {
  /* float p = 10.2; */
  /* foo(&p); */
  /* printf("p = %f\n", p); */
  double result = bar(5,2.41);
  printf("%lf \n",result);
  return 0;
}
