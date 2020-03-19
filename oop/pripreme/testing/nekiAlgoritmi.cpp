#include <iostream>
#include <vector>

using namespace std;

template<typename InputIt, typename Val>
InputIt veciOd(InputIt start, InputIt end, const Val& value)
{
  auto predicate = [value](int a){
    return a>value;
  };
  while(start!=end)
    if(predicate(*start++)) return --start;
  return end;
  
}


int main(void)
{
  std::vector<int> v{5,4,1,2,10,6,1};
  auto foo = veciOd(v.begin(),v.end(),9);
  *foo = 14;
  for(const auto& x:v) cout<<x<<" ";
  cout<<endl;
  return 0;
}
