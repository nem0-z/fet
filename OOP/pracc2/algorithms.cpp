#include "algorithms.hpp"
#include <iostream>
#include <utility>
#include <vector>
int main() {
  // std::vector<int> myvector;
  // for (int i=1; i<6; i++) myvector.push_back (i*10); // myvector: 10 20 30 40
  // 50
  //
  // int myints[] = {10, 20, 80, 320, 1024};  //   myints: 10 20 80 320 1024
  // int myints1[5];
  // algo::transform(myints, myints + 5, myints1, [](int a) { return a * 10; });
  // for (int i = 0; i < 5; ++i) std::cout << myints[i] << " ";
  // std::cout << std::endl;
  // for (int i = 0; i < 5; ++i) std::cout << myints1[i] << " ";
  // std::cout << std::endl;
  // std::pair<std::vector<int>::iterator,int*> mypair;
  //
  // // using default comparison:
  // mypair = algo::mismatch (myvector.begin(), myvector.end(), myints);
  // std::cout << "First mismatching elements: " << *mypair.first;
  // std::cout << " and " << *mypair.second << '\n';
  //

  // std::string elems[10] = {"air","water","fire","earth"};
  //
  // // insert new element at the beginning:
  // algo::move_backward (elems,elems+4,elems+5);
  // elems[0]="ether";
  //
  // std::cout << "elems contains:";
  // for (int i=0; i<10; ++i)
  //   std::cout << " [" << elems[i] << "]";
  // std::cout << '\n';
  

// int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };
//
//  auto test =  algo::remove_if (myints, myints+8, [](int a){return a==20;}); // 10 99 30 30 99 10 10 99
//
//   std::cout << "myvector contains:";
//   for(int* i = myints ; i<test; ++i)
//     std::cout<<*i<<" ";
//   std::cout << '\n';
 
//  int myints[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
//   std::vector<int> myvector (myints,myints+9);
//   // using default comparison:
//   std::vector<int>::iterator it;
//   it = algo::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
//                                                          //                ^
//   myvector.resize( std::distance(myvector.begin(),it) ); // 10 20 30 20 10
//   // print out content:
//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it!=myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';
//
  // std::vector<int> v{5,1,2,6,3,1};
  // for(const auto& x:v) std::cout<<x<<" ";
  // std::cout<<'\n';
  // algo::partitionRight(v.begin(),v.end(),[](int a){return a%2;});
  // for(const auto& x:v) std::cout<<x<<" ";
  // std::cout<<'\n';
  std::vector<int> v{1,2,3,4,5};
  std::cout << algo::is_sorted(v.begin(),v.end()) << std::endl;

  return 0;
}
