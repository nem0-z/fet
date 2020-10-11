#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>

int kadane(int* array, int start, int end) {
  int maxSoFar = INT_MIN, maxEndingHere = 0;
  for (int i = start; i < end; ++i) {
    maxEndingHere += array[i];
    if (maxSoFar < maxEndingHere) maxSoFar = maxEndingHere;
    if (maxEndingHere < 0) maxEndingHere = 0;
  }
  return maxSoFar;
}

int maxSubBF(int* array, int size) {
  int maxSoFar = array[0];
  for (int i = 0; i < size; ++i) {
    int sum = 0;
    for (int j = i; j < size; ++j) {
      sum += array[j];
      if (sum > maxSoFar) maxSoFar = sum;
    }
  }
  return maxSoFar;
}

int main(void) {
  int v[] = {1, 7, 400, -7, 2, 5, -1400, 200, 492};
  std::cout << kadane(v, 0, sizeof(v)/sizeof(int)) << std::endl;
  std::cout << maxSubBF(v,sizeof(v)/sizeof(int)) << std::endl;
  return 0;
}

