#include <stdio.h>

int sum(int arr[], int size){
  int i, total = 0;
  for (i = 0; i < size; ++i){
    total += arr[i];
  }
  return total;
}
