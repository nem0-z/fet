#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class heap {
  public:
  heap();
  heap(const heap&);
  heap(heap&&);
  // ~heap();

  heap& operator=(const heap&);
  heap& operator=(heap&&);

  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }

  template <typename U>
  void insert(U&&);
  T pop();

  void print() const;

  private:
  T* ptr_;
  size_t size_;
  void srediNadole(int);
  void srediNagore(int);
};

template <typename T>
heap<T>::heap() : ptr_{new T[100]}, size_{0} {}

template <typename T>
template <typename U>
void heap<T>::insert(U&& val) {
  ptr_[++size_] = std::forward<U>(val);
  srediNagore(size_);
}

template <typename T>
void heap<T>::srediNagore(int index) {
  while (index > 1 && ptr_[index] > ptr_[index / 2]) {
    std::swap(ptr_[index], ptr_[index / 2]);
    index /= 2;
  }
}

template <typename T>
T heap<T>::pop() {
  T toPop = std::move(ptr_[1]);
  ptr_[1] = ptr_[size_];
  srediNadole(1);
  --size_;
  return toPop;
}

template <typename T>
void heap<T>::srediNadole(int index) {
  if (index >= size_) return;
  int leftChildIndex = 2 * index;
  int rightChildIndex = 2 * index + 1;
  int greaterChildIndex;
  if (ptr_[leftChildIndex] > ptr_[rightChildIndex])
    greaterChildIndex = leftChildIndex;
  else
    greaterChildIndex = rightChildIndex;
  if (ptr_[index] < ptr_[greaterChildIndex])
    std::swap(ptr_[index], ptr_[greaterChildIndex]);
  else
    srediNadole(index * 2);
}

template <typename T>
void heap<T>::print() const {
  for (int i = 1; i <= size_; ++i) std::cout << ptr_[i] << " ";
  std::cout << std::endl;
}
