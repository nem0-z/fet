#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
using namespace std;

template <typename OutputIt>
void output(OutputIt start,
            OutputIt end)  // ovo smo stavili cisto onako da znamo da nam je
                           // "output iterator" dovoljan
{
  while (start != end) cout << *start++ << " ";
  cout << endl;
}

template <typename OutputIt, typename InputIt, typename UnaryOpt>
void transformiraj(OutputIt start, OutputIt end, InputIt destination,
                   UnaryOpt foo) {
    while (start!= end)
    {
      *destination = foo(*start);
      ++start;
    }
}

template <typename OutputIt, typename test>
OutputIt mojFind(OutputIt start, OutputIt end, test pred) {
  while (start != end) {
    if (pred(*start))
      return start;
    else
      ++start;
  }
  return end;
}
int main(void) {
  list<int> a{1, 6, 1, 7, 2, 7, 2};
  list<double> b{1.5, 76.3, 1.6, 2.6, 21.6};
  list<char> c{'h', 'y', 65, 'd', '$'};
  output(a.begin(), a.end());
  output(b.begin(), b.end());
  output(c.begin(), c.end());
  int unos;
  cin >> unos;
  auto pred = [&unos](int x) {return x == unos; };
  auto it = mojFind(b.begin(), b.end(),pred);
  auto it5 = a.begin();
  it5++;
  auto insertIt = inserter(a,it5);
  transformiraj(a.begin(),a.end(),insertIt,pred);
  output(a.begin(), a.end());
  //probaj tu odozgo funkciju transformiraj uraditi
  // ona ce nesto smjestiti negdje na destinaciju 
  // a.erase(a.begin()); //brise prvi clan u a
  //kolekcija.erase(mjesto gdje hoces brisat)
  //iteratori invalid nakon sto si mijenjao velicinu kolekcije 
  return 0;
}
