#pragma once
#include <iostream>
#include <utility>
#include <stdexcept>
#include <cstddef>
#include <iterator>

template <typename T>
class vector
{
public:
    vector() : capacity_{100}, size_{0}, elements_{new T[capacity_]} {}
    vector(const vector &other) : capacity_{other.capacity_}, size_{other.size_}, elements_{new T[capacity_]}
    {
        std::copy(other.begin(), other.end(), elements_);
    }
    vector(vector &&);
    vector &operator=(const vector &other)
    {
        if (this != &other)
        {
            delete[] elements_;
            capacity_ = other.capacity_;
            size_ = other.size_;
            elements_ = new T[capacity_];
            std::copy(other.begin(), other.end(), elements_);
        }
        return *this;
    }
    vector &operator=(vector &&);
    ~vector()
    {
        delete[] elements_;
    }

    bool empty() const { return size_ == 0; }
    bool full() const { return size_ == capacity_; }
    size_t size() const { return size_; }
    size_t capacity() const { return capacity_; }
    void print() const
    {
        for (int i = 0; i < size_; ++i)
            std::cout << elements_[i] << " ";
        std::cout << std::endl;
    }
    const T &back() const { return elements_[size_ - 1]; }
    const T &front() const { return elements_[0]; }
    T &back() { return elements_[size_ - 1]; }
    T &front() { return elements_[0]; }
    T &at(int index)
    {
        if (index < 0 || index > size_)
            throw std::out_of_range("Nope!");
        return elements_[index];
    }
    T &operator[](int index) { return elements_[index]; }

    // Zadatak 1
    template <typename U>
    vector &push_back(U &&);
    vector &pop_back();
    // // Zadatak 2
    template <typename U>
    vector &push_front(U &&);
    vector &pop_front();
    // // Zadatak 3
    vector &insert(int index, const T &value);
    // // Zadatak 4
    vector &invert();
    // // Zadatak 5
    int find(const T &value); // Vraca index elementa
    vector &replace(const T &oldValue, const T &newValue);

    class iterator;
    // class const_iterator;
    // const_iterator cbegin() const { return const_iterator(elements_); }
    // const_iterator cend() const { return const_iterator(elements_ + size_); }
    iterator begin() const { return iterator(elements_); }
    iterator end() const { return iterator(elements_ + size_); }
    iterator erase(iterator pos);

private:
    size_t capacity_;
    size_t size_;
    T *elements_;
    void reserve();
};

#include "iterator.hpp"

template <typename T>
typename vector<T>::iterator vector<T>::erase(typename vector<T>::iterator pos)
{
    int index = pos - begin();
    for (int i = index; i < size_ - 1; ++i)
        elements_[i] = elements_[i + 1];
    --size_;
    return iterator(elements_ + index);
}

template <typename T>
vector<T> &vector<T>::replace(const T &oldValue, const T &newValue)
{
    for (int i = 0; i < size_; ++i)
    {
        if (elements_[i] == oldValue)
            elements_[i] = newValue;
    }
    return *this;
}
template <typename T>
int vector<T>::find(const T &value)
{
    int i = 0;
    while (i < size_)
    {
        if (elements_[i] == value)
            return i;
        ++i;
    }
    return -1;
}

template <typename T>
vector<T> &vector<T>::invert()
{
    for (int i = 0; i < size_ / 2; ++i)
        std::swap(elements_[i], elements_[size_ - 1 - i]);
    return *this;
}

template <typename T>
vector<T> &vector<T>::insert(int index, const T &value)
{
    if (index < 0 || index > size_)
        throw std::out_of_range("debil");
    if (full())
        reserve();
    for (int i = size_; i > index; --i)
        elements_[i] = elements_[i - 1];
    elements_[index] = value;
    ++size_;
    return *this;
}

template <typename T>
vector<T> &vector<T>::pop_front()
{

    for (int i = 0; i < size_ - 1; ++i)
        elements_[i] = elements_[i + 1];
    --size_;
    return *this;
}

template <typename T>
template <typename U>
vector<T> &vector<T>::push_front(U &&value)
{
    if (full())
        reserve();
    for (int i = size_; i > 0; --i)
        elements_[i] = elements_[i - 1];
    elements_[0] = std::forward<U>(value);
    ++size_;
    return *this;
}

template <typename T>
void vector<T>::reserve()
{
    capacity_ *= 2;
    T *tmp = new T[capacity_];
    for (int i = 0; i < size_; ++i)
    {
        tmp[i] = std::move(elements_[i]);
    }
    delete[] elements_;
    elements_ = tmp;
}

template <typename T>
template <typename U>
vector<T> &vector<T>::push_back(U &&value)
{
    if (full())
        reserve();
    elements_[size_++] = std::forward<U>(value);
    return *this;
}

template <typename T>
vector<T> &vector<T>::pop_back()
{
    --size_;
    return *this;
}
