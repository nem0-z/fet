#pragma once
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class heap {
  public:
  heap();
  heap(const std::initializer_list<T>&);
  heap(const heap&);
  heap(heap&&);
  ~heap();

  heap& operator=(const heap&);
  heap& operator=(heap&&);

  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }

  template <typename U>
  void insert(U&&);
  T pop();

  void print() const;
  void make_heap();

  private:
  T* ptr_;
  size_t size_;
  void srediNadole(int);
  void srediNadoleIterativno(int);
  void srediNagore(int);
};

template <typename T>
heap<T>::heap() : ptr_{new T[100]}, size_{0} {}

template <typename T>
heap<T>::heap(const std::initializer_list<T>& initList)
    : size_{initList.size()}, ptr_{new T[100]} {
  std::copy(initList.begin(), initList.end(), ptr_ + 1);
  make_heap();
}

template <typename T>
heap<T>::~heap() {
  delete[] ptr_;
}

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
  if (2 * index > size_) return;
  int leftChildIndex = 2 * index;
  int rightChildIndex = 2 * index + 1;
  int greaterChildIndex = rightChildIndex;
  if (ptr_[leftChildIndex] > ptr_[rightChildIndex])
    greaterChildIndex = leftChildIndex;
  if (ptr_[index] < ptr_[greaterChildIndex]) {
    print();
    std::swap(ptr_[index], ptr_[greaterChildIndex]);
  }
  srediNadole(greaterChildIndex);
}

template <typename T>
void heap<T>::srediNadoleIterativno(int index) {
  while (2 * index <= size_) {
    int child = 2 * index;
    if (ptr_[child] < ptr_[child + 1]) ++child;
    if (ptr_[index] > ptr_[child])
      break;
    else {
      std::swap(ptr_[index], ptr_[child]);
      print();
    }
    index = child;
  }
}
template <typename T>
void heap<T>::print() const {
  for (int i = 1; i <= size_; ++i) std::cout << ptr_[i] << " ";
  std::cout << std::endl;
}

template <typename T>
void heap<T>::make_heap() {
  for (int i = size_ / 2; i >= 1; --i) {
    // srediNadoleIterativno(i);
    srediNadole(i);
  }
}
