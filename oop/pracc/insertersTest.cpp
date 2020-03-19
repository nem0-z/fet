#include <iostream>
#include <vector>
#include <list>
using namespace std;


int main(void)
{
  // std::list<int> vec;
  // std::list<int>::iterator vecIterator = vec.begin();
  // for(int unos;cin>>unos;)
  // {
  //   auto foo = inserter(vec,vecIterator);
  //   *foo = unos;
  // }
  // auto insertIterator = inserter(vec,vecIterator);
  // *insertIterator = 10;
  // for(const auto& x:vec) cout<<x<<" ";
  // cout<<endl;
  std::vector<double> vec1;
  for(int unos;cin>>unos;)
  {
    auto foo = back_inserter(vec1);
    *foo = unos;
  }
  for(const auto& x:vec1) cout<<x<<" ";
  cout<<endl;
  return 0;
}
