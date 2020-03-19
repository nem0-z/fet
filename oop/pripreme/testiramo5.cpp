#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(void)
{
  map<char,int> mapa;
  char unos;
  int i = 0;
  for(char unos;cin>>unos;++i)
  {
    mapa[unos] = i;
  }
  auto x = mapa.find('b');
  x->second = 20;
  for(auto it = mapa.begin(); it!= mapa.end(); ++it)
  {
    cout<<it->first<<" "<<it->second<<endl;
  }
  return 0;
}
