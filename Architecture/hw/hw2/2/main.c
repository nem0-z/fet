#include <stdio.h>
#include <stdlib.h>

void print_comb(int maxr);
/* { */
/*   for (int i = 0; i < maxr; ++i) */
/*     printf("%c", d[i]); */
/*  */
/* } */
  /* printf("\n"); */

void combinations_impls(char *chars, int maxr, int size, int r);
/* { */
/*   if (r == 0) */
/*   { */
/*     print_comb(maxr); */
/*     return; */
/*   } */
/*   for (int i = 0; i < size; ++i) */
/*   { */
/*     d[maxr - r] = chars[i]; */
/*     combinations_impls(chars, maxr, size, r - 1); */
/*   } */
/* } */

void combinations(char *chars, int size, int r);
// {
//   d = (char *)malloc(r);
//   combinations_impl(chars,r,size,r);
//   }

int main(void)
{
  char set[] = {'a','b','c'};
  combinations(set,3,1);
  return 0;
}
