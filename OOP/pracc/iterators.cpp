#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

int main(void) {
  list<int> lista{1, 2, 3, 4, 5};
  vector<int> vect{6, 7, 8, 9, 10};
  //   for(auto i = 0; i<vect.size() ; ++i)
  //     cout<<vect[i]<<" ";
  //  for (auto i = begin(vect); i!= end(vect); ++i)
  //     cout<<*i<<" ";
  //  for (auto i = begin(vect); i!= end(vect);)
  //    cout<<*i++<<" ";
  vector<int>::iterator i;
  for (i=vect.begin(); i != vect.end(); i+=2) *i *= 2; //why it won't work
  for (auto x : vect) cout << x << " ";
  // vector<int>::iterator it;
  // it = end(vect);
  // cout<<*it;
  // for (i=vect.begin(); i != vect.end(); ++i) *i = *i * 2;
  // for (auto x : vect) cout << x << " ";
  for (auto it = lista.begin(); it!= lista.end(); ++it)
    cout<<*it<<" ";
  return 0;
}
