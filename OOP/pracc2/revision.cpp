#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

void unos(vector<double>& vec) {
  for (double unos; cin >> unos;) vec.push_back(unos);
}

void rikverc(vector<double>& vec) {
  auto start = vec.begin();
  auto end = vec.end();
  while ((start != end) && (start != --end)) std::swap(*start++, *end);
}

int main(void) {
  const char* str = "string";
  std::cout << str << std::endl;
  vector<double> kont;
  // unos(kont);
  // rikverc(kont);
  // std::sort(kont.begin(),kont.end(),[](int a, int b){return a>b;});
  // for(const auto& x:kont) cout<<x<<" ";
  // cout<<'\n';
  int a = 10;
  int& b = a;
  const int& c = b;
  auto d = c;
  a = 15;
  d = 4;
  std::cout << a << b << c << d << std::endl;
  auto lambdaFoo = [a](int a_) mutable -> bool {
    a = 5;
    return true;
  };
  lambdaFoo(4);
  std::cout << c << std::endl;
  // std::cout << lambdaFoo(5) << std::endl;
  return 0;
}

string x;
string y{};
string z{"abc"};
string d(10, 'c');
string a = x;
