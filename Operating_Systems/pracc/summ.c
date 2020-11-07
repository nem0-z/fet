#include <stdio.h>

#ifndef SIZE
#define SIZE(a) sizeof(a) / sizeof(int)
#endif /* ifndef SIZE(a) */

int sum(int[], int);

/* int sum(int arr[], int size){ */
/*   int i, total = 0; */
/*   for(i = 0; i < size; ++i) */
/*     total += arr[i]; */
/*   return total; */
/* } */

int main(void) {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int s = sum(arr, SIZE(arr));
  printf("(main) Sum is equal to: %d\n", s);
  return 0;
}
