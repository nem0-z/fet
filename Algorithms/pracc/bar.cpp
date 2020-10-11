#include <algorithm>
#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

// 5 1 2 3 4
void bubble(int* arr, int size) {
  for (int i = size - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (arr[j] > arr[j + 1]) std::swap(arr[j], arr[j + 1]);
    }
  }
}

template <typename It>
void bsort(It begin, It end) {
  // while (begin != end) {
  //   auto i = begin;
  //   auto j = --end;
  //   while (i != j) {
  //     auto i1 = i;
  //     auto i2 = ++i;
  //     if (*i1 > *i2) std::swap(*i1, *i2);
  //   }
  // }
  const int size = end - begin;
  for (int i = size - 1; i > 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (*(begin + j) > *(begin + j + 1))
        std::swap(*(begin + j), *(begin + j + 1));
    }
  }
}

template <typename It>
void ssort(It begin, It end) {
  while (begin != end) {
    It min = begin;
    It current = min;
    while (current != end) {
      if (*current < *min) min = current;
      ++current;
    }
    if (current != min) std::swap(*begin, *min);
    ++begin;
  }
}

void selection(int* arr, int size) {
  for (int i = 0; i < size; ++i) {
    int min = i;
    for (int j = min; j < size; ++j) {
      if (arr[j] < arr[min]) min = j;
    }
    if (min != i) std::swap(arr[i], arr[min]);
  }
}

template <typename It>
void isort(It begin, It end) {
  auto tbegin = begin;
  while (begin != end) {
    It t1 = begin;
    It t2 = ++begin;
    while (*t2 < *t1 && t2 != tbegin) {
      std::swap(*t2--, *t1--);
    }
  }
}

template <typename It>
void merge(It b1, It e1, It b2, It e2, It dest) {
  while (b1 != e1 || b2 != e2) {
    if (b1 == e1)
      *dest++ = *b2++;
    else if (b2 == e2)
      *dest++ = *b1++;
    else if (*b1 < *b2)
      *dest++ = *b1++;
    else
      *dest++ = *b2++;
  }
}

template <typename It>
void msort(It begin, It end) {
  const int size = end - begin;
  if (size == 1) return;
  It mid = begin + size / 2;
  msort(begin, mid);
  msort(mid, end);
  std::vector<int> tmp;
  tmp.resize(size);
  merge(begin, mid, mid, end, tmp.begin());
  std::copy(tmp.begin(), tmp.end(), begin);
}

template <typename It>
It pp(It begin, It end) {
  It pivot = --end;
  while (begin != end) {
    if (*end < *pivot)
      std::swap(*begin++, *end);
    else
      --end;
  }
  std::swap(*begin, *pivot);
  return begin;
}

template <typename It>
void qsort(It begin, It end) {
  const int size = end - begin;
  if (size <= 1) return;
  // if (size <= 15) isort(begin, end);
  auto partitionPoint = pp(begin, end);
  qsort(begin, partitionPoint);
  qsort(++partitionPoint, end);
}

int arr[] = {5, 7, 1, 2, 6, 87, 4, 3};

int finds(int* arr, int size) {
  int mid = size / 2;
  int midElem = arr[mid];
  if (midElem < arr[mid - 1])
    return midElem;
  else if (midElem > arr[mid + 1])
    return arr[mid + 1];
  if (arr[0] < arr[size - 1]) return arr[0];
  if (arr[0] < midElem)
    return finds(arr + size - mid, mid);
  else
    return finds(arr, size - mid);
}

int findm(int* arr, int size) {
  if (size == 1) return *arr;
  int leftmin = findm(arr, size / 2);
  int rightmin = findm(arr + size / 2, size - size / 2);
  return std::min(leftmin, rightmin);
}

int main(int argc, char* argv[]) {
  // vector<int> v;
  // int i = 21;
  // while (--i) v.emplace_back(i);
  // std::random_shuffle(v.begin(), v.end());
  // for (auto a : v) cout << a << " ";
  // cout << endl;
  // qsort(v.begin(), v.end());
  // for (auto a : v) cout << a << " ";
  // cout << endl;
  int niz[] = {5, 6, 7, 8, 11, 12, 13, -1, 2, 4};
  // int niz[] = {1,2,3,4,5,6};
  // std::cout << finds(niz, sizeof(niz)/sizeof(int)) << std::endl;
  std::cout << findm(niz, sizeof(niz) / sizeof(int)) << std::endl;
}
