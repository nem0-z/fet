#include <stdio.h>
int findAndReturnMax(int *, int, int);
int main(int agrc, char *argv[]) {
  int arr[5] = {17, 21, 44, 2, 60};
  int max = arr[0];
  if (findAndReturnMax(arr, 5, max) == 0) {
    printf("MAX: %d \n", max);
  }
}
int findAndReturnMax(int *array1, int len, int max) {
  int i;
  if (!array1 || (len <= 0)) {
    return -1;
  }
  max = array1[0];
  for (i = 0; i < len; i++) {
    if (max < array1[i]) {
      max = array1[i];
    }
  }
  return 0;
}
