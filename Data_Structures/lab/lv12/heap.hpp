#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <utility>

template <typename T>
class heap {
  public:
  heap(size_t c = 10);
  ~heap();
  // add copy and move ctor and op=

  size_t size() const { return size_ - 1; }
  bool empty() const { return size_ == 1; }
  bool full() const { return size_ - 1 == capacity_; }

  template <typename U>
  void insert(U&& value);

  void printHeap() const;

  T extractMax();

  private:
  size_t capacity_;
  size_t size_;
  T* heap_;
  void expandHeap();
  void fixBelowIndex(size_t i);
};

template <typename T>
heap<T>::heap(size_t c) : capacity_{c}, size_{1}, heap_{new T[capacity_]} {}

template <typename T>
heap<T>::~heap() {
  delete[] heap_;
  size_ = 0;
  capacity_ = 0;
  heap_ = nullptr;
}

template <typename T>
template <typename U>
void heap<T>::insert(U&& value) {
  if (full()) {
    expandHeap();
  }
  int index = size_;
  heap_[index] = std::forward<U>(value);
  while (index != 1) {
    int parentIndex = index / 2;
    if (heap_[index] > heap_[parentIndex]) {
      std::swap(heap_[index], heap_[parentIndex]);
      index = parentIndex;
    } else
      break;
  }
  ++size_;
}

template <typename T>
void heap<T>::expandHeap() {
  capacity_ *= 2;
  T* tmp = new T[capacity_];
  for (int i = 0; i < size_; ++i) tmp[i] = std::move(heap_[i]);
  delete[] heap_;
  heap_ = tmp;
}

template <typename T>
void heap<T>::printHeap() const {
  for (int i = 1; i < size_; ++i) std::cout << heap_[i] << " ";
  std::cout << std::endl;
}

template <typename T>
T heap<T>::extractMax() {
  if (empty()) throw std::out_of_range("Heap is empty.");
  T max = std::move(heap_[1]);             // return value
  heap_[1] = std::move(heap_[size_ - 1]);  // swap with last
  fixBelowIndex(1);
  --size_;
  return max;
}

template <typename T>
void heap<T>::fixBelowIndex(size_t i) {
  size_t leftChildIndex = 2 * i;
  size_t rightChildIndex = 2 * i + 1;
  size_t maxValueIndex = i;
  if (leftChildIndex < size_ && heap_[leftChildIndex] > heap_[maxValueIndex])
    maxValueIndex = leftChildIndex;
  if (rightChildIndex < size_ && heap_[rightChildIndex] > heap_[maxValueIndex])
    maxValueIndex = rightChildIndex;
  if (maxValueIndex != i) {
    // leftChild ili rightChild ima vecu vrijednost nego trenutni index odnosno
    // treba ga plasirati negdje drugo
    std::swap(heap_[i], heap_[maxValueIndex]);
    fixBelowIndex(maxValueIndex);
  }
}
