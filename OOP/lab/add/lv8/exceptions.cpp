#include <iostream>
#include <stdexcept>

void test() { throw std::invalid_argument("Test"); }

void bar() {
  try {
    test();
  } catch (const std::out_of_range& e) {
    std::cout << "catch std::out_of_range: " << e.what() << std::endl;
  }
}

void foo() { bar(); }

int main(void) {
  std::cout << "Unesite broj: ";
  int n;
  std::cin >> n;

  try {
    if (n % 2 == 0) {
      foo();
    } else {
      throw std::string("Broj nije paran");
    }
  } catch (const std::invalid_argument& e) {
    std::cout << "catch std::invalid_argument: " << e.what() << std::endl;
  } catch (const std::string& e) {
    std::cout << "catch string: " << e << std::endl;
  }

  return 0;
}
