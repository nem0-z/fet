#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <utility>

using namespace std;

template<typename T>
void print(const T& kont)
{
  for(const auto& x:kont) cout<<x<<" ";
  cout<<'\n';
}

int main(void)
{
  vector<int> vec{5,7,2,1,3};
  list<int> lista{5,9,6,4,0};
  print(vec);
  auto vecIns = inserter(vec,vec.begin()+2);
  *vecIns = 10;
  print(vec);
  *vecIns = 3;
  print(vec);
  *vecIns = 2;
  print(vec);
  *vecIns = 12;
  print(vec);
  *vecIns = 16;
  print(vec);
  *vecIns = 8;
  print(vec);
  *vecIns = 10;
  print(vec);
  auto er = vec.erase(vec.begin()+2,vec.begin()+4);
  *er = 5;
  print(vec);
  auto erS = vec.erase(vec.begin()+5);
  *erS = 7;
  print(vec);
  return 0;
}
