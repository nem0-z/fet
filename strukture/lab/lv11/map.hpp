#pragma once
#include <cstddef>
#include <iostream>
#include <utility>

template <typename Key, typename Value>
class mapa
{
public:
  mapa();
  mapa(const mapa &);
  mapa(mapa &&);
  ~mapa();

  mapa &operator=(const mapa &);
  mapa &operator=(mapa &&);

  template <typename U, typename V>
  void add(U &&key, V &&value);
  void print() const;
  bool find(const Key &) const;
  bool erase(const Key &);

  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }

private:
  struct Node
  {
    Value value;
    Key key;
    Node *leftChild;
    Node *rightChild;

    template <typename U, typename V>
    Node(U &&kljuc, V &&vrijednost)
        : key{std::forward<U>(kljuc)}, value{std::forward<V>(vrijednost)},
          leftChild{nullptr}, rightChild{nullptr} {}
    ~Node()
    {
      delete leftChild;
      delete rightChild;
    }
  };

  template <typename U, typename V>
  void addIntoNode(Node *node, U &&key, V &&value);

  void printNode(Node *) const;

  void deleteNode(Node *node)
  {
    if (node->leftChild)
      deleteNode(node->leftChild);
    if (node->rightChild)
      deleteNode(node->rightChild);
    delete node;
  }

  Node *root_;
  size_t size_;
};

template <typename Key, typename Value>
mapa<Key, Value>::mapa() : root_{nullptr}, size_{0} {}

template <typename Key, typename Value>
mapa<Key, Value>::mapa(const mapa &other) : size_{other.size_} {}

template <typename Key, typename Value>
mapa<Key, Value>::~mapa()
{
  // delete root_;
  // implementirati destruktor za Node pa ce on rekurzivno ubijati svoju djecu
  if (!empty())
    deleteNode(root_);
}

template <typename Key, typename Value>
template <typename U, typename V>
void mapa<Key, Value>::addIntoNode(Node *node, U &&key, V &&value)
{
  if (key < node->key)
  {
    if (node->leftChild == nullptr)
      node->leftChild = new Node(std::forward<U>(key), std::forward<V>(value));
    else
      addIntoNode(node->leftChild, key, value);
  }
  else
  {
    if (node->rightChild == nullptr)
      node->rightChild = new Node(std::forward<U>(key), std::forward<V>(value));
    else
      addIntoNode(node->rightChild, key, value);
  }
}

template <typename Key, typename Value>
template <typename U, typename V>
void mapa<Key, Value>::add(U &&key, V &&value)
{
  if (empty())
    root_ = new Node(std::forward<U>(key), std::forward<V>(value));
  else
    addIntoNode(root_, key, value);
  ++size_;
}

template <typename Key, typename Value>
void mapa<Key, Value>::print() const
{
  // preorder: root, left subtree, right subtree
  // postorder: left subtree, right subtree, root
  // inorder:  left subtree, root, right subtree
  if (!empty())
    printNode(root_);
}

template <typename Key, typename Value>
void mapa<Key, Value>::printNode(Node *node) const
{
  if (node->leftChild)
    printNode(node->leftChild);
  std::cout << node->value << std::endl;
  if (node->rightChild)
    printNode(node->rightChild);
}

// template <typename T>
// bool mapa<T>::find(const T &value) const
// {
//   Node *current = root_;

//   while (current)
//   {
//     if (current->value == value)
//       return true;
//     else if (value < current->value)
//       current = current->leftChild;
//     else
//       current = current->rightChild;
//   }
//   return false;
// }

// template <typename T>
// bool mapa<T>::erase(const T &toErase)
// {
//   Node *parent = root_;
//   Node *current = root_;

//   while (current)
//   {
//     if (current->value == toErase)
//       break;
//     parent = current;
//     if (toErase < current->value)
//       current = current->leftChild;
//     else
//       current = current->rightChild;
//   }
//   if (!current)
//     return false;

//   if (current->leftChild && current->rightChild)
//   {
//     Node *tmp = current;
//     //tmp pokazuje na cvor koji sadrzi vrijednost za brisanje
//     //current cemo pomjerati u stablu koristeci NPP
//     parent = current;
//     current = current->leftChild;
//     while (current->rightChild)
//     {
//       parent = current;
//       current = current->rightChild;
//     }
//     //current postaje cvor koji ima 0 ili jedno dijete jer smo ga ovako ispomjerali
//     tmp->value = std::move(current->value);
//   }
//   if (!current->leftChild && !current->rightChild)
//   {
//     if (parent->leftChild == current)
//       parent->leftChild = nullptr;
//     else
//       parent->rightChild = nullptr;
//     delete current;
//     //nema djece
//   }

//   else if (!current->rightChild)
//   {
//     if (parent->leftChild == current)
//       parent->leftChild = current->leftChild;
//     else
//       parent->rightChild = current->leftChild;
//     delete current;
//     //ima samo lijevo dijete
//   }
//   else
//   {
//     if (parent->leftChild == current)
//       parent->leftChild = current->rightChild;
//     else
//       parent->rightChild = current->rightChild;
//     delete current;
//     //ima samo desno dijete
//   }

//   return true;
// }
