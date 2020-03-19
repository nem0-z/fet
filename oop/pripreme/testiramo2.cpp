#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int foo(int& a) 
{
 return a+='a';
}
int main(void)
{
  vector<int> vec{5,7};
  int x = 5;
  cout<<x<<endl;
  foo(x);
  cout<<x<<endl;
  int a = 'a';
  cout<<a<<endl;
  char& b = a;
  cout<<b<<endl;
  ++a;
  cout<<a<<endl;
  cout<<b<<endl;

  // for (const auto& e:vec) cout<<e<<" ";
  return 0;
}
