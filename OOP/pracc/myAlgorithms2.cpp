#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
template<class InputIt, class UnaryOpt>
InputIt findIf (InputIt start, InputIt end, UnaryOpt test)
{
  while(start!=end)
  {
    if(test(*start++)) return start;
  }
  return end;
}
int main(int argc, char *argv[])
{
  vector<int> vect{3,7,2,1,7,87,3,7,2,8,9,0,};
  int unos;
  cin>>unos;
  auto pred = [&unos](int a){
    return unos == a;
  };
  auto it = findIf(vect.begin(),vect.end(),pred);
  while(it!=vect.end()) //test
  {
    cout<<*it++<<" ";
  }
  return 0;
}
