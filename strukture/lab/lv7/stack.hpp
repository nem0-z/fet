#pragma once
#include "node.hpp"
#include <cstddef>

template <typename T>
class stack
{
private:
    Node<T> *first_ = nullptr;
    size_t size_ = 0;

public:
    stack() = default;
    stack(const stack &);
    stack(stack &&);
    ~stack();

    stack &operator=(const stack &);
    stack &operator=(stack &&);

    void push(const T &);
    T &top();
    const T &top() const;

    size_t size() const;
    bool empty() const;

    void pop();
};

template <typename T>
stack<T>::stack(const stack<T> &other) : size_{other.size_}
{
    if (!empty())
    {
        first_ = new Node<T>(other.first_->value);
        Node<T> *tmp = other.first_->next;
        Node<T> *last = first_;

        while (tmp)
        {
            last->next = new Node<T>(tmp->value);
            tmp = tmp->next;
            last = last->next;
        }
    }
}

template <typename T>
stack<T>::stack(stack<T> &&other) : size_{other.size_}, first_{other.first_}
{
    other.first_ = nullptr;
}

template <typename T>
stack<T> &stack<T>::operator=(const stack<T> &other)
{
    if (!empty())
    {
        while (first_)
        {
            Node<T> *tmp = first_;
            first_ = first_->next;
            delete tmp;
        }
    } //isto sve kao i copy constructor samo sto moramo brisati

    if (!empty())
    {
        first_ = new Node<T>(other.first_->value);
        Node<T> *tmp = other.first_->next;
        Node<T> *last = first_;

        while (tmp)
        {
            last->next = new Node<T>(tmp->value);
            tmp = tmp->next;
            last = last->next;
        }
    }
    return *this;
}

template <typename T>
stack<T> &stack<T>::operator=(stack<T> &&other)
{
    if (!empty())
    {
        while (first_)
        {
            Node<T> *tmp = first_;
            first_ = first_->next;
            delete tmp;
        }
    } //isto sve kao i move constructor samo sto moramo brisati
    size_ = other.size_;
    first_ = other.first_;
    other.first_ = nullptr;
    return *this;
}

template <typename T>
stack<T>::~stack<T>()
{

    if (!empty())
    {
        while (first_)
        {
            Node<T> *tmp = first_;
            first_ = first_->next;
            delete tmp;
        }
    }
}

template <typename T>
void stack<T>::push(const T &val)
{
    Node<T> *newNode = new Node<T>(val, first_);
    first_ = newNode;
    ++size_;
    //first_ = new Node<T>(val,first_); //nais
}

//we add on stack from top
//push 5, 10, 20
//stack: 20,10,5

template <typename T>
T &stack<T>::top()
{
    return first_->value;
}

template <typename T>
const T &stack<T>::top() const
{
    return first_->value;
}

template <typename T>
size_t stack<T>::size() const
{
    return size_;
}

template <typename T>
bool stack<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
void stack<T>::pop()
{
    if (!empty())
    {
        Node<T> *tmp = first_;
        first_ = first_->next;
        delete tmp;
        --size_;
    }
}
