#pragma once
#include <iostream>
#include <stdexcept>
#include <utility>
#include <cstddef>

template <typename T>
class BST
{
public:
    BST();
    // BST(const BST &);
    // BST(BST &&);
    // ~BST();

    // BST &operator=(const BST &);
    // BST &operator=(BST &&);

    template <typename U>
    bool insert(U &&); //nek vrati bool da li je uspjesno ili ne
    void print() const;
    bool find(const T &);
    bool empty() const
    {
        return size_ == 0;
    }
    size_t size() const
    {
        return size_;
    }

private:
    class Node
    {
    public:
        Node *leftChild;
        Node *rightChild;
        T data;
        template <typename U>
        Node(U &&value) : data{std::forward<U>(value)},
                          leftChild{nullptr}, rightChild{nullptr} {}
    };
    Node *root_;
    size_t size_ = 0;
    template <typename U>
    bool addNode(Node *, U &&);
    void printNode(Node *) const;
};

template <typename T>
void BST<T>::printNode(Node *node) const
{
    if (node->leftChild)
        printNode(node->leftChild);
    std::cout << "Value: " << node->data << std::endl;
    if (node->rightChild)
        printNode(node->rightChild);
}

template <typename T>
void BST<T>::print() const
{
    if (!empty())
        printNode(root_);
}

template <typename T>
BST<T>::BST() : root_{nullptr} {}

template <typename T>
template <typename U>
bool BST<T>::insert(U &&value)
{
    if (empty())
    {
        root_ = new Node(std::forward<U>(value));
        ++size_;
        return true;
    }
    else
        return addNode(root_, value);
}

template <typename T>
template <typename U>
bool BST<T>::addNode(Node *node, U &&value)
{
    bool flag = false;
    if (value < node->data)
    {
        if (node->leftChild)
            addNode(node->leftChild, value);
        else
        {
            node->leftChild = new Node(std::forward<U>(value));
            ++size_;
            flag = 1;
        }
    }
    else
    {
        if (node->rightChild)
            addNode(node->rightChild, value);
        else
        {
            node->rightChild = new Node(std::forward<U>(value));
            ++size_;
            flag = 1;
        }
    }
    return flag;
}