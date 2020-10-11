#include <algorithm>
#include <iostream>
#include <vector>

template <typename It>
void merge(It begin1, It end1, It begin2, It end2, It dest) {
  while (begin1 != end1 || begin2 != end2) {
    if (begin1 == end1) {
      *dest++ == *begin2++;
    } else if (begin2 == end2) {
      *dest++ = *begin1++;
    } else if (*begin1 <= *begin2) {
      *dest++ = *begin1++;
    } else if (*begin2 < *begin1) {
      *dest++ = *begin2++;
    }
  }
}

template <typename It>
void mergeSort(It begin, It end) {
  if (end - begin <= 1) return;

  It middle = begin + (end - begin) / 2;
  mergeSort(begin, middle);
  mergeSort(middle, end);
  // middle se nece dva puta raditi zato jer prvi poziv je [begin,middle)
  // a drugi je [middle,end)

  // izdijelili smo sad trebamo mergat
  // za zadacu bi bilo:
  // merge(begin,middle,middle,end,begin);
  // dakle od begin do middle i middle do end spoji na destinaciju begin

  // dodatni niz koji ce da bude olaksica
  std::vector<typename It::value_type> tmp;
  tmp.resize(end - begin);
  merge(begin, middle, middle, end, tmp.begin());
  std::copy(tmp.begin(), tmp.end(), begin);
}

int main(void) {
  std::vector<int> v;
  for (int i = 0; i < 20; ++i) v.push_back(i);
  std::random_shuffle(v.begin(), v.end());

  for (const auto& item : v) std::cout << item << " ";
  std::cout << std::endl;

  mergeSort(v.begin(), v.end());
  // uhm nece ovo nesto de pogledaj

  for (const auto& item : v) std::cout << item << " ";
  std::cout << std::endl;
  return 0;
}
