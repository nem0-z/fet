#pragma once

/* Forward list implementation
 * Mostly stl compatible.
 */
#include <cstddef>    // for size_t
#include <functional> // for comparison function
#include <iterator>   // for iterator tag
#include <utility>    // for std::move

#include "node.hpp"

template <typename T>
class forward_list
{
public:
  forward_list();                      // Default constructor
  forward_list(const forward_list &x); // Copy constructor
  forward_list(forward_list &&x);      // Move constructor
  const forward_list &operator=(const forward_list &x);
  const forward_list &operator=(forward_list &&x);
  ~forward_list(); // Destructor

  // Returns the number of elements in the list container.
  inline size_t size() const { return size_; }
  // Returns whether the list is empty.
  inline bool empty() const { return size_ == 0; };

  // Deallocate all nodes from the list, leaving it empty for further use
  void clear();

  // Adds a new element at the end of the list, allocating a new node where
  // the content of val is copied (or moved) to the new element.
  void push_back(const T &val);

  // Adds a new element at the beginning of the list. The content of val is
  // copied (or moved) to the new element.
  void push_front(const T &elem);

  // Remove the last element from the list. Leaves unchanged if list is empty
  void pop_back();

  // Remove the first element from the list. Leaves unchanged if the list is
  // empty
  void pop_front();

  // Element access
  // Returns a reference to the first element in list. Does not to
  // existance checking, so calling it on an empty list causes seg fault.
  inline T &front() { return first_->value; }
  inline const T &front() const { return first_->value; }

  // Returns a reference to the last item in the list. Does not to existance
  // checking, so calling it on an empty list causes seg fault.
  T &back() { return last_->value; }
  const T &back() const { return last_->value; }

  class Iterator;
  Iterator begin();
  Iterator end();

  // Zadatak 1)
  template <typename U>
  void transform(U predicate);

  // Zadatak 2)
  template <typename U>
  Iterator find(U predicate);
  Iterator find(const T &val);

  // Zadatak 3)
  void erase(Iterator it);

  // Zadatak 4)
  void splice(Iterator position, forward_list &other);

private:
  Node<T> *first_; // Pointer to the first element of list
  Node<T> *last_;  // Pointer to the last element of list
  size_t size_;    // Number of elements in list
};

/* clears all the elements from the list. */
template <typename T>
void forward_list<T>::clear()
{
  Node<T> *tmp = first_;
  while (tmp)
  {
    first_ = first_->next;
    delete tmp;
    tmp = first_;
  }
  size_ = 0;
  last_ = nullptr;
  first_ = nullptr;
}

/* Adds a new node with the desired vaule to the end of the list. */
template <typename T>
void forward_list<T>::push_back(const T &val)
{
  Node<T> *newNode = new Node<T>(val);
  if (empty())
  {
    first_ = last_ = newNode;
  }
  else
  {
    last_->next = newNode;
    last_ = newNode;
  }
  ++size_;
}

