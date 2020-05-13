#pragma once
#include <cstddef>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <utility>

template <typename Elem>
class stack
{
public:
    stack(size_t capacity = 10);
    stack(const stack &);
    stack(stack &&);
    stack &operator=(const stack &);
    stack &operator=(stack &&);
    ~stack();

    template <typename T>
    stack &push(T &&);

    Elem pop();

    Elem &top();
    const Elem &top() const;

    void print() const;

    inline size_t size() const;
    inline size_t capacity() const;
    inline bool empty() const;
    inline bool full() const;

private:
    size_t capacity_;
    int top_ = -1;
    Elem *ptr_ = nullptr;
    void realocate();
    inline void clear();
};

template <typename Elem>
stack<Elem>::stack(size_t cap) : capacity_{cap}, ptr_{new Elem[capacity_]} {}

template <typename Elem>
stack<Elem>::stack(const stack &other)
    : capacity_{other.capacity_}, top_{other.top_}, ptr_{new Elem[capacity_]}
{
    std::copy(other.ptr_, other.ptr_ + top_ + 1, ptr_);
}

template <typename Elem>
stack<Elem>::stack(stack &&other)
    : capacity_{other.capacity_}, top_{other.top_}, ptr_{other.ptr_}
{
    other.ptr_ = nullptr;
    other.top_ = -1;
}

template <typename Elem>
stack<Elem> &stack<Elem>::operator=(const stack &other)
{
    return (this != &other) ? *this = stack(other) : *this; //ghetto
}

template <typename Elem>
stack<Elem> &stack<Elem>::operator=(stack &&other)
{
    if (this != &other)
    {
        clear();
        capacity_ = other.capacity_;
        top_ = other.top_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        other.top_ = -1;
    }
    return *this;
}

template <typename Elem>
stack<Elem>::~stack()
{
    clear();
}

template <typename Elem>
inline size_t stack<Elem>::size() const
{
    return top_ + 1;
}
template <typename Elem>
inline size_t stack<Elem>::capacity() const
{
    return capacity_;
}
template <typename Elem>
inline bool stack<Elem>::empty() const
{
    return top_ == -1;
}
template <typename Elem>
inline bool stack<Elem>::full() const
{
    return (top_ + 1) == capacity_;
}

template <typename Elem>
inline void stack<Elem>::clear()
{
    top_ = -1;
    delete[] ptr_;
}

template <typename Elem>
void stack<Elem>::realocate()
{
    capacity_ *= 2;
    Elem *tmp = new Elem[capacity_];
    for (auto i = 0; i < top_ + 1; ++i)
    {
        tmp[i] = std::move(ptr_[i]);
    }
    delete[] ptr_;
    ptr_ = tmp;
}

template <typename Elem>
template <typename T>
stack<Elem> &stack<Elem>::push(T &&value)
{
    if (full())
        realocate();
    ptr_[++top_] = std::forward<T>(value);
    return *this;
}

template <typename Elem>
Elem stack<Elem>::pop()
{
    if (!empty())
    {
        Elem toPop = std::move(ptr_[top_]);
        --top_;
        return toPop;
    }
    else
        throw std::logic_error("Empty stack.");
}

template <typename Elem>
Elem &stack<Elem>::top()
{
    if (!empty())
        return ptr_[top_];
}
template <typename Elem>
const Elem &stack<Elem>::top() const
{
    if (!empty())
        return ptr_[top_];
}

template <typename Elem>
void stack<Elem>::print() const
{
    if (!empty())
    {
        for (auto i = 0; i < top_ + 1; ++i)
            std::cout << ptr_[i] << " ";
        std::cout << '\n';
    }
    else
        std::cout << "Empty stack\n";
}
