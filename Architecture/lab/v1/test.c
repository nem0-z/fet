#include <assert.h>
#include <stdio.h>

int max(const int* v, int size) {
  assert(v != NULL);
  assert(size != 0);
  int result = v[0];
  for (int i = 0; i < size; ++i) {
    if (v[i] > result) result = v[i];
  }
  return result;
}

int main(int argc, char* argv[]) {
  int input, size = 7;
  int array[30] = {1,7,2,11,3,9,8};
  printf("Max element: %d\n", max(array, size));
  return 0;
}

