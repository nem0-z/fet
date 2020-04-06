#pragma once

#include <utility>

template <typename T>
class Node {
  public:
  T value;
  Node* next = nullptr;

  Node(const T& val, Node* n = nullptr) : value{val}, next{n} {};
  Node(T&& val, Node* n = nullptr) : value{std::move(val)}, next{n} {};
};
