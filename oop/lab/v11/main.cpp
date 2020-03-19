#include <iostream>
#include <string>

using namespace std;

void foo(const string& a){
  std::cout << a << std::endl;
}

int main(int argc, char *argv[])
{
  string x = "test";
  foo("test");
  return 0;
}
