#pragma once
#include "sorted_list.hpp"

template <typename T>
class sorted_list<T>::iterator
    : public std::iterator<std::bidirectional_iterator_tag, T> {
  public:
  iterator() = default;
  iterator(Node *prev, Node *curr) : prevIt{prev}, currentIt{curr} {}
  friend class sorted_list;

  iterator &operator++() {
    prevIt = currentIt;
    if (currentIt) {
      currentIt = currentIt->next;
    }
    return *this;
  }
  iterator operator++(int) {
    auto tmp = *this;
    ++(*this);
    return tmp;
  }
  iterator &operator--() {
    currentIt = prevIt;
    if (prevIt) {
      prevIt = prevIt->prev;
    }
    return *this;
  }
  iterator operator--(int) {
    auto tmp = *this;
    --(*this);
    return tmp;
  }

  T &operator*() { return currentIt->data_; }

  const T &operator*() const { return currentIt->data_; }

  bool operator==(const iterator &other) const {
    return other.currentIt == currentIt;
  }

  bool operator!=(const iterator &other) const {
    return other.currentIt != currentIt;
  }

  bool checkBegin() const{
    return currentIt != nullptr && prevIt == nullptr;
  }

  bool checkEnd() const{
    return currentIt == nullptr && prevIt != nullptr;
  }


  private:
  Node *prevIt = nullptr;
  Node *currentIt = nullptr;
};
