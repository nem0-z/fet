#pragma once
#include "list.hpp"

template <typename T>
class list<T>::iterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
public:
    friend class list;
    iterator(Node *current, Node *previous) : current_{current}, previous_{previous} {}

    T &operator*()
    {
        return current_->data_;
    }
    const T &operator*() const
    {
        return current_->data_;
    }
    iterator &operator++()
    {
        previous_ = current_;
        if (current_)
            current_ = current_->next_;
        return *this;
    }
    iterator operator++(int)
    {
        iterator tmp = *this;
        ++(*this);
        return tmp;
    }
    iterator &operator--()
    {
        current_ = previous_;
        if (previous_)
            previous_ = previous_->prev_;
        return *this;
    }
    iterator operator--(int)
    {
        iterator tmp = *this;
        --(*this);
        return tmp;
    }
    bool operator==(const iterator &other)
    {
        return current_ == other.current_ && previous_ == other.previous_;
    }
    bool operator!=(const iterator &other)
    {
        return current_ != other.current_ && previous_ != other.previous_;
    }
    bool isBegin()
    {
        return previous_ == nullptr && current_ != nullptr;
    }
    bool isEnd()
    {
        return current_ == nullptr && previous_ != nullptr;
    }

private:
    Node *current_ = nullptr;
    Node *previous_ = nullptr;
};