#pragma once
#include <initializer_list>
#include <stdexcept>
#include <iterator>
#include <utility>
#include <functional>

template <typename T>
class ArrayList
{
private:
    size_t size_;
    size_t capacity_;
    T *elements_;

public:
    ArrayList(size_t capacityVar = 100);

    ArrayList(std::initializer_list<T>);

    ArrayList(const ArrayList &other);

    ArrayList(ArrayList &&other);

    ArrayList &operator=(const ArrayList &other);

    ArrayList &operator=(ArrayList &&other);

    ~ArrayList();

    class iterator;
    class const_iterator;

    bool empty() const;
    bool full() const;
    inline int size() const;
    inline int capacity() const;
    void print() const;
    void reserve();
    T &back() const;
    T &front() const;
    const T &at(int) const;
    T &at(int);
    T &operator[](int);
    const T &operator[](int) const;

    ArrayList<T> &push_back(const T &);
    ArrayList<T> &pop_back();
    ArrayList<T> &push_front(const T &);
    ArrayList<T> &pop_front();
    ArrayList<T> &insert(const int &, const T &);
    template <typename RandomAccessIter>
    void insert(const RandomAccessIter &, const T &);
    ArrayList<T> &invert();
    iterator find(const T &);
    ArrayList<T> &replace(const T &, const T &);
    void remove(typename ArrayList<T>::iterator);
    iterator find_if(const std::function<bool(T)> &);
    iterator remove_if(const std::function<bool(T)> &);

    const_iterator cbegin() const;
    const_iterator cend() const;
    iterator begin() const;
    iterator end() const;
};

#include "iterator.hpp"
#include "constIterator.hpp"
