#pragma once
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstddef>
#include <stack>
#include <queue>

template <typename Key, typename Value>
class map
{
public:
  map() : size_{0}
  {
  }
  map(const map &other) : size_{other.size_}
  {
  }
  map(map &&other)
  {
  }
  ~map()
  {
    clearNode(root_);
    root_ = nullptr;
    size_ = 0;
  }

  bool empty() const { return size_ == 0; }
  size_t size() const { return size_; }

  void insert(const std::pair<Key, Value> &pair)
  {
    addNode(root_, pair);
  }

  Value &find(const Key &k)
  {
    auto found = findNode(root_, k);
    if (found)
      return *found;
    else
      throw std::runtime_error("Not found");
  }

  Value &operator[](const Key &k)
  {
    auto found = findNode(root_, k);
    if (found)
      return *found;
    else
      insert(std::make_pair(k, Value{}));
    return *findNode(root_, k);
  }

  void erase(const Key &k)
  {
    if (empty())
      return;
    if (root_->key_ == k)
    {
      if (root_->leftChild_ && !root_->rightChild_)
      {
        Node *tmp = root_;
        root_ = root_->leftChild_;
        delete tmp;
        --size_;
        return;
      }
      else if (!root_->leftChild_ && root_->rightChild_)
      {
        Node *tmp = root_;
        root_ = root_->rightChild_;
        delete tmp;
        --size_;
        return;
      }
      else if (!root_->leftChild_ && !root_->rightChild_)
      {
        delete root_;
        root_ = nullptr;
        size_ = 0;
        return;
      }
    }
    Node *current = root_;
    Node *parent = current;
    while (current)
    {
      if (current->key_ == k)
        break;
      parent = current;
      if (k < current->key_)
        current = current->leftChild_;
      else
        current = current->rightChild_;
    }
    if (!current)
      return;
    if (current->leftChild_ && current->rightChild_)
    {
      Node *tmp = current->rightChild_;
      parent = current;
      while (tmp->leftChild_)
      {
        parent = tmp;
        tmp = tmp->leftChild_;
      }
      current->value_ = std::move(tmp->value_);
      current = tmp;
    }

    else if (current->leftChild_ && !current->rightChild_)
    {
      if (parent->leftChild_ == current)
        parent->leftChild_ = current->leftChild_;
      else
        parent->rightChild_ = current->leftChild_;
    }
    else if (!current->leftChild_ && current->rightChild_)
    {
      if (parent->leftChild_ == current)
        parent->leftChild_ = current->rightChild_;
      else
        parent->rightChild_ = current->rightChild_;
    }
    else
    {
      if (parent->leftChild_ == current)
        parent->leftChild_ = nullptr;
      else
        parent->rightChild_ = nullptr;
    }
    delete current;
    --size_;
  }

  void print() const
  {
    printNode(root_);
    std::cout << std::endl;
  }

  void printBreadth() const
  {
    std::queue<Node *> s;
  }

private:
  class Node
  {
  public:
    Key key_;
    Value value_;
    Node *leftChild_ = nullptr;
    Node *rightChild_ = nullptr;
    template <typename U, typename V>
    Node(U &&key, V &&value)
    {
      key_ = std::forward<U>(key);
      value_ = std::forward<V>(value);
    }
  };
  void clearNode(Node *root)
  {
    if (!root)
      return;
    clearNode(root->leftChild_);
    clearNode(root->rightChild_);
    delete root;
  }
  void printNode(Node *root) const
  {
    if (!root)
      return;
    printNode(root->leftChild_);
    std::cout << root->key_ << " " << root->value_ << std::endl;
    printNode(root->rightChild_);
  }
  Value *findNode(Node *root, const Key &key)
  {
    if (!root)
      return nullptr;
    if (root->key_ == key)
      return &root->value_;
    if (key < root->key_)
      return findNode(root->leftChild_, key);
    else
      return findNode(root->rightChild_, key);
  }
  void addNode(Node *&root, const std::pair<Key, Value> &pair)
  {
    if (!root)
    {
      root = new Node(pair.first, pair.second);
      ++size_;
      return;
    }
    if (root->key_ == pair.first)
    {
      root->value_ = pair.second;
      return;
    }
    if (pair.first < root->key_)
      addNode(root->leftChild_, pair);
    else
      addNode(root->rightChild_, pair);
  }
  Node *root_ = nullptr;
  size_t size_;
};
