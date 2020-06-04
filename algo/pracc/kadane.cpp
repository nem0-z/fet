#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iostream>

int kadane(int* array, int start, int end) {
  int maxSoFar = INT_MIN, maxEndingHere = 0;
  for (int i = start; i < end; ++i) {
    maxEndingHere += array[i];
    if (maxSoFar < maxEndingHere) maxSoFar = maxEndingHere;
    if (maxEndingHere < 0) maxEndingHere = 0;
  }
  return maxSoFar;
}

int main(void) {
  int v[] = {1, 7, 400, -7, 2, 5, -14, 200, 201};
  std::cout << kadane(v, 0, 8) << std::endl;
  return 0;
}


