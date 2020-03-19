#include <algorithm>
#include <iostream>
#include <list>
#include <string>
namespace sinisa {
int a = 5;
}

int a = 20;

int main(int argc, char *argv[]) {
  std::list<int> lista{5, 7, 2, 7};
  // std::sort(std::begin(lista), std::end(lista),
  //           [](int a, int b) { return a > b; });
  auto x = [](int a, int b) { return a > b; };
  const int& z = 10;
  std::cout << z << std::endl;
  // const int z = 5;
  // typedef decltype(z) mojInt;
  // mojInt sinisa = 20;
  // std::string b = "zlatan";
  // std::cout << b+std::string(4,'c')<< std::endl;
  return 0;
}
