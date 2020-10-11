#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
void foo(char a, std::string b = "sinisa") {
  std::cout << 1;
}
void foo(int a)
{
  cout<<2;
}
// void foo(char a = 5)
// {
//   cout<<3;
// }
void bar(int a)
{
    cout<<4;
}
void bar(double a)
{
  cout<<5;
}
void bar(std::string x)
{
  cout<<6;
}
// void bar(bool a)
// {
//   cout<<7;
// }

int main(void)
{
  bar(true);
  return 0;
}
