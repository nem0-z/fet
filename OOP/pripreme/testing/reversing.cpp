#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>

template<class BidirIt>
void rikverc(BidirIt first, BidirIt last)
{
    while ((first != last) && (first != --last))
        std::swap(*first++, *last);
}
int main(int argc, char *argv[])
{
  // std::list<int> v{2,3,4,5,6,7,8};
  // std::string s = "Sinisa";
  // rikverc(v.begin(),v.end());
  // for(const auto& item:v) std::cout << item << " ";
  // std::cout<<'\n';
  // rikverc(s.begin(),s.end());
  // for(const auto& item:s) std::cout << item << " ";
  // std::cout<<'\n';
  std::map<int, char> map;
  map[1] = 'a';
  map[2] = 'b';
  map[3] = 'c';
  for(auto it = map.begin(); it!= map.end(); ++it)
  {
    std::cout << (*it).first << " " << (*it).second << std::endl;
  }
  rikverc(map.begin(),map.end());
  for(auto it = map.begin(); it!= map.end(); ++it)
  {
    std::cout << (*it).first << " " << (*it).second << std::endl;
  }
  return 0;
}
