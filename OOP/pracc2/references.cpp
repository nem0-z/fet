#include <iostream>
#include <vector>
int a = 40;

int main(int argc, char* argv[]) {
  // int a = 10;
  // int* ptr = &::a;
  // std::cout << &a << std::endl;
  // std::cout << &ptr << std::endl;
  // *ptr = 20;
  // std::cout << &ptr << std::endl;
  // void* ptr1 = nullptr;
  // std::cout << &ptr1 << std::endl;
  int* array = new int[10];
  std::cout << &array << std::endl;
  int x = 5;
  std::cout << &x << std::endl;
  delete[] array;
  std::cout << &array << std::endl;
  std::vector<int> v{3, 2, 1, 6, 2, 1};
  std::vector<int>& vecRef = v;
  std::cout << vecRef.size() << std::endl;
  std::cout << &vecRef << std::endl;
  const int& rvalueRef = 5;
  int&& rvalueRef1 = 10;
  return 0;
}
