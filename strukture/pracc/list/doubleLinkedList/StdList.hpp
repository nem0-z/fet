#pragma once
#include <iostream>

template <typename Elem>
class StdList {
  private:
  class Node {
public:
    Elem data_;
    Node *next_ = nullptr;
    Node *prev_ = nullptr;

    Node(Elem data = 0) : data_{data} {}
  };
  uint32_t size_;
  Node *head_;
  Node *tail_;

  public:
  StdList();
  StdList(const StdList &);
  StdList(StdList &&);
  ~StdList();

  StdList &operator=(const StdList &);
  StdList &operator=(StdList &&);

  StdList &insert(uint32_t);

  StdList &push_back(const Elem &);
  StdList &push_front(const Elem &);

  StdList &pop_back();
  StdList &pop_front();

  inline bool empty() const;
  inline uint32_t size() const;

  void print() const;
  void clear();

  class iterator;
  class const_iterator;

  iterator begin() { return iterator(nullptr, head_); }
  iterator end() { return iterator(tail_, nullptr); }

  const_iterator cbegin() { return const_iterator(nullptr, head_); }
  const_iterator cend() { return const_iterator(tail_, nullptr); }

  template <typename U>
  void transform(U unary_);

  template <typename U>
  iterator find(U predicate);

  iterator find(const Elem &item);

  void erase(iterator position);

  void splice(iterator position, StdList &other);

  void insert(iterator position, const Elem &item);

  void erase(iterator from, iterator to);
};

template <typename Elem>
StdList<Elem> &StdList<Elem>::pop_back() {
  if (!empty()) {
    if (size_ == 1) {
      delete tail_;
      tail_ = nullptr;
      head_ = nullptr;
    }
    Node *tmp = tail_->prev_;
    delete tail_;
    tail_ = tmp;
    tail_->next_ = nullptr;
  }
  --size_;
  return *this;
}

template <typename Elem>
StdList<Elem> &StdList<Elem>::pop_front() {
  if (!empty()) {
    if (size_ == 1) {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      Node *tmp = head_->next_;
      delete head_;
      head_ = tmp;
      head_->prev_ = nullptr;
    }
  }
  --size_;
  return *this;
}

template <typename Elem>
void StdList<Elem>::print() const {
  if (empty()) {
    std::cout << "Empty list!\n" << std::endl;
    return;
  }
  Node *tmp = head_;
  while (tmp) {
    std::cout << tmp->data_ << " ";
    tmp = tmp->next_;
  }
  std::cout << '\n';
}

template <typename Elem>
void StdList<Elem>::clear() {
  Node *tmp = head_;

  while (head_) {
    tmp = head_->next_;
    delete head_;
    head_ = tmp;
  }
  size_ = 0;
  head_ = nullptr;
  tail_ = nullptr;
}

template <typename Elem>
StdList<Elem>::StdList() : size_{0}, head_{nullptr}, tail_{nullptr} {}

template <typename Elem>
StdList<Elem>::StdList(const StdList &other) : size_{other.size_} {
  if (!other.empty()) {
    head_ = tail_ = new Node(other.head_->data_);
    Node *tmp = other.head_->next_;

    while (tmp) {
      Node *newNode = new Node(tmp->data_);
      newNode->prev_ = tail_;
      tail_->next_ = newNode;
      tail_ = newNode;
      tmp = tmp->next_;
    }
  }
}

template <typename Elem>
StdList<Elem>::StdList(StdList &&other)
    : size_{other.size_}, head_{other.head_}, tail_{other.tail_} {
  other.head_ = nullptr;
  other.tail_ = nullptr;
}

template <typename Elem>
StdList<Elem>::~StdList() {
  clear();
}

template <typename Elem>
StdList<Elem> &StdList<Elem>::operator=(const StdList<Elem> &other) {
  clear();
  if (!other.empty() && this != &other) {
    return *this = StdList(other);
  }
  return *this;
}

template <typename Elem>
StdList<Elem> &StdList<Elem>::operator=(StdList<Elem> &&other) {
  if (!other.empty() && this != &other) {
    clear();
    size_ = other.size_;
    head_ = other.head_;
    tail_ = other.tail_;
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }
  return *this;
}

