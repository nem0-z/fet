#pragma once
#include "vec.hpp"

template <typename T>
class vector<T>::iterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
    iterator(T *p) : ptr_{p} {}
    iterator(const iterator &other)
    {
        ptr_ = other.ptr_;
    }
    T &operator*(void)
    {
        return *ptr_;
    }
    const T &operator*(void)const
    {
        return *ptr_;
    }
    iterator &operator++()
    {
        ++ptr_;
        return *this;
    }
    iterator operator++(int)
    {
        T *tmp = *this;
        ++(*this);
        return tmp;
    }
    iterator &operator--()
    {
        --ptr_;
        return *this;
    }
    iterator operator--(int)
    {
        T *tmp = *this;
        --(*this);
        return tmp;
    }
    bool operator==(iterator &other)
    {
        return ptr_ == other.ptr_;
    }
    bool operator!=(iterator &other)
    {
        return ptr_ != other.ptr_;
    }
    bool operator<(iterator &other)
    {
        return ptr_ < other.ptr_;
    }
    bool operator>(iterator &other)
    {
        return ptr_ > other.ptr_;
    }
    T operator-(const iterator &other)
    {
        return ptr_ - other.ptr_;
    }
    iterator operator+(int step)
    {
        return ptr_ + step;
    }
    iterator operator-(int step)
    {
        return ptr_ + step;
    }

private:
    T *ptr_;
};