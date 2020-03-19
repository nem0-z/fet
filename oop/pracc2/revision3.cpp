#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using namespace std;

template <typename Map>
void printMap(Map mapa) {
  for (auto it = mapa.begin(); it != mapa.end(); ++it)
    cout << it->first << " " << it->second << endl;
}

template<typename T = double>
void f1(T a)
{
  std::cout << sizeof(T) << std::endl;
}

struct A{
  
};

int main(void) {
  // map<string, int> hesh;
  // hesh["sinisa"] = 2;
  // hesh["ceero"] = 3;
  // hesh["ceero"]++;
  // printMap(hesh);
  // cout << hesh["tomas"] << endl;
  // printMap(hesh);
  // // auto it = hesh.find("ajla");
  // // it->second = 55;
  // // printMap(hesh);
  // int a = 5;
  // f1(5);
  int a;
  int b = 10;
  const int* p;
  p = &a;
  int* const pc = &a;
  *pc = 5;
  const int* const pcc = &b;
  std::cout << a << std::endl;
  return 0;
}

