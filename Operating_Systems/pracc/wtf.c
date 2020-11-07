#include <stdio.h>

int wtf(int*, int, int);

int main(int argc, char *argv[])
{
  int arr[] = {1,2,3,4,5,6,7,9,11};
  int size = sizeof(arr)/sizeof(int);
  int res = wtf(arr, size, 2);
  printf("%d", res);
  return 0;
}

