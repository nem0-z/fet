#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayList {
  private:
  T* elements_;
  size_t size_;
  size_t capacity_;

  public:
  ArrayList(size_t capacityVar = 100) : size_{0}, capacity_{capacityVar} {
    elements_ = new T[capacity_];
  }

  ArrayList(const ArrayList& other)
      : size_{other.size_}, capacity_{other.capacity_} {
    elements_ = new T[capacity_];
    std::copy(other.elements_, other.elements_ + size_, elements_);
  }

  ArrayList(ArrayList&& other)
      : elements_{other.elements_},
        size_{other.size_},
        capacity_{other.capacity_} {
    other.elements_ = nullptr;
  }

  ArrayList& operator=(const ArrayList& other) {
    if (*this != &other) {
      size_ = other.size();
      capacity_ = other.capacity();
      elements_ = new T[capacity_];
      std::copy(other.elements_, other.elements_ + size_, elements_);
    }
    return *this;
  }

  ArrayList& operator=(ArrayList&& other) {
    elements_ = other.elements_;
    size_ = other.size();
    capacity_ = other.capacity();
    other.elements_ = nullptr;
    return *this;
  }

  bool empty() const;
  bool full() const;
  int size() const { return size_; }
  int capacity() const { return capacity_; }
  void print() const;
  void reserve();
  T& back() const { return elements_[size_ - 1]; }
  T& at(int index) {
    if (index < 0 || index > size_) throw std::out_of_range("Nope!");
    return elements_[index];
  }
  T& operator[](int index) { return elements_[index]; }
  ~ArrayList() { delete[] elements_; }

  // Zadatak 1
  ArrayList<T>& push_back(const T& value);
  ArrayList<T>& pop_back();
  // Zadatak 2
  ArrayList<T>& push_front(const T& value);
  ArrayList<T>& pop_front();
  // Zadatak 3
  ArrayList<T>& insert(int index, const T& value);
  // Zadatak 4
  ArrayList<T>& invert();
  // Zadatak 5
  int find(const T& value);  // Vraca index elementa
  ArrayList<T>& replace(const T& oldValue, const T& newValue);

  class iterator;
  iterator begin() const { return iterator(elements_); }
  iterator end() const { return iterator(elements_ + size_); }
};

template <typename T>
bool ArrayList<T>::empty() const {
  if (size_)
    return false;
  else
    return true;
}

template <typename T>
bool ArrayList<T>::full() const {
  if (size_ == capacity_)
    return true;
  else
    return false;
}

template <typename T>
void ArrayList<T>::print() const {
  for (int i = 0; i < size_; ++i) std::cout << elements_[i] << " ";
  std::cout << '\n';
}

template <typename T>
void ArrayList<T>::reserve() {
  capacity_ *= 2;
  auto tmp = new T[capacity_];
  std::copy(elements_, elements_ + size_, tmp);
  delete[] elements_;
  elements_ = tmp;
}

template <typename T>
ArrayList<T>& ArrayList<T>::push_back(const T& value) {
  if (full()) reserve();
  elements_[size_++] = value;
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::pop_back() {
  --size_;
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::push_front(const T& value) {
  if (full()) reserve();
  for (int i = size_; i > 0; --i) elements_[i] = elements_[i - 1];
  elements_[0] = value;
  ++size_;
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::pop_front() {
  for (int i = 0; i < size_ - 1; ++i) elements_[i] = elements_[i + 1];
  --size_;
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::insert(int index, const T& value) {
  if (full()) reserve();
  for (int i = size_; i > index; --i) {
    elements_[i] = elements_[i - 1];
  }
  ++size_;
  elements_[index] = value;
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::invert() {
  for (int i = 0; i < size_ / 2; ++i)
    std::swap(elements_[i], elements_[size_ - 1 - i]);
  return *this;
}

template <typename T>
int ArrayList<T>::find(const T& value) {
  int index = -1;
  for (int i = 0; i < size_; ++i)
    if (value == elements_[i]) return i;
  return index;
}

template <typename T>
ArrayList<T>& ArrayList<T>::replace(const T& oldValue, const T& newValue) {
  for (int i = 0; i < size_; ++i)
    if (elements_[i] == oldValue) elements_[i] = newValue;
  return *this;
}

template <typename T>
class ArrayList<T>::iterator
    : public std::iterator<std::random_access_iterator_tag, T> {
  private:
  T* ptr_;

  public:
  iterator(T* pel) : ptr_{pel} {}
  // operator *, poredjenja, inkrement i dekrement u prefix i postfix

  T& operator*() const { return *ptr_; }

  iterator& operator++();
  iterator operator++(int) {
    iterator tmp = *this;
    ++ptr_;
    return tmp;
  }
  iterator& operator--() {
    --ptr_;
    return *this;
  }
  iterator operator--(int) {
    iterator tmp = *this;
    --ptr_;
    return tmp;
  }
  bool operator!=(iterator other) const { return ptr_ != other.ptr_; }
  bool operator==(iterator other) const { return ptr_ == other.ptr_; }
};

template <typename T>
typename ArrayList<T>::iterator& ArrayList<T>::iterator::operator++() {
  ++ptr_;
  return *this;
}
