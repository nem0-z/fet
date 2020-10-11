#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;

template <class T, class U, class Z>
U foo(T x, U y = 10, Z sinisa = false) {
  std::cout << 1 << std::endl;
}

extern int ajla;
bool z;

template <class iter>
bool foo(iter start, iter end) {
  if (start==end)
    return true;
  else
    return false;
}

void  reverseVec(vector<int>& vec)
{
  vector<int> tmp;
  for(auto it = vec.end()-1; it>=vec.begin(); --it)
    tmp.push_back(*it);
  vec.clear();
  for(auto& x:tmp) vec.push_back(x);
  // for(const auto& x:tmp) std::cout << x <<" ";
}

int bomba(void)
{
  exit(0);
}

int main(int argc, char *argv[]) {
 // list<int> cont{6, 2, 6, 1};
  vector<int> vec{6,1,2,6,8,2};
  // reverseVec(vec);
  // for(const auto& x:vec) std::cout << x << std::endl;
  // std::vector<int>::const_iterator konstantni;
  // konstantni = vec.begin();
  // std::cout << *konstantni << std::endl;
  // *konstantni = 5;
  throw bomba();
  // foo(50, 20, true);
  // std::cout << std::boolalpha << z << std::endl;
  // std::cout << std::boolalpha << foo(cont.begin(), cont.begin()) << std::endl;
  // auto mojErase = cont.erase(--(--cont.end()));
  // *mojErase = 5;
  // auto mojInsert = inserter(cont,++cont.begin());
  // *mojInsert = 10;
  // for(const auto& x:cont) std::cout << x << " ";
  return 0;
}
