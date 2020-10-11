#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[])
{
  std::vector<int>* v = new std::vector<int>;
  *v = {2,5,1,76};
  cout<<v->size()<<endl;
  delete v;
  int* ptr = new int;
  for(auto i = 0 ; i<5; ++i)
    ptr[i] = i;
  for(auto i = 0 ; i<20; ++i)
    cout<<ptr[i]<<" ";
  return 0;
}
