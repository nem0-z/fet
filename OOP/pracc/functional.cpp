#include <iostream>
#include <functional>

using namespace std;

void testFun(int a, function<int(int,int)> fun)
{
  cout<<fun(a,5.7)+5; 
}

int main(void)
{
  int c = 15;
  auto funkcija = [&c](int x, int y) 
  {
      c=10;
      return x+y-c;
      
  };
  testFun(10,funkcija);
  cout<<c;
  return 0;
}
