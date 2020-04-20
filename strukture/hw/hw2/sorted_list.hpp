#pragma once
#include <cstddef>
#include <iostream>

using std::cout;

template <typename T>
class sorted_list
{

public:
  sorted_list();
  sorted_list(const sorted_list &);
  sorted_list(sorted_list &&);
  ~sorted_list();

  sorted_list &operator=(const sorted_list &);
  sorted_list &operator=(sorted_list &&);

  class iterator; //bice friend i bidirekcioni je
  iterator begin();
  iterator end();

  // void add(const T &);
  // void add(T &&); //probati sa forward referencom no?

  template <typename F>
  void add(F &&); //yup

  iterator find(const T &); //vraca iterator na pronadjeni ako nije naso onda end
  template <typename UnaryOpt>
  iterator find_if(const UnaryOpt &);

  void remove(const iterator &); //pazi na corner caseove

  inline size_t size() const;
  inline bool empty() const;
  void clear();

  T &front() const;
  T &back() const;

  void print() const; //debugging

private:
  class Node
  {
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