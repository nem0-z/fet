#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class ArrayList {
  private:
  T* elements_;
  size_t size_;
  size_t capacity_;
  void expand() {
    capacity_ = 2 * capacity_;
    T* tmp = new T[capacity_];
    std::copy(elements_, elements_ + size_, tmp);
    delete[] elements_;
    elements_ = tmp;
  }

  public:
  ArrayList(int size = 100);
  ArrayList(const ArrayList<T>& other);
  const ArrayList<T>& operator=(const ArrayList<T>&);
  bool empty() const;
  bool full() const;
  int size() const { return size_; }
  int capacity() const { return capacity_; }
  void print() const;
  T& at(int index);
  ~ArrayList(void) { delete[] elements_; }

  // Zadatak 1
  ArrayList<T>& push_back(const T& value) {
    if (full()) expand();
    elements_[size_] = value;
    ++size_;
    return *this;
  }
  ArrayList<T>& pop_back() {
    --size_;
    return *this;
  }
  // Zadatak 2
  ArrayList<T>& push_front(const T& value) { return insert(0, value); }
  ArrayList<T>& pop_front() {
    for (int i = 0; i < size_; ++i) {
      elements_[i] = elements_[i + 1];
    }
    --size_;
    return *this;
  }
  // Zadatak 3
  ArrayList<T>& insert(int index, const T& value) {
    if (index < 0 || index >= size_)
      throw std::out_of_range("Index is out of range.");
    if (full()) expand();
    for (int i = size_; i > index; --i) elements_[i] = elements_[i - 1];
    elements_[index] = value;
    ++size_;
    return *this;
  }
  // Zadatak 4
  ArrayList<T>& invert();
  //   // T* tmp = new T[capacity_];
  //   // int j = 0;
  //   // for (int i = size_ - 1; i >= 0; --i, ++j) {
  //   //   tmp[j] = elements_[i];
  //   // }
  //   // delete[] elements_;
  //   // elements_ = tmp;
  //   for (int i = 0; i < size_ / 2; ++i)
  //   std::swap(elements_[i], elements_[size_ - i - 1]);
  //   return *this;
  // }
  // Zadatak 5
  int find(const T& value) {
    for (int i = 0; i < size_; ++i) {
      if (elements_[i] == value) return i;
    }
    return -1;
  }
  ArrayList<T>& replace(const T& oldValue, const T& newValue) {
    // U citavom nizu zamijeni stare vrijednosti sa novom
    for (int i = 0; i < size_; ++i) {
      if (elements_[i] == oldValue) {
        elements_[i] = newValue;
      }
    }
    return *this;
  }
};

template <typename T>
ArrayList<T>::ArrayList(int n) {
  n < 0 ? capacity_ = 100 : capacity_ = n;
  size_ = 0;
  elements_ = new T[capacity_];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {
  capacity_ = other.capacity();
  size_ = other.size();
  elements_ = new T[capacity_];
  for (int i = 0; i < size_; i++) elements_[i] = other.elements_[i];
}

template <typename T>
const ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
  if (this != &other) {
    delete[] elements_;
    capacity_ = other.capacity();
    size_ = other.size();
    elements_ = new T[capacity()];
    for (int i = 1; i < size_; i++) elements_[i] = other.elements_[i];
  }
  return *this;
}

template <typename T>
bool ArrayList<T>::empty() const {
  return (size_ == 0);
}

template <typename T>
bool ArrayList<T>::full() const {
  return (size_ == capacity_);
}

template <typename T>
void ArrayList<T>::print() const {
  for (int i = 0; i < size_; i++) std::cout << elements_[i] << " ";
  std::cout << std::endl;
}

template <typename T>
T& ArrayList<T>::at(int index) {
  if (index < 0 || index >= size_)
    throw std::out_of_range("Index is out of range.");
  else
    return elements_[index];
}


template <typename T>
inline ArrayList<T>& ArrayList<T>::invert() {
  for (int i = 0; i < size_ / 2; ++i)
    std::swap(elements_[i], elements_[size_ - i - 1]);
  return *this;
}
