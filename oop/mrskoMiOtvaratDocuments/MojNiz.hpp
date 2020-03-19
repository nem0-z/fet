#pragma once
#include <algorithm>
#include <initializer_list>
#include <iostream>

template <typename T>
struct MojNiz {
  size_t capacity_ = 1;
  size_t arraySize = 0;
  T* ptr = nullptr;

  MojNiz() : ptr{new T[capacity_]} {}
  MojNiz(std::initializer_list<T> init)
      : capacity_{init.size()}, arraySize{capacity_}, ptr{new T[capacity_]} {
    std::copy(init.begin(), init.end(), ptr);
  }
  MojNiz(const MojNiz& o)
      : capacity_{o.capacity_}, arraySize{o.arraySize}, ptr{new T[capacity_]} {
    std::copy(o.ptr, o.ptr + arraySize, ptr);
  }
  MojNiz(MojNiz&& o)
      : capacity_{o.capacity_}, arraySize{o.arraySize}, ptr{new T[capacity_]} {
    o.capacity_ = 0;
    o.arraySize = 0;
    o.ptr = nullptr;
  }
  MojNiz& operator=(const MojNiz& o) {
    delete [] ptr;
    capacity_ = o.capacity_;
    arraySize = o.arraySize;
    ptr = new T[capacity_];
    std::copy(o.ptr, o.ptr + arraySize, ptr);
    return *this;
  }
  MojNiz& operator=(MojNiz&& o) {
    delete [] ptr;
    capacity_ = o.capacity_;
    arraySize = o.arraySize;
    ptr = o.ptr;
    o.ptr = nullptr;
    o.arraySize = 0;
    o.capacity_ = 0;
    return *this;
  }
  ~MojNiz() { delete[] ptr; }

  T& operator[](int pos) const { return ptr[pos]; }
  size_t size() const { return arraySize; }
  T& at(int pos) const {
    if (pos >= arraySize) throw std::domain_error("ok");
    return ptr[pos];
  }

  // state
};
