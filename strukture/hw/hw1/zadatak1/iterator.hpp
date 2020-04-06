#pragma once
template <typename T>
class ArrayList<T>::iterator
    : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    T *ptr_;

public:
    iterator(T *pel) : ptr_{pel} {}

    T &operator*() const { return *ptr_; }

    iterator &operator++()
    {
        ++ptr_;
        return *this;
    }
    iterator operator++(int)
    {
        iterator tmp = *this;
        ++ptr_;
        return tmp;
    }
    iterator &operator--()
    {
        --ptr_;
        return *this;
    }
    iterator operator--(int)
    {
        iterator tmp = *this;
        --ptr_;
        return tmp;
    }
    bool operator!=(const iterator &other) const { return ptr_ != other.ptr_; }
    bool operator==(const iterator &other) const { return ptr_ == other.ptr_; }
    iterator operator+(const int &val) { return iterator(ptr_ + val); }
    iterator operator-(const int &val) { return iterator(ptr_ - val); }
    iterator &operator+=(const int &val)
    {
        ptr_ += val;
        return *this;
    }
    iterator &operator-=(const int &val)
    {
        ptr_ -= val;
        return *this;
    }
    int operator-(const iterator &other) const
    {
        return ptr_ - other.ptr_;
    }
    int operator+(const iterator &other) const
    {
        return ptr_ + other.ptr_;
    }
    // int operator-(iterator lhs, const_iterator other);
    // int operator+(iterator lhs, const_iterator other);
};