template <typename Elem>
inline uint32_t StdList<Elem>::size() const {
  return size_;
}

template <typename Elem>
inline bool StdList<Elem>::empty() const {
  return size_ == 0;
}

template <typename Elem>
StdList<Elem> &StdList<Elem>::push_back(const Elem &item) {
  Node *toAdd = new Node(item);
  if (empty()) {
    head_ = tail_ = toAdd;
  } else if (size_ == 1) {
    head_->next_ = toAdd;
    tail_ = toAdd;
    tail_->prev_ = head_;
  } else {
    tail_->next_ = toAdd;
    toAdd->prev_ = tail_;
    tail_ = toAdd;
  }
  ++size_;
  return *this;
}
template <typename Elem>
StdList<Elem> &StdList<Elem>::push_front(const Elem &item) {
  Node *newNode = new Node(item);
  if (empty()) {
    head_ = tail_ = newNode;
  } else if (size_ == 1) {
    head_ = newNode;
    head_->next_ = tail_;
    tail_->prev_ = head_;
  } else {
    newNode->next_ = head_;
    head_->prev_ = newNode;
    head_ = newNode;
  }
  ++size_;
  return *this;
}

#include "ListConstIterator.hpp"
#include "ListIterator.hpp"

template <typename Elem>
template <typename U>
void StdList<Elem>::transform(U unary_) {
  StdList<Elem>::iterator it = begin();
  while (it != end()) {
    unary_(*it++);
  }
}

template <typename Elem>
template <typename U>
typename StdList<Elem>::iterator StdList<Elem>::find(U predicate) {
  auto it = begin();
  while (it != end()) {
    if (predicate(*it)) return it;
    ++it;
  }
  return end();
}

template <typename Elem>
typename StdList<Elem>::iterator StdList<Elem>::find(const Elem &item) {
  Node *tmp = head_;
  while (tmp) {
    if (tmp->data_ == item) return iterator(tmp->prev_, tmp);
    tmp = tmp->next_;
  }
  return end();
}

template <typename Elem>
void StdList<Elem>::erase(typename StdList<Elem>::iterator position) {
  if (position.isBegin()) {
    pop_front();
  } else if (position.isEnd()) {
    pop_back();
  } else {
    Node *toDelete = position.current;
    toDelete->prev_->next_ = toDelete->next_;
    toDelete->next_->prev_ = toDelete->prev_;
    delete toDelete;
    --size_;
  }
}

template <typename Elem>
void StdList<Elem>::splice(typename StdList<Elem>::iterator position,
                           StdList<Elem> &other) {
  if (!other.empty()) {
    if (position.isBegin()) {
      other.tail_->next_ = head_;
      head_ = other.head_;
    } else if (position.isEnd()) {
      tail_->next_ = other.head_;
      tail_ = other.tail_;
    } else {
      Node *range1 = position.previous;
      Node *range2 = position.current;
      range2->prev_ = other.tail_->next_;
      other.tail_->next_ = range2;
      range1->next_ = other.head_;
      other.head_->prev_ = range1;
    }
  }
  size_ += other.size_;
  other.head_ = nullptr;
  other.tail_ = nullptr;
  other.size_ = 0;
}

template <typename Elem>
void StdList<Elem>::insert(typename StdList<Elem>::iterator position,
                           const Elem &item) {
  if (empty())
    push_front(item);
  else if (!empty() && position.isBegin()) {
    push_front(item);
  }
  else if (!empty() && position.isEnd())
  {
      push_back(item);
  }
  else if (!empty()) {
    Node *toAdd = new Node(item);
    Node *prev = position.previous;
    Node *next = position.current;
    prev->next_ = toAdd;
    toAdd->next_ = next;
    next->prev_ = toAdd;
    toAdd->prev_ = prev;
    ++size_;
  }
}

template <typename Elem>
void StdList<Elem>::erase(typename StdList<Elem>::iterator from,
                          typename StdList<Elem>::iterator to) {
  auto tmp1 = from.current->prev_;
  auto tmp2 = to;
  while (from != to) {
    auto tmp = from.current->next_;
    delete from.current;
    from.current = tmp;
    --size_;
  }
  tmp1->next_ = tmp2.current;
  tmp2.current->prev_ = tmp1;
}
