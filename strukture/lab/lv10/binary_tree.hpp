#pragma once
#include <cstddef>
#include <iostream>
#include <utility>

template <typename T>
class binary_tree {
  public:
  binary_tree();
  binary_tree(const binary_tree&);
  binary_tree(binary_tree&&);
  ~binary_tree();

  binary_tree& operator=(const binary_tree&);
  binary_tree& operator=(binary_tree&&);

  template <typename U>
  void add(U&&);
  void print() const;
  bool find(const T&) const;

  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }

  private:
  struct Node {
    T value;
    Node* leftChild;
    Node* rightChild;

    template <typename U>
    Node(U&& v)
        : value{std::forward<U>(v)}, leftChild{nullptr}, rightChild{nullptr} {}
    ~Node() {
      delete leftChild;
      delete rightChild;
    }
  };

  template <typename U>
  void addIntoNode(Node* node, U&& value);

  void printNode(Node*) const;

  Node* root_;
  size_t size_;
};

template <typename T>
binary_tree<T>::binary_tree() : root_{nullptr}, size_{0} {}

template <typename T>
binary_tree<T>::binary_tree(const binary_tree& other) : size_{other.size_} {}

template <typename T>
binary_tree<T>::~binary_tree() {
  delete root_;
  // implementirati destruktor za Node pa ce on rekurzivno ubijati svoju djecu
}

template <typename T>
template <typename U>
void binary_tree<T>::addIntoNode(Node* node, U&& value) {
  if (value < node->value) {
    if (node->leftChild == nullptr) {
      node->leftChild = new Node(std::forward<U>(value));
    } else {
      addIntoNode(node->leftChild, value);
    }
  } else {
    if (node->rightChild == nullptr) {
      node->rightChild = new Node(std::forward<U>(value));
    } else {
      addIntoNode(node->rightChild, value);
    }
  }
}

template <typename T>
template <typename U>
void binary_tree<T>::add(U&& value) {
  if (empty())
    root_ = new Node(std::forward<U>(value));
  else {
    addIntoNode(root_, value);
  }
  ++size_;
}

template <typename T>
void binary_tree<T>::print() const {
  // preorder: root, left subtree, right subtree
  // postorder: left subtree, right subtree, root
  // inorder:  left subtree, root, right subtree

  if (!empty()) printNode(root_);
}

template <typename T>
void binary_tree<T>::printNode(Node* node) const {
  if (node->leftChild) printNode(node->leftChild);
  std::cout << node->value << std::endl;
  if (node->rightChild) printNode(node->rightChild);
}

template <typename T>
bool binary_tree<T>::find(const T& value) const {
  Node* current = root_;

  while (current) {
    if (current->value == value) {
      return true;
    } else if (value < current->value) {
      current = current->leftChild;
    } else {
      current = current->rightChild;
    }
  }
  return false;
}
