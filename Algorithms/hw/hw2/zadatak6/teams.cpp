#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>

class Tim
{
public:
  std::string naziv;
  int bodovi;
  int primljeniGolovi;
  int postignutiGolovi;
};

std::ostream &operator<<(std::ostream &out, const Tim &tim)
{
  out << tim.naziv << "\t" << tim.bodovi << "\t" << tim.primljeniGolovi
      << "\t\t" << tim.postignutiGolovi << "\t\t"
      << tim.postignutiGolovi - tim.primljeniGolovi << std::endl;
  return out;
}

template <typename It>
void printArr(It begin, It end)
{
  std::cout << "Ekipa\tBodovi\tPrimljeni\tPostignuti\tGol razlika\n";
  std::cout << std::string(50, '-') << std::endl;
  while (begin != end)
    std::cout << *begin++ << " ";
  std::cout << std::endl;
}

auto makeArr(void)
{
  std::vector<Tim> v;
  int i = 66;
  while (i <= 90)
  {
    Tim t;
    t.naziv = (char)i;
    t.bodovi = rand() % 100;
    t.primljeniGolovi = rand() % 10;
    t.postignutiGolovi = rand() % 10;
    v.push_back(t);
    ++i;
  }
  std::random_shuffle(v.begin(), v.end());
  v.push_back(Tim{"foo", 20, 5, 5});
  v.push_back(Tim{"bar", 20, 5, 5});
  v.push_back(Tim{"a", 20, 7, 5});
  v.push_back(Tim{"b", 20, 10, 8});
  v.push_back(Tim{"c", 20, 4, 2});
  return v;
}

namespace zad6
{
  template <typename It, typename Pred>
  It partition(It begin, It end, Pred p)
  {
    It pivot = --end;
    while (begin <= end)
    {
      if (begin > --end)
        break;
      // cheeky decrement end and check for overlap
      while (p(*begin, *pivot) && begin != pivot)
        ++begin;
      while (!p(*end, *pivot) && end != begin)
        --end;
      if (begin < end)
        std::swap(*begin++, *end);
    }
    std::swap(*begin, *pivot);
    return begin;
  }

  template <typename It, typename Pred>
  void insertionsort(It begin, It end, Pred p)
  {
    It dummyBegin, dummyEnd, i, j;
    for (dummyBegin = begin, dummyEnd = --end; begin != dummyEnd;)
    {
      It i = begin;
      It j = ++begin;
      while (p(*j, *i) && j != dummyBegin)
        std::swap(*j--, *i--);
    }
  }
  template <typename It, typename Pred>
  void quicksort(It begin, It end, Pred p)
  {
    const int size = end - begin;
    if (size <= 1)
      return;
    It partition_point = zad6::partition(begin, end, p);
    quicksort(begin, partition_point, p);
    quicksort(++partition_point, end, p);
  }
} // namespace zad6

void sortTeams(std::vector<Tim> &v)
{
  zad6::quicksort(v.begin(), v.end(), [](const Tim &t1, const Tim &t2) {
    return t1.naziv < t2.naziv;
  });
  zad6::insertionsort(v.begin(), v.end(), [](const Tim &t1, const Tim &t2) {
    return t1.postignutiGolovi > t2.postignutiGolovi;
  });
  zad6::insertionsort(v.begin(), v.end(), [](const Tim &t1, const Tim &t2) {
    return t1.postignutiGolovi - t1.primljeniGolovi >
           t2.postignutiGolovi - t2.primljeniGolovi;
  });
  zad6::insertionsort(v.begin(), v.end(), [](const Tim &t1, const Tim &t2) {
    return t1.bodovi > t2.bodovi;
  });
  std::cout
      << "Pri sortiranju timova prvo je koristen quicksort da se sortiraju po "
         "nazivu, ovde nam nije bila bitna stabilnost pa smo njega koristili, "
         "u ostala 3 slucaja je koristen insertionsort(inplace merge bi bila "
         "bolja opcija svakako medjutim nisam ga implementirao kako treba tj "
         "da radi u O(nlogn) time complexity koji je stabilno sortirao timove "
         "po ostalim parametrima (stabilnost je postignuta tako sto smo "
         "sortirali na nacin da zadnji sort bude po kriteriju koji nam je "
         "glavni)"
      << std::endl;
}

int main(void)
{
  std::vector<Tim> v = makeArr();
  sortTeams(v);
  std::cout << "After sorting: " << std::endl;
  printArr(v.begin(), v.end());
}
