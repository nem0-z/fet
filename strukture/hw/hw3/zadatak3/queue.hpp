#pragma once
#include <cstddef>
#include <utility>
#include <iostream>
#include <algorithm>
#include <stdexcept>

template <typename Elem>
class queue
{
public:
    queue(size_t cap = 999);
    queue(const queue &);
    queue(queue &&);
    queue &operator=(const queue &);
    queue &operator=(queue &&);
    ~queue();

    template <typename T>
    void push(T &&);

    Elem pop();

    inline Elem &front();
    inline Elem &back();
    inline const Elem &front() const;
    inline const Elem &back() const;

    inline size_t size() const;
    inline size_t capacity() const;
    inline bool empty() const;
    inline bool full() const;

    void print() const;

private:
    size_t capacity_;
    int lo_ = -1;
    int hi_ = -1;
    size_t size_ = 0;
    Elem *ptr_;
    void clear();
    void realocate();
};

template <typename Elem>
queue<Elem>::queue(size_t cap)
    : capacity_{cap}, ptr_{new Elem[capacity_]} {}

template <typename Elem>
queue<Elem>::queue(const queue &other)
    : capacity_{other.capacity_},
      lo_{other.lo_},
      hi_{other.hi_},
      size_{other.size_},
      ptr_{new Elem[capacity_]}
{
    std::copy(other.ptr_, other.ptr_ + capacity_, ptr_);
}

template <typename Elem>
queue<Elem>::queue(queue &&other)
    : capacity_{other.capacity_},
      lo_{other.lo_},
      hi_{other.hi_},
      size_{other.size_},
      ptr_{other.ptr_}
{
    other.ptr_ = nullptr;
    other.lo_ = -1;
    other.hi_ = -1;
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
        capacity_ = other.capacity_;
        lo_ = other.lo_;
        hi_ = other.hi_;
        size_ = other.size_;
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        other.lo_ = -1;
        other.hi_ = -1;
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
void queue<Elem>::push(T &&val)
{
    if (full())
        throw std::out_of_range("Queue is full.");
    // realocate();
    if (empty())
        lo_ = 0;
    hi_ = (hi_ + 1) % capacity_;
    ptr_[hi_] = std::forward<T>(val);
    ++size_;
}

template <typename Elem>
void queue<Elem>::print() const
{
    if (!empty())
    {
        std::cout << "Size: " << size() << std::endl;
        std::cout << "Capacity: " << capacity() << std::endl;
        std::cout << "Lower index: " << lo_ << std::endl;
        std::cout << "Higher index: " << hi_ << std::endl;
        std::cout << std::endl;
    }
    else
        std::cout << "Empty queue" << std::endl;
}

template <typename Elem>
inline bool queue<Elem>::empty() const
{
    return size_ == 0;
}
template <typename Elem>
inline bool queue<Elem>::full() const
{
    return size_ == capacity_;
}
template <typename Elem>
inline size_t queue<Elem>::size() const
{
    return size_;
}
template <typename Elem>
inline size_t queue<Elem>::capacity() const
{
    return capacity_;
}

template <typename Elem>
Elem queue<Elem>::pop()
{
    if (empty())
        throw std::runtime_error("Empty queue");
    int popFrom = lo_;
    lo_ = (lo_ + 1) % capacity_;
    --size_;
    return ptr_[popFrom];
}

template <typename Elem>
inline Elem &queue<Elem>::front()
{
    return ptr_[lo_];
}
template <typename Elem>
inline Elem &queue<Elem>::back()
{
    return ptr_[hi_];
}
template <typename Elem>
inline const Elem &queue<Elem>::front() const
{
    return ptr_[lo_];
}
template <typename Elem>
inline const Elem &queue<Elem>::back() const
{
    return ptr_[hi_];
}
template <typename Elem>
void queue<Elem>::clear()
{
    delete[] ptr_;
}

template <typename Elem>
void queue<Elem>::realocate()
{
    auto oldCap = capacity_;
    capacity_ *= 2;
    auto tmp = new Elem[capacity_];
    std::copy(ptr_ + lo_, ptr_ + oldCap, tmp);
    std::copy(ptr_, ptr_ + hi_ + 1, tmp + oldCap - lo_);
    delete[] ptr_;
    ptr_ = tmp;
    lo_ = 0;
    hi_ = size_ - 1;
}