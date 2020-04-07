#pragma once
template <typename T>
class ArrayList<T>::const_iterator
    : public std::iterator<std::random_access_iterator_tag, T>
{
private:
    const T *ptr_;

public:
    const_iterator(const T *pel) : ptr_{pel} {}

    const T &operator*() const { return *ptr_; }

    const_iterator &operator++()
    {
        ++ptr_;
        return *this;
    }
    const_iterator operator++(int)
    {
        const_iterator tmp = *this;
        ++ptr_;
        return tmp;
    }
    const_iterator &operator--()
    {
        --ptr_;
        return *this;
    }
    const_iterator operator--(int)
    {
        const_iterator tmp = *this;
        --ptr_;
        return tmp;
    }
    bool operator!=(const const_iterator &other) const { return ptr_ != other.ptr_; }
    bool operator==(const const_iterator &other) const { return ptr_ == other.ptr_; }

    const_iterator operator+(const int &val) const { return const_iterator(ptr_ + val); }
    const_iterator operator-(const int &val) const { return const_iterator(ptr_ - val); }
    const_iterator &operator+=(const int &val)
    {
        ptr_ += val;
        return *this;
    }
    const_iterator &operator-=(const int &val)
    {
        ptr_ -= val;
        return *this;
    }
    int operator-(const const_iterator &other) const
    {
        return ptr_ - other.ptr_;
    }
    int operator+(const const_iterator &other) const
    {
        return ptr_ + other.ptr_;
    }

    friend class iterator;

    int operator-(const iterator& other);
    int operator+(const iterator& other);
};
