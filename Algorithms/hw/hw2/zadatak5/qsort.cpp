#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

template <typename It>
void printArr(It begin, It end)
{
  while (begin != end)
    std::cout << *begin++ << " ";
  std::cout << std::endl;
}

auto makeArr(void)
{
  std::vector<int> v;
  int i = 10000000;
  while (i--)
    v.push_back(i);
  std::random_shuffle(v.begin(), v.end());
  return v;
}

namespace QS
{

  template <typename It>
  void insertionsort(It begin, It end)
  {
    for (It dummyBegin = begin, dummyEnd = --end; begin != dummyEnd;)
    {
      It i = begin;
      It j = ++begin;
      while (*j < *i && j != dummyBegin)
        std::swap(*j--, *i--);
    }
  }
  template <typename It>
  It partition(It begin, It end)
  {
    It pivot = --end;
    while (begin <= end)
    {
      if (begin > --end)
        break;
      // cheeky decrement end and check for overlap
      while (*begin <= *pivot && begin != pivot)
        ++begin;
      while (*end > *pivot)
        --end;
      if (begin < end)
        std::swap(*begin++, *end);
    }
    std::swap(*begin, *pivot);
    return begin;
  }

  template <typename It>
  void quicksort(It begin, It end)
  {
    const int size = end - begin;
    if (size <= 1)
      return;
    if (size < 10)
    {
      insertionsort(begin, end);
      return;
    }
    It partition_point = QS::partition(begin, end);
    quicksort(begin, partition_point);
    quicksort(++partition_point, end);
  }
} // namespace QS

int main(void)
{
  std::vector<int> v = makeArr();
  // std::vector<int> v{1,2,3,4,6,-2};
  // std::cout << "Before sorting: " << std::endl;
  // printArr(v.begin(), v.end());
  auto now = std::chrono::system_clock::now();
  QS::quicksort(v.begin(), v.end());
  auto finish = std::chrono::system_clock::now();
  auto elapsed = finish - now;
  // std::cout << "After sorting: " << std::endl;
  // printArr(v.begin(), v.end());
  std::cout << "Time elapsed: " << elapsed.count() / 1000000 << "ms"
            << std::endl;
}
