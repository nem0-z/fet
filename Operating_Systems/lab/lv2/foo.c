#include <stdio.h>

int sum(int[], int);

int main(int argc, char *argv[])
{
  int arr[] = {1, 2, 3, 4, 5};
  int s = sum(arr, 5);
  printf("%d\n", s);
  return 0;
}

/* int sum(int arr[], int size){ */
/*   int i, sum = 0; */
/*   for(i=0; i<size; ++i) */
/*     sum += arr[i]; */
/*   return sum; */
/* } */
