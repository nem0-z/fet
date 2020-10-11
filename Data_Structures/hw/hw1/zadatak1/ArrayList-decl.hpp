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
    ArrayList(const ArrayList &);
    ArrayList(ArrayList &&);
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
    T &at(int);
    T &operator[](int);
    const T &at(int) const;
    const T &operator[](int) const;

    void remove(const T &value);
    void remove(const typename ArrayList<T>::iterator &);
    ArrayList &operator=(const ArrayList &);
    ArrayList &operator=(ArrayList &&);
    ArrayList &push_back(const T &);
    ArrayList &pop_back();
    ArrayList &push_front(const T &);
    ArrayList &pop_front();
    ArrayList &insert(const int &, const T &);
    ArrayList &invert();
    ArrayList &replace(const T &, const T &);
    iterator find(const T &) const;

    template <typename predicate>
    iterator find_if(const predicate &) const;
    template <typename predicate>
    iterator remove_if(const predicate &);
    template <typename RandomAccessIter>
    void insert(const RandomAccessIter &, const T &);

    const_iterator cbegin() const;
    const_iterator cend() const;
    iterator begin() const;
    iterator end() const;
};
