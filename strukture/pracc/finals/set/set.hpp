#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stack>
#include <stdexcept>
#include <utility>

template <typename T>
class set {
  public:
  set();
  set(const set&);
  set(set&&);
  set& operator=(const set&);
  set& operator=(set&&);
  ~set();

  bool find(const T&);
  template <typename U>
  void insert(U&&);
  void erase(const T&);
  void print() const;         // all 3 traversals
  void printS() const;        // all 3 traversals with help of stack
  void breadthLevel() const;  // breadthLevel traversal
  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }
  void clear();

  private:
  class Node {
public:
    T data_;
    Node* leftChild_ = nullptr;
    Node* rightChild_ = nullptr;
    template <typename U>
    Node(U&& val) {
      data_ = std::forward<U>(val);
    }
  };
  Node* root_ = nullptr;
  size_t size_;
  template <typename U>
  void addNode(Node*&, U&&);
  bool findNode(Node*, const T&);
  void printInorder(Node*) const;
  void printPostorder(Node*) const;
  void postOrder(Node*) const;
  void clearNode(Node*);
  void copyNode(Node*, Node*&);
};

template <typename T>
void set<T>::clearNode(Node* root) {
  if (!root) return;
  clearNode(root->leftChild_);
  clearNode(root->rightChild_);
  delete root;
}

template <typename T>
void set<T>::clear() {
  clearNode(root_);
  root_ = nullptr;
  size_ = 0;
}

template <typename T>
void set<T>::copyNode(Node* oldNode, Node*& newNode) {
  if (!oldNode) return;
  newNode = new Node(oldNode->data_);
  copyNode(oldNode->leftChild_, newNode->leftChild_);
  copyNode(oldNode->rightChild_, newNode->rightChild_);
}

template <typename T>
set<T>::set(const set& other) : size_{other.size_} {
  copyNode(other.root_, root_);
}

template <typename T>
set<T>::set(set&& other) : size_{other.size_}, root_{other.root_}{
  other.root_ = nullptr;
}

template <typename T>
set<T>& set<T>::operator=(const set& other){
  if(this!=&other){
    clear();
    copyNode(other.root_,root_);
    size_ = other.size_;
  }
  return *this;
}

template <typename T>
set<T>& set<T>::operator=(set&& other){
  if(this!=&other){
    clear();
    root_ = other.root_;
    size_ = other.size_;
    other.root_ = nullptr;
    other.size_ = 0;
  }
  return *this;
}

template <typename T>
set<T>::set() : size_{0} {}

template <typename T>
set<T>::~set() {
  clearNode(root_);
  root_ = nullptr;
  size_ = 0;
}

template <typename T>
bool set<T>::find(const T& toFind) {
  if (empty()) throw std::out_of_range("Nisi ti dobar druze");
  return findNode(root_, toFind);
}

template <typename T>
bool set<T>::findNode(Node* root, const T& toFind) {
  if (!root) return false;
  if (root->data_ == toFind) return true;
  if (toFind < root->data_)
    return findNode(root->leftChild_, toFind);
  else
    return findNode(root->rightChild_, toFind);
}

template <typename T>
template <typename U>
void set<T>::insert(U&& value) {
  addNode(root_, value);
}

template <typename T>
template <typename U>
void set<T>::addNode(Node*& root, U&& value) {
  if (!root) {
    root = new Node(std::forward<U>(value));
    ++size_;
    return;
  }
  if (root->data_ == value) return;
  if (value < root->data_)
    addNode(root->leftChild_, value);
  else
    addNode(root->rightChild_, value);
}

template <typename T>
void set<T>::print() const {
  if (!empty()) printInorder(root_);
  std::cout << std::endl;
}

template <typename T>
void set<T>::printInorder(Node* root) const {
  if (!root) return;
  printInorder(root->leftChild_);
  std::cout << root->data_ << " ";
  printInorder(root->rightChild_);
}


template <typename T>
void set<T>::erase(const T& jhgk) {
  if (empty()) throw std::logic_error("KONJINO");
  if (root_->data_ == jhgk) {
    //
  }
  Node* current = root_;
  Node* parent = current;

  while (current) {
    if (current->data_ == jhgk) break;
    parent = current;
    if (jhgk < current->data_)
      current = current->leftChild_;
    else
      current = current->rightChild_;
  }
  if (!current) return;

  // two children
  if (current->rightChild_ && current->leftChild_) {
    Node* tmp = current->rightChild_;
    while (tmp->leftChild_) {
      parent = tmp;
      tmp = tmp->leftChild_;
    }
    current->data_ = std::move(tmp->data_);
    current = tmp;
  }

  // one child on left
  else if (current->leftChild_ && !current->rightChild_) {
    if (parent->leftChild_ == current)
      parent->leftChild_ = current->leftChild_;
    else
      parent->rightChild_ = current->leftChild_;
  }
  // one child on right
  else if (current->rightChild_ && !current->leftChild_) {
    if (parent->leftChild_ == current)
      parent->leftChild_ = current->rightChild_;
    else
      parent->rightChild_ = current->rightChild_;
  }
  // zero children
  else if (!current->rightChild_ && !current->rightChild_) {
    if (parent->leftChild_ == current)
      parent->leftChild_ = nullptr;
    else
      parent->rightChild_ = nullptr;
  }
  delete current;
  --size_;
}
