#include <iostream>

using namespace std;

template <typename T, typename U>
void foo(T a, U b) {
  std::cout << "Both templated" << std::endl;
}

template <typename T, typename U = char>
void foo(T a, char b) {
  std::cout << "2nd char" << std::endl;
}

template <>
void foo(int a, char b) {
  std::cout << "0 templates" << std::endl;
}

template <typename T = char, typename U = float>
struct A {
  void foo() { std::cout << 1 << std::endl; }

  T a{};
  U b{};
};

template <>
struct A<char, float> {
  void foo() { std::cout << 2 << std::endl; }

  char a{};
  float b{};
};

template <typename T>
struct A<short, T> {
  void foo() { 
    std::cout << 3 << std::endl; }
  short a{};
  T b{};
};

template <typename T>
struct A<T, short> {
  void foo() { std::cout << 4 << std::endl; }
  T a{};
  short b{};
};

// template<typename U>
// struct A<U,float>{
//   void foo(){
//     std::cout << sizeof(a) << std::endl;
//     std::cout << sizeof(b) << std::endl;
//   }
//   short a{};
//   U b{};
// };


using test = A<short,float>;

int main(int argc, char *argv[]) {
  A<short,float> x;
  x.foo();
  // A<char,float> y;
  // y.foo();
  // A<> y1;
  // y1.foo();
  // foo(4.5,4.5);
  // foo('a','c');
  // A<int,double> x;
  // x.foo();
  // A<char,float> y;
  // y.foo();
  // A<char,char> y;
  // A<float,short> x;
  // x.foo();
  return 0;
}
