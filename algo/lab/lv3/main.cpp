#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// not stable
void selectionSort(int* array, int len) {
  for (int j = 0; j < len; ++j) {
    int minIndex = j;
    for (int i = j; i < len; ++i) {
      if (array[minIndex] > array[i]) minIndex = i;
    }
    std::swap(array[minIndex], array[j]);
  }
}

// stable
void bubbleSort(int* array, int len) {
  // granice za vanjsku petlju : [n,0)
  for (int i = len; i > 0; --i) {
    bool flag = false;
    for (int j = 1; j < i; ++j) {
      if (array[j] < array[j - 1]) {
        std::swap(array[j], array[j - 1]);
        flag = true;
      }
      if (!flag)
        return;  // in case no swaps happened then gtfo
                 // array is already sorted
    }
  }
}

// stable
void insertionSort(int* array, int len) {
  for (int i = 1; i < len; ++i) {
    // 0 - i uvijek sortirano
    // i-ti element ubaciti u [0-i)
    for (int j = i; j > 0 && array[j] < array[j - 1]; --j) {
      std::swap(array[j], array[j - 1]);
    }
  }
}

// one step for shell sort
void insertionsortVar(int* array, int n, int increment) {
  // jedan korak shellsorta
  // treba insertion sortom da sortira elemente
  // npr 5 10 15 20 25...
  for (int i = increment; i < n; i += increment) {
    for (int j = i; j >= increment && array[j] < array[j - increment];
         j -= increment)
      std::swap(array[j], array[j - increment]);
  }
}

// unstable
void shellSort(int* array, int len) {
  for (int k = len / 2; k > 2; k /= 2) {
    for (int i = 0; i < k; ++i) {
      insertionsortVar(array + i, len - i, k);
    }
  }
  insertionsortVar(array, 20, 1);
  // ovo je pozivanje "klasicnog" insertion sorta
  // da ih poslozi na kraju
}

int main(void) {
  int v[20];
  for (int i = 0; i < 20; ++i) {
    v[i] = i;
  }
  std::random_shuffle(v, v + 20);
  std::cout << "Before sort: " << std::endl;
  for (int i = 0; i < 20; ++i) std::cout << v[i] << " ";
  std::cout << '\n';

  // selectionSort(v,20);
  // bubbleSort(v, 20);
  // insertionSort(v, 20);
  shellSort(v,20);

  std::cout << "After sort: " << std::endl;
  for (int i = 0; i < 20; ++i) std::cout << v[i] << " ";
  std::cout << '\n';
  return 0;
}
