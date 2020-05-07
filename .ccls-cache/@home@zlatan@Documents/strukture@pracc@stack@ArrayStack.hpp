#include <algorithm>
#include <iostream>

template <typename Elem>
class ArrayStack {
  private:
  int capacity_;
  int topIndex_;
  Elem *ptr_;

  public:
  ArrayStack();
  ArrayStack(const ArrayStack &);
  ArrayStack(ArrayStack &&);
  ~ArrayStack();

  template <typename T>
  ArrayStack &push(T &&);

  Elem pop();
  Elem &top();
  const Elem &pop() const;

  inline int size() const;
  inline bool empty() const;
  inline bool full() const;
  void print() const;

  void realocate(int);
};

template <typename Elem>
ArrayStack<Elem>::ArrayStack()
    : capacity_{1}, topIndex_{0}, ptr_{new Elem[capacity_]} {}

template <typename Elem>
ArrayStack<Elem>::~ArrayStack() {
  delete[] ptr_;
}

template <typename Elem>
ArrayStack<Elem>::ArrayStack(const ArrayStack &other)
    : capacity_{other.capacity_},
      topIndex_{other.topIndex_},
      ptr_{new Elem[capacity_]} {
  std::copy(other.ptr_, other.ptr_ + topIndex_ + 1, ptr_);
}

template <typename Elem>
ArrayStack<Elem>::ArrayStack(ArrayStack &&other)
    : capacity_{other.capacity_}, topIndex_{other.topIndex_}, ptr_{other.ptr_} {
  other.ptr_ = nullptr;
}

template <typename Elem>
template <typename T>
ArrayStack<Elem> &ArrayStack<Elem>::push(T &&val) {
  if (full()) realocate(2 * capacity_);
  ptr_[topIndex_++] = std::forward<T>(val);
}

template <typename Elem>
inline bool ArrayStack<Elem>::full() const {
  return capacity_ == topIndex_;
}

template <typename Elem>
void ArrayStack<Elem>::realocate(int capacity) {
  std::cout << "Hi" << std::endl;
  auto newArray = new Elem[capacity];
  std::copy(ptr_, ptr_ + topIndex_ + 1, newArray);
  capacity_ = capacity;
  delete[] ptr_;
  ptr_ = newArray;
}

template <typename Elem>
void ArrayStack<Elem>::print() const {
  for (int i = 0; i < topIndex_; ++i) std::cout << ptr_[i] << " ";
  std::cout << std::endl;
}

template <typename Elem>
inline int ArrayStack<Elem>::size() const {
  return topIndex_;
}

template <typename Elem>
Elem &ArrayStack<Elem>::top() {
  return ptr_[topIndex_ - 1];
}

template <typename Elem>
Elem ArrayStack<Elem>::pop() {
  // auto tmp = std::move(ptr_[topIndex_--]);
  // return tmp;
  return std::move(ptr_[topIndex_--]);
}

template <typename Elem>
inline bool ArrayStack<Elem>::empty() const {
  return topIndex_ == 0;
}

