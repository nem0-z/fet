#pragma once

/* Forward list implementation
 * Mostly stl compatible.
 */
#include <cstddef>     // for size_t
#include <functional>  // for comparison function
#include <iterator>    // for iterator tag
#include <utility>     // for std::move

#include "node.hpp"

template <typename T>
class forward_list {
  public:
  forward_list();                       // Default constructor
  forward_list(const forward_list& x);  // Copy constructor
  forward_list(forward_list&& x);       // Move constructor
  const forward_list& operator=(const forward_list& x);
  const forward_list& operator=(forward_list&& x);
  ~forward_list();  // Destructor

  // Returns the number of elements in the list container.
  inline size_t size() const { return size_; }
  // Returns whether the list is empty.
  inline bool empty() const { return size_ == 0; };

  // Deallocate all nodes from the list, leaving it empty for further use
  void clear();

  // Adds a new element at the end of the list, allocating a new node where
  // the content of val is copied (or moved) to the new element.
  void push_back(const T& val);

  // Adds a new element at the beginning of the list. The content of val is
  // copied (or moved) to the new element.
  void push_front(const T& elem);

  // Remove the last element from the list. Leaves unchanged if list is empty
  void pop_back();

  // Remove the first element from the list. Leaves unchanged if the list is
  // empty
  void pop_front();

  // Element access
  // Returns a reference to the first element in list. Does not to
  // existance checking, so calling it on an empty list causes seg fault.
  inline T& front() { return first_->value; }
  inline const T& front() const { return first_->value; }

  // Returns a reference to the last item in the list. Does not to existance
  // checking, so calling it on an empty list causes seg fault.
  T& back() { return last_->value; }
  const T& back() const { return last_->value; }

  private:
  Node<T>* first_;  // Pointer to the first element of list
  Node<T>* last_;   // Pointer to the last element of list
  size_t size_;     // Number of elements in list
};

/* clears all the elements from the list. */
template <typename T>
void forward_list<T>::clear() {
  Node<T>* tmp = first_;
  while (tmp) {
    first_ = first_->next;
    delete tmp;
    tmp = first_;
  }
  size_ = 0;
  first_ = nullptr;
  last_ = nullptr;
}

/* Adds a new node with the desired vaule to the end of the list. */
template <typename T>
void forward_list<T>::push_back(const T& val) {
  Node<T>* newNode = new Node<T>(val);
  if (empty()) {
    first_ = last_ = newNode;
  } else {
    last_->next = newNode;
    last_ = newNode;
  }
  ++size_;
}

/* Adds a new node with the desired vaule to the end of the list. */
template <typename T>
void forward_list<T>::push_front(const T& val) {
  Node<T>* newNode = new Node<T>(val);
  if (empty()) {
    first_ = last_ = newNode;
  } else {
    newNode->next = first_;
    first_ = newNode;
  }
  ++size_;
}

/* Removes the last node form the list.
 * O(n) complexity, be aware.
 * If the list is empty does nothing.
 */
template <typename T>
void forward_list<T>::pop_back() {}

/* Removes the first node form the list.
 * O(1) complexity, prefer it in the code over the push_back.
 * If the list is empty does nothing.
 */
template <typename T>
void forward_list<T>::pop_front() {}

// Default constructor
template <typename T>
forward_list<T>::forward_list() : first_{nullptr}, last_{nullptr}, size_{0} {}

// Copy constructor
template <typename T>
forward_list<T>::forward_list(const forward_list& rhs)
    : first_{nullptr}, last_{nullptr}, size_{rhs.size_} {
  if (!rhs.empty()) {
    first_ = last_ = new Node<T>(rhs.first_->value);
    Node<T>* tmp = rhs.first_->next;
    while (tmp) {
      Node<T>* newNode = new Node<T>(tmp->value);
      last_->next = newNode;
      last_ = newNode;
      tmp = tmp->next;
    }
  }
}

// Move constructor
template <typename T>
forward_list<T>::forward_list(forward_list&& rhs)
    : first_{rhs.first_}, last_{rhs.last_}, size_{rhs.size_} {
  rhs.first_ = nullptr;
  rhs.last_ = nullptr;
  rhs.size_ = 0;  // ovo je setovano sve na 0 jer ce se rvalue rhs brisati odma
                  // nakon toga
  // destruktor tj nas metod clear se oslanja na ove pointere i size tako da bi
  // se moglo nesto zeznut ako ih ne setujemo rucno na null values
}

// Destructor
template <typename T>
forward_list<T>::~forward_list() {
  clear();
}

// The copy assignment and move operators
template <typename T>
const forward_list<T>& forward_list<T>::operator=(const forward_list& rhs) {
  clear();
  if (!rhs.empty()) {
    first_ = last_ = new Node<T>(rhs.first_->value);
    Node<T>* tmp = rhs.first_->next;
    while (tmp) {
      Node<T>* newNode = new Node<T>(tmp->value);
      last_->next = newNode;
      last_ = newNode;
      tmp = tmp->next;
    }
  }
  return *this;
}

template <typename T>
const forward_list<T>& forward_list<T>::operator=(forward_list&& rhs) {
  clear();
  first_ = rhs.first_;
  last_ = rhs.last_;
  size_ = rhs.size_;

  rhs.first_ = nullptr;
  rhs.last_ = nullptr;
  rhs.size_ = 0;
}
