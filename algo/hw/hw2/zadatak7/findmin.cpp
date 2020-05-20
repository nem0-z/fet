#include <iostream>

int findmin(int* array,int size) {
  const int mid = size/2;
  if(array[mid-1] > array[mid]) return array[mid];
  else if (array[mid+1] < array[mid]) return array[mid+1];

}

int main(void) {
  int arr[] = {1,2,3,4,-1,0};
  std::cout << "Smallest element: " << findmin(arr,sizeof(arr)/sizeof(int)) << std::endl;
  return 0;
}
