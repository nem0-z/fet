#include <iostream>

int findmin(int *array, int size)
{
  const int mid = size / 2;
  if (array[0] < array[size - 1])
    return array[0];
  else if (array[mid] < array[mid - 1])
    return array[mid];
  else if (array[mid + 1] < array[mid])
    return array[mid + 1];

  if (array[0] < array[mid])
    return findmin(array + size - mid, mid);
  else
    return findmin(array, size - mid);
}

int main(void)
{
  // int arr[] = {1, 2, 3, 4, -1, 0};
  // int arr[] = {2, 3, 4, -1, 0, 1};
  // int arr[] = {3, 4, -1, 0, 1, 2};
  // int arr[] = {4, -1, 0, 1, 2, 3};
  int arr[] = {-1, 0, 1, 2, 3, 4};
  std::cout << "Smallest element: " << findmin(arr, sizeof(arr) / sizeof(int)) << std::endl;
  return 0;
}
