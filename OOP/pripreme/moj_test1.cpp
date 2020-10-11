#include <functional>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

// napraviti genericku funkciju moj_meks(x,y,z)
// x,y - iteratori na proizvoljnu kolekciju
// z - kriterij za sortiranje
// od korisnika u mainu traziti unos vrijednosti test
// funkcija transformira niz na nacin da sve vrijednosti manje od vrijednosti test 
// budu zamijenjene nulom
// u slucaju da nijedna vrijednost iz kolekcije nije zadovoljila uslov
// potrebno baciti iznimku tipa invalid_argument

template<typename Iter,typename Fun>
auto moj_meks(Iter start,Iter end,Fun predicate)
{
  int cnt = 0;
  while(start!=end)
  {
    if(predicate(*start)) {
      *start = 0;
      ++cnt;
    }
    ++start;
  }
  if(cnt == 0) throw std::invalid_argument("jebo te led sine");
}

int main(void)
{
  vector<int> vec{5,7,2,1,5,2,56};
  int unos;
  cin>>unos;
 try{ moj_meks(vec.begin(),vec.end(),[unos](auto a){
      return a<unos;});
  for(auto x:vec) cout<<x<<" ";
 }
 catch(std::invalid_argument c)
 {
    cout<<c.what()<<endl;
 }
  return 0;
}
