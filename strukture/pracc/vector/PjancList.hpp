#pragma once
#include <iostream>
#include <stdexcept>
#include <initializer_list>

//Array koji je Pjano radio na predavanju
template <typename T>
class PjancList
{
private:
    T *data_;
    size_t size_;
    int donja;
    int gornja;
    void kopiraj(const PjancList &other)
    {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

public:
    PjancList(int d, int g) : donja{d}, gornja{g}
    {
        if (g < d)
            throw std::invalid_argument("Donja granica ne smije biti veca od gornje.");
        size_ = gornja - donja + 1;
        data_ = new T[size_];
    }
    PjancList(std::initializer_list<T> initList) : size_{initList.size()}, donja{0},
                                                   gornja{static_cast<int>(size_) - 1}
    {
        data_ = new T[size_];
        // std::copy(initList.begin(),initList.end(),data_);
        int i = 0;
        for (auto it = initList.begin(); it != initList.end(); ++i, ++it)
            data_[i] = *it;
    }
    PjancList(const PjancList &other) : size_{other.size_}, donja{other.donja}, gornja{other.gornja}
    {
        data_ = new T[size_];
        kopiraj(other);
    }
    PjancList(PjancList &&other) : size_{other.size_}, donja{other.donja}, gornja{other.gornja}
    {
        data_ = other.data_;
        other.data_ = nullptr;
    }
    PjancList &operator=(const PjancList &other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            donja = other.donja;
            gornja = other.gornja;
            data_ = new T[size_];
            kopiraj(other);
        }
        return *this;
    }
    PjancList &operator=(PjancList &&other)
    {
        if (this != &other)
        {
            delete[] data_;
            size_ = other.size_;
            donja = other.donja;
            gornja = other.gornja;
            data_ = other.data_;
            other.data_ = nullptr;
        }
        return *this;
    }
    ~PjancList() { delete[] data_; }
    T &operator[](int index) { return data_[index - donja]; }
    const T &operator[](int index) const { return data_[index - donja]; }
    void realociraj(int d, int g)
    {
        if (g < d)
            throw std::invalid_argument("Donja granica ne smije biti veca od gornje.");
        donja = d;
        gornja = g;
        size_ = gornja - donja + 1;
        T *tmp = new T[size_];
        delete[] data_;
        data_ = tmp;
    }
    PjancList &push_back(const T &val)
    {
        data_[size_++] = val;
        return *this;
    }
    void print() const
    {
        for (int i = 0; i < size_; ++i)
            std::cout << data_[i] << " ";
        std::cout << '\n';
    }
    class iterator;
    class const_iterator;
    iterator begin() { return iterator(data_); }
    iterator end() { return iterator(data_ + size_); }
};

template <typename T>
class PjancList<T>::iterator : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    T *ptr;

public:
    iterator(T *pel) : ptr{pel} {}

    T &operator*() { return *ptr; }
    //sad dalje oni operatori nebitno
};