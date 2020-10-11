// primjer iz knjige, probat cemo ovo u asembleru
#include <stdio.h>

/* int foo(int a, int b){ */
/*   return (a|2) + (b & 0xfffffffe) + (a|2); //get this part done in assembly */
/* } */

int main() {
  unsigned int i;
  i = 0;
  goto next1;
  i = i + 1;

next1:
  i = i + 100;

next2:
  i = i + 10;
  i = i + 15;
  int x = foo(20,30);
  printf("i je %d\n", i);

  return 0;
}

