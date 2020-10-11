#include <algorithm>
#include <iostream>
#include <vector>

template <typename It>
void quickSort(It begin, It end) {
  // posao
  auto count = end - begin;
  if (count <= 1) return;
  // ako je niz od 0 ili 1 elemenata mrs nazad
  // partitioning ide oko srednjeg elementa
  auto middle_element = begin + count / 2;
  auto end_element = end - 1;
  std::swap(*middle_element, *end_element);
  auto partition_point = std::partition(
      begin, end - 1,
      [&end_element](auto& elem) { return elem < *end_element; });
  std::swap(*end_element, *partition_point);
  // ovaj end element je ustv nas srednji pa ko biva da particioniramo oko
  // srednjeg
  //
  // rekurzija
  quickSort(begin, partition_point);
  quickSort(partition_point+1, end_element);
}

int main(void) {
  std::vector<int> v;
  for (int i = 0; i < 20; ++i) v.push_back(i);
  std::random_shuffle(v.begin(), v.end());

  for (const auto& item : v) std::cout << item << " ";
  std::cout << std::endl;

  quickSort(v.begin(), v.end());
  // uhm nece ovo nesto de pogledaj

  for (const auto& item : v) std::cout << item << " ";
  std::cout << std::endl;
  return 0;
}