/* Adds a new node with the desired vaule to the end of the list. */
template <typename T>
void forward_list<T>::push_front(const T &val)
{
  Node<T> *newNode = new Node<T>(val);
  if (empty())
  {
    first_ = last_ = newNode;
  }
  else
  {
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
forward_list<T>::forward_list(const forward_list &rhs)
    : first_{nullptr}, last_{nullptr}, size_{rhs.size_}
{
  if (!rhs.empty())
  {
    first_ = last_ = new Node<T>(rhs.first_->value);
    Node<T> *tmp = rhs.first_->next;
    while (tmp)
    {
      Node<T> *newNode = new Node<T>(tmp->value);
      last_->next = newNode;
      last_ = newNode;

      tmp = tmp->next;
    }
  }
}

// Move constructor
template <typename T>
forward_list<T>::forward_list(forward_list &&rhs)
    : first_{rhs.first_}, last_{rhs.last_}, size_{rhs.size_}
{
  rhs.first_ = nullptr;
  rhs.last_ = nullptr;
  rhs.size_ = 0;
}

// Destructor
template <typename T>
forward_list<T>::~forward_list()
{
  clear();
}

// The copy assignment and move operators
template <typename T>
const forward_list<T> &forward_list<T>::operator=(const forward_list &rhs)
{
  clear();
  if (!rhs.empty())
  {
    first_ = last_ = new Node<T>(rhs.first_->value);
    Node<T> *tmp = rhs.first_->next;
    while (tmp)
    {
      Node<T> *newNode = new Node<T>(tmp->value);
      last_->next = newNode;
      last_ = newNode;

      tmp = tmp->next;
    }
  }
  return *this;
}

template <typename T>
const forward_list<T> &forward_list<T>::operator=(forward_list &&rhs)
{
  clear();
  first_ = rhs.first_;
  last_ = rhs.last_;
  size_ = rhs.size_;

  rhs.first_ = nullptr;
  rhs.last_ = nullptr;
  rhs.size_ = 0;
  return *this;
}

template <typename T>
class forward_list<T>::Iterator
{
public:
  Iterator() = default;
  Iterator(Node<T> *prevNode, Node<T> *myNode)
      : prevNode_{prevNode}, myNode_{myNode} {}

  Iterator &operator++()
  {
    prevNode_ = myNode_;
    if (myNode_)
      myNode_ = myNode_->next;
    return *this;
  }

  Iterator operator++(int)
  {
    auto oldThis = *this;
    ++(*this);
    return oldThis;
  }

  T &operator*() { return myNode_->value; }
  const T &operator*() const { return myNode_->value; }

  bool operator==(const Iterator &other) const
  {
    return myNode_ == other.myNode_;
  }

  bool operator!=(const Iterator &other) const { return !operator==(other); }

  bool isBegin() const { return prevNode_ == nullptr && myNode_ != nullptr; }
  bool isEnd() const { return prevNode_ != nullptr && myNode_ == nullptr; }

  friend class forward_list;

private:
  Node<T> *myNode_ = nullptr;
  Node<T> *prevNode_ = nullptr;
};

template <typename T>
typename forward_list<T>::Iterator forward_list<T>::begin()
{
  return Iterator(nullptr, first_);
}

template <typename T>
typename forward_list<T>::Iterator forward_list<T>::end()
{
  return Iterator(last_, nullptr);
}

// Zadatak 1)
template <typename T>
template <typename U>
void forward_list<T>::transform(U predicate)
{
  // auto it = begin();
  // while (it != end())
  // {
  //   predicate(*it);
  //   ++it;
  // }
  Node<T> *tmp = first_;
  while (tmp)
  {
    predicate(tmp->value);
    tmp = tmp->next;
  }
}

// Zadatak 2)
template <typename T>
template <typename U>
typename forward_list<T>::Iterator forward_list<T>::find(U predicate)
{
  auto it = begin();
  while (it != end())
  {
    if (predicate(*it))
      return it;
    ++it;
  }
  return end();
}

// Zadatak 2)
template <typename T>
typename forward_list<T>::Iterator forward_list<T>::find(const T &value)
{
  Node<T> *tmp = first_;
  Node<T> *tmp_previous = nullptr;
  while (tmp)
  {
    if (tmp->value == value)
      return Iterator(tmp_previous, tmp);
    tmp_previous = tmp;
    tmp = tmp->next;
  }
  return end();
}

// Zadatak 3)
template <typename T>
void forward_list<T>::erase(forward_list<T>::Iterator position)
{
  Node<T> *nodeToDelete = position.myNode_;
  if (position == begin())
  {
    first_ = first_->next;
  }
  else if (position.myNode_ == last_)
  {
    last_ = position.prevNode_;
    if (last_ != nullptr)
      last_->next = nullptr;
  }
  else
  {
    Node<T> *previousNode = position.prevNode_;
    Node<T> *nextNode = nodeToDelete->next;
    previousNode->next = nextNode;
  }
  delete nodeToDelete;
  --size_;

  //u slucaju da brisemo clan sa pocetka, previousNode ce bit nullptr
  //i ovde cemo ga dereferencirati sto nam daje segfault (dodan kasnije gore if statement)

  //sta ako brisemo zadnji

  //poslije ovoga su iteratori invalidirani
  //bas radi ovih prebacivanja tako da ne mozemo biti sigurni
  //da ce pokazivati idalje na isto
}

// Zadatak 4)
template <typename T>
void forward_list<T>::splice(Iterator position, forward_list<T> &otherList)
{
  if (otherList.empty())
  {
    return;
    //ovo je tu jer ako je otherList prazna nema sta radit
    //dzaba bi sebi napravili problem opet bi derefencirali nullptr
    //ista prica je i za splice na begin
  }
  else if (position == begin())
  {
    first_ = otherList.first_;
    otherList.last_->next = position.myNode_;
  }
  else if (position == end())
  {
    position.prevNode_->next = otherList.first_;
    last_ = otherList.last_;
  }
  else
  {
    Node<T> *otherListFirst = otherList.first_;
    Node<T> *otherListLast = otherList.last_;
    Node<T> *it = position.myNode_;

    Node<T> *current = position.myNode_;
    Node<T> *previous = position.prevNode_;

    previous->next = otherListFirst;
    otherListLast->next = current;
  }
  size_ += otherList.size_;
  otherList.first_ = nullptr;
  otherList.last_ = nullptr;
  otherList.size_ = 0;
}
