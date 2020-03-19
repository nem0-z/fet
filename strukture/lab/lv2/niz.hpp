#ifndef _NIZ_
#define _NIZ_

#include <algorithm>
#include <cstdio>
#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class MojNiz {
  private:
  size_t capacity_ = 100;
  size_t size_ = 0;
  T* data_ = new T[capacity_];

  public:
  MojNiz() = default;
  MojNiz(const std::initializer_list<T>&);
  MojNiz(const MojNiz&);
  MojNiz(MojNiz&&);
  MojNiz& operator=(const MojNiz&);
  MojNiz& operator=(MojNiz&&);
  ~MojNiz();
  T& operator[](int index);
  const T& operator[](int index) const;
  size_t size() const { return size_; }
  void push_back(T x);

  class iterator;

  iterator begin() { return iterator(data_); }
  iterator end() { return iterator(data_ + size_); }
  void resize(size_t new_size);
  iterator erase(iterator pos);
  iterator erase(iterator begin, iterator end);
};

template <typename T>
MojNiz<T>::MojNiz(const MojNiz<T>& other)
    : capacity_{other.capacity_}, size_{other.size_}, data_{new T[capacity_]} {
  std::copy(other.data_, other.data_ + other.size_, data_);
}

template <typename T>
MojNiz<T>::MojNiz(const std::initializer_list<T>& other)
    : size_{other.size()}, capacity_{other.capacity_}, data_{new T[capacity_]} {
  std::copy(other.data_, other.data_ + other.size_, data_);
}

template <typename T>
MojNiz<T>::~MojNiz() {
  delete[] data_;
}

template <typename T>
MojNiz<T>& MojNiz<T>::operator=(MojNiz<T>&& other) {
  size_ = other.size_;
  std::swap(data_, other.data_);
  return *this;
}

template <typename T>
MojNiz<T>& MojNiz<T>::operator=(const MojNiz<T>& other) {
  return *this = MojNiz<T>{other};
}

template <typename T>
T& MojNiz<T>::operator[](int index) {
  return data_[index];
}

template <typename T>
const T& MojNiz<T>::operator[](int index) const {
  return data_[index];
}

template <typename T>
void MojNiz<T>::push_back(T x) {
  if (size_ == capacity_) {
    capacity_ *= 2;
    auto temp = new T[capacity_];
    std::copy(data_, data_ + size_, temp);
    delete[] data_;
    data_ = temp;
  }
  data_[size_++] = x;
}

// Defined in header <iterator>
// struct input_iterator_tag { };
// struct output_iterator_tag { };
// struct forward_iterator_tag : public input_iterator_tag { };
// struct bidirectional_iterator_tag : public forward_iterator_tag { };
// struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template <typename T>
class MojNiz<T>::iterator
    : public std::iterator<std::random_access_iterator_tag, T> {
  private:
  T* pel_;

  public:
  iterator(T* p) : pel_(p) {}

  // TODO
  T& operator*() { return *pel_; }
  const T& operator*() const { return *pel_; }
  iterator& operator++() {
    ++pel_;
    return *this;
  }
  iterator operator++(int) {
    auto tmp = pel_;
    ++pel_;
    return iterator(tmp);
    // iterator tmp(pel_);
    //++pel;
    // return tmp;
  }
  iterator& operator--() {
    --pel_;
    return *this;
  }
  iterator operator--(int) {
    auto tmp = pel_;
    --pel_;
    return iterator(tmp);
  }
  bool operator==(const iterator& b) const { return pel_ == b.pel_; }
  bool operator!=(const iterator& b) const {
    return pel_ != b.pel_;
    // return !(*this == b.pel_); // on je uradio ovako da iskoristi gornji
    // metod "cisto iz zezancije" HAHAHAHA flex
  }
  bool operator<(const iterator& b) const { return pel_ < b.pel_; }
  bool operator>(const iterator& b) const { return pel_ > b.pel_; }
  iterator operator+(const int& a) const { return iterator(pel_ + a); }
  iterator& operator+=(const int& a) {
    pel_ += a;  // zasto ne a*sizeof(T)?
    return *this;
  }
  iterator operator-(const int& a) const { return iterator(pel_ - a); }
  iterator& operator-=(const int& a) {
    pel_ -= a;
    return *this;
  }
  // auto it1 = niz.begin();
  // auto it2 = niz.end();
  // auto x = it2 - it1; //x = sizeof(niz)
  // it2 -> this
  // it1 -> a
  int operator-(const iterator& a) const { return pel_ - a.pel_; }
};

template <typename T>
void MojNiz<T>::resize(size_t new_size) {
  if (new_size == size_)
    return;
  else if (new_size > size_) {
    size_t itemsToAdd = new_size - size_;
    while (itemsToAdd != 0) {
      push_back(T{});
      --itemsToAdd;
    }  // ovo smo radili da bi iskoristili push_back jer on
    // managea capacity i to sve, da ne bi mi morali rucno
  } else {
    size_ = new_size;
  }
}

template <typename T>
typename MojNiz<T>::iterator MojNiz<T>::erase(MojNiz<T>::iterator pos) {
  // moze i da uzmes zadnji clan stavis na tu poziciju i smanjis size
  // ali onda relativna pozicija elemenata nece biti sustained
  // pazi na corner caseove
  iterator it1(pos), it2(pos + 1);
  while (it1 != end()) {
    std::swap(*it1++, *it2++);
  }
  --size_;
  return iterator(pos);
}
// moramo dodati typename ispred jer vracamo objekat unutar klase koja je
// genericka -> compiler requirement

template <typename T>
typename MojNiz<T>::iterator MojNiz<T>::erase(MojNiz<T>::iterator begin,
                                              MojNiz<T>::iterator end) {
  //TODO
}


#endif
