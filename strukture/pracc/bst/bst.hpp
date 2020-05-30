#pragma once
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <utility>

template <typename Value>
class set {
  public:
  set();
  set(const set&);
  set(set&&);
  ~set();

  set& operator=(const set&);
  set& operator=(set&&);

  size_t size() const { return size_; }
  bool empty() const { return root_ == nullptr; }

  template <typename U>
  void insert(U&&);
  bool find(const Value&) const;
  void erase(const Value&);
  void print() const;

  private:
  class Node {
public:
    Value data;
    Node* leftChild;
    Node* rightChild;

    template <typename U>
    Node(U&& v)
        : data{std::forward<U>(v)}, leftChild{nullptr}, rightChild{nullptr} {}
  };
  Node* root_;
  size_t size_;
  void insertNode(Node*, Node*);
  void deleteNode(Node*, const Value&);
  void printInorder(Node*) const;
  void printPostorder(Node*) const;
  void printPreorder(Node*) const;
  bool findNode(Node*, const Value&) const;
  void insertCopyNode(Node*&, Node*);
  void clear(Node*);
};


template <typename Value>
set<Value>::set() : root_{nullptr}, size_{0} {}

template <typename Value>
void set<Value>::insertCopyNode(Node*& copyHere, Node* copyThis) {
  if (!copyThis) return;
  Node* newNode = new Node(copyThis->data);
  copyHere = newNode;
  insertCopyNode(copyHere->leftChild, copyThis->leftChild);
  insertCopyNode(copyHere->rightChild, copyThis->rightChild);
}

template <typename Value>
set<Value>::set(const set& other) : size_{other.size_} {
  // preorder
  if (!other.empty()) insertCopyNode(root_, other.root_);
}

template <typename Value>
set<Value>::set(set&& other) : root_{other.root_}, size_{other.size_} {
  other.root_ = nullptr;
}

template <typename Value>
set<Value>::~set() {
  clear(root_);
  root_ = nullptr;
  size_ = 0;
}

template <typename Value>
template <typename U>
void set<Value>::insert(U&& val) {
  Node* newNode = new Node(std::forward<U>(val));
  if (empty()) {
    root_ = newNode;
    ++size_;
  } else {
    insertNode(root_, newNode);
  }
}
template <typename Value>
void set<Value>::insertNode(Node* root, Node* newNode) {
  if (root->data == newNode->data) return;
  if (newNode->data < root->data) {
    if (root->leftChild == nullptr) {
      root->leftChild = newNode;
      ++size_;
    } else
      insertNode(root->leftChild, newNode);
  } else {
    if (root->rightChild == nullptr) {
      root->rightChild = newNode;
      ++size_;
    } else
      insertNode(root->rightChild, newNode);
  }
}

template <typename Value>
void set<Value>::print() const {
  if (!empty()) {
    printInorder(root_);
    std::cout << std::endl;
  } else
    std::cout << "Empty tree" << std::endl;
}

template <typename Value>
void set<Value>::printInorder(Node* root) const {
  if (root == nullptr) return;
  printInorder(root->leftChild);
  std::cout << root->data << " ";
  printInorder(root->rightChild);
}

template <typename Value>
void set<Value>::printPreorder(Node* root) const {
  if (root == nullptr) return;
  std::cout << root->data << " ";
  printPreorder(root->leftChild);
  printPreorder(root->rightChild);
}

template <typename Value>
void set<Value>::printPostorder(Node* root) const {
  if (root == nullptr) return;
  printPostorder(root->leftChild);
  printPostorder(root->rightChild);
  std::cout << root->data << " ";
}

template <typename Value>
bool set<Value>::find(const Value& toFind) const {
  if (empty())
    throw std::runtime_error("");
  else
    return findNode(root_, toFind);
}

template <typename Value>
bool set<Value>::findNode(Node* node, const Value& toFind) const {
  if (node == nullptr) return false;
  if (node->data == toFind) return true;
  if (toFind < node->data)
    return findNode(node->leftChild, toFind);
  else
    return findNode(node->rightChild, toFind);
  return false;
}

template <typename Value>
void set<Value>::erase(const Value& toDelete) {
  if (empty()) throw std::runtime_error("");
  Node* current = root_;
  Node* parent = current;
  while (current) {
    if (current->data == toDelete) break;
    parent = current;
    if (toDelete < current->data) {
      current = current->leftChild;
    } else {
      current = current->rightChild;
    }
  }
  // current is my Node where toDelete is stored
  if (!current) return;

  // 2 children:
  if (current->leftChild && current->rightChild) {
    Node* tmp = current;
    parent = current;
    current = current->leftChild;
    while (current->rightChild) {
      parent = current;
      current = current->rightChild;
    }
    tmp->data = std::move(current->data);
  }
  // 0 children:
  if (!current->leftChild && !current->rightChild) {
    if (parent->leftChild == current)
      parent->leftChild = nullptr;
    else
      parent->rightChild = nullptr;
    delete current;
  }
  // 1 child:
  else if (current->leftChild && !current->rightChild) {
    // 1 child on the left
    if (parent->leftChild == current) {
      parent->leftChild = current->leftChild;
    } else
      parent->rightChild = current->leftChild;
    delete current;
  } else {
    // 1 child on the right
    if (parent->rightChild == current)
      parent->rightChild = current->rightChild;
    else
      parent->leftChild = current->rightChild;
    delete current;
  }
  --size_;
}

template <typename Value>
void set<Value>::clear(Node* root) {
  if (!root) return;
  clear(root->leftChild);
  clear(root->rightChild);
  delete root;
}
// template <typename Value>
// template <typename Value>
// template <typename Value>
