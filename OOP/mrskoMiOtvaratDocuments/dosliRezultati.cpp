#include <iostream>

class Sinisa{
  public:
  int foo() const {
    x_ = 5;
    return x_;
  }
  Sinisa(Sinisa&){
    std::cout << 1 << std::endl;
  }
  Sinisa(const Sinisa&){
    std::cout << 2 << std::endl;
  }
  Sinisa() = default;

  private:
  mutable int x_{};
};


int main(void)
{
  Sinisa x;
  Sinisa y = x;
  return 0;
}
