#include <stdio.h>
/* int najmanji(int* niz, int velicina) { */
/*   if (velicina == 1) return niz[0]; */
/*   int min_os = najmanji(niz + 1, velicina - 1); */
/*   if (min_os < niz[0]) */
/*     return min_os; */
/*   else */
/*     return niz[0]; */
/* } */
int najmanji(int*,int);

int main() {
  int niz[] = {-5, -8, -12, 7, 4, 5, 3};
  printf("%d", najmanji(niz, 7));
  return 0;
}
