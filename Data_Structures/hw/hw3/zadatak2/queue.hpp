#pragma once
#include <cstddef>
#include <iostream>
#include <algorithm>
#include <utility>
#include <stdexcept>

template <typename Elem>
class queue
{
public:
    queue();
    queue(const queue &);
    queue(queue &&);
    queue &operator=(const queue &);
    queue &operator=(queue &&);
    ~queue();

    template <typename T>
    queue &enqueue(T &&);

    Elem dequeue();

    Elem &top();
    const Elem &top() const;

    void print() const;

    inline size_t size() const;
    inline bool empty() const;

private:
    class Node
    {
    public:
        Elem data{};
        Node *next = nullptr;

        Node() = default;
        template <typename T>
        Node(T &&val) : data{std::forward<T>(val)} {}
    };
    Node *head_ = nullptr;
    Node *tail_ = nullptr;
    size_t size_ = 0;
    void clear();
};

template <typename Elem>
queue<Elem>::queue() = default;

template <typename Elem>
queue<Elem>::queue(const queue &other)
    : size_{other.size_}
{
    if (other.empty())
    {
        head_ = tail_ = nullptr;
    }
    else
    {
        head_ = tail_ = new Node(other.head_->data);
        Node *tmp = other.head_->next;
        while (tmp)
        {
            Node *toAdd = new Node(tmp->data);
            tail_->next = toAdd;
            tail_ = toAdd;
            tmp = tmp->next;
        }
    }
}

template <typename Elem>
queue<Elem>::queue(queue &&other)
    : head_{other.head_}, tail_{other.tail_}, size_{other.size_}
{
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
}

template <typename Elem>
queue<Elem> &queue<Elem>::operator=(const queue &other)
{
    return (this != &other) ? *this = queue(other) : *this; //ghetto
}

template <typename Elem>
queue<Elem> &queue<Elem>::operator=(queue &&other)
{
    if (this != &other)
    {
        clear();
        head_ = other.head_;
        tail_ = other.tail_;
        size_ = other.size_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template <typename Elem>
queue<Elem>::~queue()
{
    clear();
}

template <typename Elem>
template <typename T>
queue<Elem> &queue<Elem>::enqueue(T &&val)
{
    Node *toAdd = new Node(std::forward<T>(val));
    if (empty())
        head_ = tail_ = toAdd;
    else
    {
        tail_->next = toAdd;
        tail_ = toAdd;
    }
    ++size_;
    return *this;
}

template <typename Elem>
Elem queue<Elem>::dequeue()
{
    if (!empty())
    {
        Elem toDequeue = std::move(head_->data);
        Node *tmp = head_->next;
        delete head_;
        head_ = tmp;
        --size_;
        return toDequeue;
    }
    else
        throw std::runtime_error("Empty queue");
}

template <typename Elem>
Elem &queue<Elem>::top()
{
    if (!empty())
        return head_->data;
    else
        throw std::runtime_error("Empty queue");
}
template <typename Elem>
const Elem &queue<Elem>::top() const
{
    if (!empty())
        return head_->data;
    else
        throw std::runtime_error("Empty queue");
}

template <typename Elem>
void queue<Elem>::print() const
{
    if (!empty())
    {
        Node *tmp = head_;
        while (tmp)
        {
            std::cout << tmp->data << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
    else
        std::cout << "Empty queue" << std::endl;
}

template <typename Elem>
inline size_t queue<Elem>::size() const
{
    return size_;
}
template <typename Elem>
inline bool queue<Elem>::empty() const
{
    return size_ == 0;
}
template <typename Elem>
void queue<Elem>::clear()
{
    if (!empty())
    {
        Node *tmp = nullptr;
        while (head_)
        {
            tmp = head_->next;
            delete head_;
            head_ = tmp;
        }
    }
}
