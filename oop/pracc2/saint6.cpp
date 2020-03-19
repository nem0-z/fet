//test
#include <iostream>
#include <string>

using namespace std;

struct test {
  private:
  int a = 4;
  string b;
  public:
  test() { std::cout << "Def" << std::endl; }

  test(int a) { std::cout << "Int" << std::endl; }

  // test(const test& d) : a{d.a}, b{d.b} {
  //   std::cout << "Kopi konstruktor" << std::endl;
  // }

  test(test&& d) : a{d.a}, b{d.b} {
    std::cout << "Move konstruktor" << std::endl;
  }

  test& operator=(const test& d) {
    std::cout << "Copy assignment operator" << std::endl;
    return *this;
  }

  // test& operator=(test&& d) {
  //   std::cout << "Move assignment operator" << std::endl;
  //   return *this;
  // }

  ~test() { std::cout << "Destruktor" << std::endl; }
friend std::ostream& operator<<(std::ostream& out, const test& foo);
};

std::ostream& operator<<(std::ostream& out, const test& foo){
  out<<foo.a;
  out<<foo.b;
  return out;
}

int main(int argc, char* argv[]) {
  test a;
  test b(5);
  // b = a;
  b = std::move(a);
  std::cout<<a<<b<<a<<std::endl;
  return 0;
}
