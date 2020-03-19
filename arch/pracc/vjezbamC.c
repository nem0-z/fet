#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void printArr(const int* arr, const int arrSize)
{
  for (int i = 0; i < arrSize; ++i) {
    printf("%d\n",arr[i]);
  }
}

int main() {
  int arrSize;
  printf("Array size: ");
  scanf("%d", &arrSize);
  assert(arrSize != 0 && "Nope!");
  int arr[arrSize];
  printf("Enter array elements: \n");
  for (int i = 0; i < arrSize; ++i) {
    scanf("%d", &arr[i]);
  }
  printf("Your array with %d elements: \n", arrSize);
  printArr(arr,arrSize);
  return 0;
}
