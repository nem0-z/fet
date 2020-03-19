#include <iostream>
#include <vector>
using namespace std;

template<class InputIt, class UnaryOpt>
int myFind(InputIt start,InputIt end, UnaryOpt test)
{
  int res{};
    while(start!=end){
      if(test(*start)) ++res; 
      ++start;
    } 
    return res;
}

int main(int argc, char *argv[])
{
  vector<double> vect = {5,2,7,8,2,7,41,87,96,3,2,8};
  int key;
  cin>>key;
  auto pred = [&key](int x){
    return key == x;
  };
  cout<<myFind(vect.begin(),vect.end(),pred);
  return 0;
}
