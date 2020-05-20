#include <iostream>

int pronadjiNajmanji(int* array, int size) {
  if (size == 1) return *array;
  const int mid = size / 2;
  const int lMin = pronadjiNajmanji(array, mid);
  const int rMin = pronadjiNajmanji(array + mid, size - mid);
  return (lMin < rMin) ? lMin : rMin;
}

int main(void) {
  int arr[] = {-14,-1, 6, -2, 3, 0, 4, -11};
  std::cout << "Najmanji element: "
            << pronadjiNajmanji(arr, sizeof(arr) / sizeof(int)) << std::endl;
}
