#pragma once
#include <cstddef>
#include <iostream>

template <typename T>
class sorted_list {
  public:
  sorted_list();
  sorted_list(const sorted_list &);
  sorted_list(sorted_list &&);
  ~sorted_list();

  sorted_list &operator=(const sorted_list &);
  sorted_list &operator=(sorted_list &&);

  class iterator;
  iterator begin();
  iterator end();

  template <typename F>
  void add(F &&);
  iterator find(const T &);
  template <typename UnaryOpt>
  iterator find_if(const UnaryOpt &);

  void remove(const iterator &);
  void removeId(int);

  inline size_t size() const;
  inline bool empty() const;
  void clear();

  T &front() const;
  T &back() const;

  void print() const;  // debugging

  private:
  class Node {
public:
    T data_{};
    Node *next = nullptr;
    Node *prev = nullptr;
    Node(const T &data) : data_{data} {}
  };
  Node *head_ = nullptr;
  Node *tail_ = nullptr;
  size_t size_ = 0;
};

#include "sorted_list-impl.hpp"
