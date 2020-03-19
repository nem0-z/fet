#include <iostream>
#include <string>
#include <vector>

using namespace std;

void readArray(const int* array,const int arrSize){
  for (int i = 0;i < arrSize; ++i) {
    std::cout << *(array+i) << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
  // int* p;
  // std::cout << p << std::endl;
  const int arrSize = 10;
  int arr[arrSize];
  *arr = 4;
  arr[1] = 7;
  arr[8] = 13;
  readArray(arr,arrSize);
  int* heapArray = new int[arrSize];
  for(int i = 0; i<arrSize; ++i){
    *(heapArray+i) = i;
  }
  readArray(heapArray,arrSize);
  delete [] heapArray;
  return 0;
}
