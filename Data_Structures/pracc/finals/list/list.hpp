#pragma once
#include <cstddef>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <iostream>

template <typename T>
class list
{
public:
    list();
    list(const list &);
    list(list &&);
    ~list();

    list &operator=(const list &);
    list &operator=(list &&);

    template <typename U>
    list &emplace_back(U &&value);
    template <typename U>
    list &emplace_front(U &&value);
    list &pop_back();
    list &pop_front();
    class iterator;
    iterator begin() const { return iterator(head_, nullptr); }
    iterator end() const { return iterator(nullptr, tail_); }
    void erase(iterator position);
    void splice(iterator position, const list &other);
    void insert(iterator position, const T &item);
    void erase(iterator from, iterator to);

    iterator find(const T &);
    template <typename UnaryOpt>
    iterator find_if(const UnaryOpt &);

    inline size_t size() const
    {
        return size_;
    }
    inline bool empty() const
    {
        return size_ == 0;
    }
    void clear();

    T &front() const;
    T &back() const;

    void print() const; // debugging

private:
    class Node
    {
    public:
        T data_;
        Node *next_ = nullptr;
        Node *prev_ = nullptr;
        template <typename U>
        Node(U &&value)
        {
            data_ = std::forward<U>(value);
        }
        Node(const Node &other) : data_{other.data_}, next_{other.next_}, prev_{other.prev_} {}
    };
    Node *head_ = nullptr;
    Node *tail_ = nullptr;
    size_t size_;
};

#include "iterator.hpp"

template <typename T>
list<T>::list() : size_{0}
{
}

template <typename T>
list<T>::~list()
{
    Node *tmp = head_;
    while (head_)
    {
        tmp = tmp->next_;
        delete head_;
        head_ = tmp;
    }
}

template <typename T>
template <typename U>
list<T> &list<T>::emplace_back(U &&value)
{
    Node *toAdd = new Node(value);
    if (empty())
    {
        head_ = tail_ = toAdd;
    }
    else
    {
        tail_->next_ = toAdd;
        toAdd->prev_ = tail_;
        tail_ = toAdd;
    }
    ++size_;
    return *this;
}

template <typename T>
template <typename U>
list<T> &list<T>::emplace_front(U &&value)
{
    if (empty())
        emplace_back(value);
    else
    {
        Node *toAdd = new Node(value);
        head_->prev_ = toAdd;
        toAdd->next_ = head_;
        head_ = toAdd;
    }
    ++size_;
    return *this;
}

template <typename T>
void list<T>::print() const
{
    for (auto it = begin(); it != end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

template <typename T>
list<T> &list<T>::pop_back()
{
    if (empty())
        throw std::out_of_range("Konj");
    if (size_ == 1)
    {
        delete head_;
        head_ = tail_ = nullptr;
    }
    else
    {
        Node *tmp = tail_->prev_;
        delete tail_;
        tail_ = tmp;
        tail_->next_ = nullptr;
    }
    --size_;
    return *this;
}

template <typename T>
list<T> &list<T>::pop_front()
{
    if (empty())
        throw std::out_of_range("Konj");
    if (size_ == 1)
    {
        delete head_;
        head_ = tail_ = nullptr;
    }
    else
    {
        Node *tmp = head_->next_;
        delete head_;
        head_ = tmp;
        head_->prev_ = nullptr;
    }
    --size_;
    return *this;
}

template <typename T>
T &list<T>::front() const
{
    return head_->data_;
}
template <typename T>
T &list<T>::back() const
{
    return tail_->data_;
}

template <typename T>
void list<T>::erase(typename list<T>::iterator position)
{
    if (empty())
        throw std::runtime_error("debil");
    if (position.isBegin())
    {
        pop_front();
    }
    else if (position.isEnd())
    {
        pop_back();
    }
    else
    {
        Node *p = position.previous_;
        Node *c = position.current_;
        p->next_ = c->next_;
        c->next_->prev_ = p;
        delete c;
    }
    --size_;
}

template <typename T>
void list<T>::insert(typename list<T>::iterator position, const T &item)
{
    if (position.isBegin())
        emplace_front(item);
    else if (position.isEnd())
        emplace_back(item);
    else
    {
        Node *toAdd = new Node(item);
        Node *c = position.current_;
        Node *p = position.previous_;
        p->next_ = toAdd;
        toAdd->prev_ = p;
        toAdd->next_ = c;
        c->prev_ = toAdd;
        ++size_;
    }
}

template <typename T>
typename list<T>::iterator list<T>::find(const T &toFind)
{
    Node *tmp = head_;
    while (tmp)
    {
        if (tmp->data_ == toFind)
            return iterator(tmp, tmp->prev_);
        tmp = tmp->next_;
    }
    return end();
}

template <typename T>
template <typename UnaryOpt>
typename list<T>::iterator list<T>::find_if(const UnaryOpt &lambda)
{
    for (auto it = begin(); it != end(); ++it)
    {
        if (lambda(*it))
            return it;
    }
    return end();
}
