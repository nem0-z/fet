#include <iostream>

using namespace std;

struct Gadget{

  virtual void screen(){
    std::cout << screenRes << std::endl;
  }
  virtual void foo() = 0;
  protected:
    double screenRes;
};

struct Phone : Gadget{
  void foo() { 
    std::cout << 1 << std::endl;
  }
 virtual void bar(){
    std::cout << 4 << std::endl;
  }
};

struct Com : Phone{
  void foo() {
    std::cout << 2 << std::endl;
  }
  void bar(){
    std::cout << 3 << std::endl;
  }
};

struct Tech : Gadget{
  void foo();
};

int main(void)
{
  Com samsung;
  Phone* test = &samsung;
  test->foo();
  test->bar();
  auto ptr = new Phone[5];
  *(ptr+1) = Com{};
  *(ptr+2) = Phone{};
  *(ptr+3) = Tech{}; //error
  return 0;
}
