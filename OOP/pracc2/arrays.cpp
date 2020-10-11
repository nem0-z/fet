#include <iostream>
#include <vector>

void bar(const int& x){
  std::cout << "Sinisa" << std::endl;
}

void bar(int&& x){
  std::cout << "Boris" << std::endl;
}

int main(void) {
  // const int size = 10;
  // int a[size];
  // for (int i = 0; i < size; ++i) {
  //   a[i] = 4;
  //   std::cout << a[i] << " ";
  // }
  // std::cout << '\n';
  // a[0] = 10;
  // std::cout << *(a + 3) << std::endl;
  // std::cout << *a << std::endl;
  // // *(a+size) = 20; //watch out, we are dereferencing last+1 = undefined
  // std::vector<int> v{a, a + size};
  // for (const auto& x : v) std::cout << x << " ";
  // std::cout << std::endl;
  // std::vector<int> v1(v.begin(), v.end());
  // for (const auto& x : v1) std::cout << x << " ";
  int* heapPtr = new int;
  *heapPtr = 20;
  std::cout << heapPtr << std::endl;
  std::cout << &heapPtr << std::endl;
  bar(*heapPtr);
  bar(3);
delete heapPtr;
  

  return 0;
}
