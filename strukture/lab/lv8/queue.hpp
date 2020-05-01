#pragma once

#include <stdexcept>

template <typename T>
class Stack {
  private:
  class Node;
  Node* first_ = nullptr;
  size_t size_ = 0;

  public:
  Stack() = default;
  // copy
  // move
  // copy=
  // move=
  // ~dtor

  size_t size() const { return size_; }

  bool empty() const { return size_ == 0; }

  void push(T&& value) {
    auto node = new Node{std::move(value), first_};
    first_ = node;
    size_++;
  }

  void push(const T& value) {
    auto node = new Node{value, first_};
    first_ = node;
    size_++;
  }

  void pop() {
    if (empty()) return;
    auto temp = first_;
    first_ = first_->getNext();
    delete temp;
    size_--;
  }

  T& top() {
    if (first_ == nullptr) throw std::runtime_error("Stack is empty!");
    return first_->getValue();
  }

  const T& top() const {
    if (first_ == nullptr) throw std::runtime_error("Stack is empty!");
    return first_->getValue();
  }
};

template <typename T>
class Stack<T>::Node {
  T value_;
  Node* next_;

  public:
  Node(const T& value, Node* next) : value_{value}, next_{next} {}
  Node(T&& value, Node* next) : value_{std::move(value)}, next_{next} {}

  T& getValue() { return value_; }

  Node* getNext() { return next_; }
};

