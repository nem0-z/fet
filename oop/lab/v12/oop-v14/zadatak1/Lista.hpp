#pragma once
#include <iostream>
#include <vector>

namespace V12 {

namespace Details {

  template<typename T>
struct Node {
  T value;
  Node* next;
};

}  // namespace Details

template<typename T>
class Lista {
  using Node = Details::Node<T>;

 public:
  Lista() = default;
  Lista(const Lista&);
  Lista(Lista&&);

  Lista& operator=(const Lista&);
  Lista& operator=(Lista&&);
  template<typename A>
  Lista& operator=(const std::vector<A>&);
  template<typename A>
  Lista operator+(const std::vector<A>&) const;

  void push_back(T val);

  void print() const;

 private:
  Node* poc_ = nullptr;
  void destroy();
  void copy(const Lista&);
  template<typename A>
  void copy(const std::vector<A>&);
};

}  // namespace V12

#include "Lista.hxx"
