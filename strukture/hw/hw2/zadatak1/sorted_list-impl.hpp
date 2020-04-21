#pragma once
#include "iterator.hpp"
#include "sorted_list.hpp"

template <typename T>
sorted_list<T>::sorted_list() = default;

template <typename T>
sorted_list<T>::sorted_list(const sorted_list &other) : size_{other.size_} {
  if (!other.empty()) {
    head_ = new Node(other.head_->data_);
    Node *otherTmp = other.head_->next;
    Node *tmp = head_;
    while (otherTmp) {
      Node *toAdd = new Node(otherTmp->data_);
      tmp->next = toAdd;
      toAdd->prev = tmp;
      otherTmp = otherTmp->next;
      tmp = tmp->next;
    }
    tail_ = tmp->prev;
  } else {
    head_ = tail_ = nullptr;
  }
}

template <typename T>
sorted_list<T>::sorted_list(sorted_list &&other)
    : head_{other.head_}, tail_{other.tail_}, size_{other.size_} {
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;
}

template <typename T>
sorted_list<T>::~sorted_list() {
  clear();
}

template <typename T>
sorted_list<T> &sorted_list<T>::operator=(const sorted_list<T> &other) {
  if (this != &other) {
    clear();
    *this = sorted_list(other);
  }
  return *this;
}

template <typename T>
sorted_list<T> &sorted_list<T>::operator=(sorted_list<T> &&other) {
  if (this != &other) {
    clear();
    size_ = other.size_;
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename T>
typename sorted_list<T>::iterator sorted_list<T>::begin() {
  return iterator(nullptr, head_);
}

template <typename T>
typename sorted_list<T>::iterator sorted_list<T>::end() {
  return iterator(tail_, nullptr);
}

template <typename T>
typename sorted_list<T>::iterator sorted_list<T>::find(const T &value) {
  auto it = begin();
  while (it != end()) {
    if (*it == value) return it;
    ++it;
  }
  return end();
}

template <typename T>
template <typename UnaryOpt>
typename sorted_list<T>::iterator sorted_list<T>::find_if(
    const UnaryOpt &predicate) {
  auto it = begin();
  while (it != end()) {
    if (predicate(*it)) {
      return it;
    }
    ++it;
  }
  return end();
}

template <typename T>
template <typename F>
void sorted_list<T>::add(F &&value) {
  Node *toAdd = new Node(std::forward<T>(value));

  // If list is empty, add it as one and only element
  if (empty()) {
    head_ = tail_ = toAdd;
  }

  // If value is new minimum add it at the front
  else if (value < front()) {
    head_->prev = toAdd;
    toAdd->next = head_;
    head_ = toAdd;
  }
  // If value is new maximum add it at the back
  else if (value > back()) {
    tail_->next = toAdd;
    toAdd->prev = tail_;
    toAdd->next = nullptr;
    tail_ = toAdd;
  }

  // Else iterate through list until we find place for it
  else {
    Node *tmp = head_;
    while (tmp) {
      // If greater then element just move on
      if (value > tmp->data_) {
        tmp = tmp->next;
      } else {
        Node *prevNode = tmp->prev;
        prevNode->next = toAdd;
        toAdd->prev = prevNode;
        toAdd->next = tmp;
        tmp->prev = toAdd;
        break;
      }
    }
  }
  ++size_;
}

//
template <typename T>
void sorted_list<T>::remove(const typename sorted_list<T>::iterator &iter) {
  // std::list lets us dereference end iterator
  // We are better than std::list (we are not :D)
  if (iter.checkEnd()) throw std::out_of_range("Invalid iterator.");

  // If size is 1 just clear so we don't bother with aftermath
  if (size_ == 1) {
    clear();
    return;
  }

  // If removing begin then update head
  if (iter.checkBegin()) {
    Node *tmpHead = head_->next;
    delete head_;
    head_ = tmpHead;
    head_->prev = nullptr;
  } else {
    Node *prev = iter.prevIt;
    Node *current = iter.currentIt;
    Node *tmpNext = current->next;
    // If removing --end() then update tail
    if (tmpNext) {
      prev->next = tmpNext;
      tmpNext->prev = prev;
    } else {
      tail_ = prev;
      tail_->next = nullptr;
    }
    delete current;
  }
  --size_;
}

template <typename T>
void sorted_list<T>::print() const {
  if (empty()) {
    printf("Empty list!\n");
    return;
  }
  Node *tmp = head_;
  while (tmp) {
    std::cout << tmp->data_ << " ";
    tmp = tmp->next;
  }
  printf("\n");
}

template <typename T>
inline size_t sorted_list<T>::size() const {
  return size_;
}

template <typename T>
inline bool sorted_list<T>::empty() const {
  return size_ == 0;
}

template <typename T>
void sorted_list<T>::clear() {
  if (!empty()) {
    Node *tmp;
    while (head_) {
      tmp = head_->next;
      delete head_;
      head_ = tmp;
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  }
}

template <typename T>
inline T &sorted_list<T>::front() {
  return head_->data_;
}

template <typename T>
inline T &sorted_list<T>::back() {
  return tail_->data_;
}

template <typename T>
inline const T &sorted_list<T>::front() const {
  return head_->data_;
}

template <typename T>
inline const T &sorted_list<T>::back() const {
  return tail_->data_;
}

