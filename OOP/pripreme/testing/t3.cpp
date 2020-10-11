#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void zamjeni(T& a,T& b)
{
  T temp=a;
  a=b;
  b=temp;
}

template<typename It>
void obrni(It p,It k)
{
  --k;
  while(p<k && p!=k){
    zamjeni(*p,*k);
    p++;
    k--;
  }
}

template<typename Kont>
void ispisi(ostream& o,Kont k)
{
  for(auto it=k.begin();it!=k.end();it++)
    o<<*it<<" ";
  o<<endl;
}
int main(){
  vector<int> k1={4,1,5,7};
  vector<int> k2={4,1,3,5,7};
  obrni(k2.begin(),k2.end());
  ispisi(cout,k2);
}
