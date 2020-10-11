#include "vjezbamC2.h"
void printArr(const int* arr, long long arrSize){
  for (int i = 0; i < arrSize; ++i) {
      printf("%d\n", arr[i]);
  }
  printf("\n");
}
static void scanArr(int* arr, long long arrSize){
  for (int i = 0; i < arrSize; ++i) {
    scanf("%d",&arr[i]);
  }
  printf("\n");
}
