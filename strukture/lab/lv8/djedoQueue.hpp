#pragma once
#include <cstddef>
#include <iostream>
#include "node.hpp"

template <typename T>
class queue {
  private:
  Node<T> *first_ = nullptr;
  Node<T> *last_ = nullptr;
  size_t size_ = 0;

  public:
  queue() = default;
  queue(const queue &);
  queue(queue &&);
  ~queue();

  queue &operator=(const queue &);
  queue &operator=(queue &&);

  template <typename U>
  void push(U &&);
  T &top();
  const T &top() const;

  size_t size() const;
  bool empty() const;
  void print() const;
  void pop();
};

template <typename T>
void queue<T>::print() const {
  Node<T> *tmp = first_;
  while (tmp) {
    std::cout << tmp->value << " ";
    tmp = tmp->next;
  }
  std::cout << '\n';
}

template <typename T>
queue<T>::queue(const queue<T> &other) : size_{other.size_} {
  if (!empty()) {
    first_ = new Node<T>(other.first_->value);
    Node<T> *tmp = other.first_->next;
    Node<T> *last = first_;

    while (tmp) {
      last->next = new Node<T>(tmp->value);
      tmp = tmp->next;
      last = last->next;
    }
  }
}

template <typename T>
queue<T>::queue(queue<T> &&other) : size_{other.size_}, first_{other.first_} {
  other.first_ = nullptr;
}

template <typename T>
queue<T> &queue<T>::operator=(const queue<T> &other) {
  if (!empty()) {
    while (first_) {
      Node<T> *tmp = first_;
      first_ = first_->next;
      delete tmp;
    }
  }  // isto sve kao i copy constructor samo sto moramo brisati

  if (!empty()) {
    first_ = new Node<T>(other.first_->value);
    Node<T> *tmp = other.first_->next;
    Node<T> *last = first_;

    while (tmp) {
      last->next = new Node<T>(tmp->value);
      tmp = tmp->next;
      last = last->next;
    }
  }
  return *this;
}

template <typename T>
queue<T> &queue<T>::operator=(queue<T> &&other) {
  if (!empty()) {
    while (first_) {
      Node<T> *tmp = first_;
      first_ = first_->next;
      delete tmp;
    }
  }  // isto sve kao i move constructor samo sto moramo brisati
  size_ = other.size_;
  first_ = other.first_;
  other.first_ = nullptr;
  return *this;
}

template <typename T>
queue<T>::~queue<T>() {
  if (!empty()) {
    while (first_) {
      Node<T> *tmp = first_;
      first_ = first_->next;
      delete tmp;
    }
  }
}

template <typename T>
template <typename U>
void queue<T>::push(U &&val) {
  Node<T> *newNode = new Node<T>{std::forward<U>(val)};
  if (empty()) {
    first_ = last_ = newNode;
  } else {
    last_->next = newNode;
    last_ = newNode;
  }
  newNode = nullptr;
  ++size_;
}

// we add on queue from top
// push 5, 10, 20
// queue: 20,10,5

template <typename T>
T &queue<T>::top() {
  return first_->value;
}

template <typename T>
const T &queue<T>::top() const {
  return first_->value;
}

template <typename T>
size_t queue<T>::size() const {
  return size_;
}

template <typename T>
bool queue<T>::empty() const {
  return size_ == 0;
}

template <typename T>
void queue<T>::pop() {
  if (!empty()) {
    Node<T> *tmp = first_;
    first_ = first_->next;
    delete tmp;
    --size_;
  }
}
