#include <stdio.h>
#include <inttypes.h>

int16_t exchange(int16_t* a, int16_t b);

int main(int argc, char *argv[])
{
  int16_t a = 10;
  int16_t b = 4;
  /* exchange(&a,b); */
  printf("A before: %d\n",exchange(&a,b));
  printf("A sada: %d\n",a);
  return 0;
}

