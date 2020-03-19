#include "MojNiz.hpp"
// #include "MojNizBackup.hpp"

using namespace std;

int main(void)
{
  MojNiz<int> x{6,7,8};
  MojNiz<int> y{1,2,3};
  // MojNiz<int> z = MojNiz<int>{4,1,9};
  // MojNiz<int> d = x;
  x = std::move(y);
  y = x;
  // z = std::move(x);
  // x = MojNiz<int>{5,1,1,2,2,2};
  // for(auto i = 0; i<x.size(); ++i)
  //   cout<<x[i];
  // cout<<endl;
  // for(auto i = 0; i<y.size(); ++i)
  //   cout<<y[i];
  // cout<<endl;
  // for(auto i = 0; i<z.size(); ++i)
  //   cout<<z[i];
  // cout<<endl;
  return 0;
}
