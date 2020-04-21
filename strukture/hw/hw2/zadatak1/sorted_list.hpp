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

  class iterator;  // bice friend i bidirekcioni je
  iterator begin();
  iterator end();
  iterator find(const T &);
  template <typename UnaryOpt>
  iterator find_if(const UnaryOpt &);

  template <typename F>
  void add(F &&);                 // yup
  void remove(const iterator &);  // pazi na corner caseove
  void print() const;             // debugging

  inline size_t size() const;
  inline bool empty() const;
  void clear();

  inline T &front();
  inline T &back();
  inline const T &front() const;
  inline const T &back() const;

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
