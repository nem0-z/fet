#include <stdio.h>

 
int factorial(int n) {
   //base case
   if(n == 0) {
      return 1;
   } else {
      return n * factorial(n-1);
   }
}


int main(void)
{
  int n = 5;
  printf("%d", factorial(n));
  return 0;
}
