#include <iostream>

int sum(const int* array, int n) {
  return (n == 1) ? *array : *array + sum(array + 1, n - 1);
}

int main(void) {
  const int arr[] = {100, 5, 140, -4};
  std::cout << sum(arr, sizeof(arr) / sizeof(int)) << std::endl;
  return 0;
}
