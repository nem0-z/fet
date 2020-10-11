#pragma once
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename T>
class queue {
  public:
  queue();
  queue(const queue&);
  queue(queue&&);
  ~queue();

  bool empty() const { return size_ == 0; }
  bool full() const { return size_ == capacity_; }
  size_t size() const { return size_; }

  template <typename U>
  void enqueue(U&& value);
  void dequeue();

  T& front() { return elements_[lo_]; }

  private:
  size_t capacity_ = 10;
  size_t size_ = 0;
  int lo_ = -1;
  int hi_ = -1;
  T* elements_;
  void reserve();
};

template <typename T>
queue<T>::queue() : elements_{new T[capacity_]} {}

template <typename T>
queue<T>::~queue() {
  delete[] elements_;
}

template <typename T>
template <typename U>
void queue<T>::enqueue(U&& value) {
  if (empty()) lo_ = 0;
  if (full()) reserve();
  hi_ = (hi_ + 1) % capacity_;
  elements_[hi_] = std::forward<U>(value);
  ++size_;
}

template <typename T>
void queue<T>::dequeue(){
  if(!empty()){
    lo_ = (lo_+1)%capacity_;
    --size_;
  }
}

template <typename T>
void queue<T>::reserve() {
  capacity_ *= 2;
  T* tmp = new T[capacity_];
  std::copy(elements_ + lo_, elements_ + (capacity_ / 2), tmp);
  if (lo_ > hi_)
    std::copy(elements_, elements_ + hi_ - 1, tmp + (capacity_ / 2) - lo_);
  delete[] elements_;
  tmp = elements_;
}
