#include <iostream>
#include <string>

void foo(const std::string&){
  std::cout << "foo(const std::string&)" << std::endl;
}

void foo(std::string&&){
  std::cout << "foo(std::string&&)" << std::endl;
}

// void bar(const std::string& s){
//   foo(s);
// }
//
// void bar(std::string&& s){
//   foo(std::move(s));
// }
//

template<typename T>
void bar(T&& s){
  foo(std::forward<T>(s));
}
    
int main(void)
{
  std::string test{"test"};
  bar(test);
  bar("test2");
  return 0;
}
