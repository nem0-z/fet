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
  ArrayList(int size = 100);
  ArrayList(const ArrayList<T>& other);
  const ArrayList<T>& operator=(const ArrayList<T>&);
  bool empty() const;
  bool full() const;
  int size() const { return size_; }
  int capacity() const { return capacity_; }
  void print() const;
  T& at(int index);
  T& operator[](int index);
  ~ArrayList(void) { delete[] elements_; }

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
};

template <typename T>
T& ArrayList<T>::operator[](int index){
  if (index < 0 || index >= size_)
    throw std::out_of_range("Index is out of range.");
  else
    return elements_[index];elements_[index];
}


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
ArrayList<T>& ArrayList<T>::push_back(const T& value){
  if(capacity_ == size_){
    capacity_*=2;
    auto p = new T[capacity_];
    delete [] elements_;
    elements_ = p;
  }
  elements_[size_++] = value;
  return *this;
}
template <typename T>
ArrayList<T>& ArrayList<T>::pop_back(){
  --size_;
  auto p = new T[size_];
  std::copy(elements_,elements_+size_,p);
  delete [] elements_;
  elements_ = p;
  return *this;
  }

template <typename T>
ArrayList<T>& ArrayList<T>::push_front(const T& value){
  if(capacity_ == size_){
    capacity_*=2;
    auto p = new T[capacity_];
    delete [] elements_;
    elements_ = p;
  }
  ++size_;
  for(int i = size_; i>0; --i) elements_[i] = elements_[i-1];
  elements_[0] = value;
  return *this;
}

template <typename T>
ArrayList<T>&  ArrayList<T>::pop_front(){
  --size_;
  auto p = new T[size_];
  std::copy(elements_+1,elements_+size_+1,p);
  delete [] elements_;
  elements_ = p;
  return *this;
}

template <typename T>
ArrayList<T>& ArrayList<T>::insert(int index, const T& value){
  if(capacity_ == size_){
    capacity_*=2;
    auto p = new T[capacity_];
    delete [] elements_;
    elements_ = p;
  }
  size_++;
  for(int i = size_; i>index ; --i) elements_[i] = elements_[i-1];
  elements_[index] = value;
  return *this;
}


template<typename T>
ArrayList<T>& ArrayList<T>::invert(){
  for(int i = 0; i<size_/2; ++i)
  std::swap(elements_[i],elements_[size_ - 1 - i]);
  return *this;
}
 
template<typename T>
int ArrayList<T>::find(const T& value){
  for(int i = 0; i<size_; ++i)
    if(elements_[i] == value) return i;
  return -1;
}  // Vraca index elementa


template<typename T>
ArrayList<T>& ArrayList<T>::replace(const T& oldValue, const T& newValue){
  const int pos = find(oldValue);
  elements_[pos] = newValue;
  return *this;
}