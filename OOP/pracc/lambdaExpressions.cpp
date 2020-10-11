#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
void printArray(const std::vector<int> &a) {
  for(auto item:a) std::cout<<item<<" ";
  std::cout << std::endl;
}
int main(void) {
  using namespace std;
  std::vector<int> array;
  for (int input; std::cin >> input;) array.push_back(input);
  cin.clear();
  // printArray(array);
  // sort(std::begin(array), std::end(array));
  // printArray(array);
  // auto criteria1 = [](int a, int b){
  //   return a>b;
  // };
  // sort(std::begin(array), std::end(array),criteria1);
  // printArray(array);
  auto criteria2 = [](int a, int b){
    return a<b;
  };
  std::sort(array.begin()+3, array.end(),criteria2);
  printArray(array);
  vector<string> cont;
  for (string foo; cin>>foo;) cont.push_back(foo);
  auto criteria3 = [](string a, string b){
    return a[2]<b[2];
  };
  sort(cont.begin(),cont.end(),criteria3);
  for (auto e:cont) cout<<e<<endl;
  return 0;
}
