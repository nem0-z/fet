#include <limits.h>
#include <algorithm>
#include <iostream>
#include <vector>

int max(int a, int b, int c) {
  if (a > b && a > c)
    return a;
  else if (b > a && b > c)
    return b;
  else
    return c;
}

int maxSubarray(int* array, int start, int mid, int end) {

  int sum = 0;
  int lSum = INT_MIN;
  int rSum = INT_MIN;
  for (int i = mid; i > start; --i) {
    sum += array[i];
    if (sum > lSum) lSum = sum;
  }

  sum = 0;
  for (int i = mid + 1; i < end; ++i) {
    sum += array[i];
    if (sum > rSum) rSum = sum;
  }
  return max(rSum+lSum,rSum,lSum);
}

int maxSubarray(int* array, int start, int end) {
  if (start == end) return array[start];
  int mid = (end + start) / 2;
  int lSum = INT_MIN;
  int rSum = INT_MIN;
  int mSum = INT_MIN;
  lSum = maxSubarray(array, start, mid);
  rSum = maxSubarray(array, mid + 1, end);
  mSum = maxSubarray(array, start, mid, end);
  return max(lSum, rSum, mSum);
}

int main(void) {
  int v[] = {1, 7, -4, 7, 2, 5, -14, -2, 2};
  std::cout << maxSubarray(v, 0, 8) << std::endl;
  return 0;
}
