#include <algorithm>
#include <iostream>

//TODO when you get more time, circular buffer looks interesting
template <typename Elem>
class ArrayQueue {
  private:
  int capacity_;
  size_t lo = 0;
  size_t hi = 0;
  size_t size_ = 0;
  Elem *ptr_;

  public:
  ArrayQueue();
  ArrayQueue(const ArrayQueue &);
  ArrayQueue(ArrayQueue &&);
  ~ArrayQueue();

  template <typename T>
  ArrayQueue &push(T &&);

  Elem pop();
  Elem &top();
  const Elem &top() const;

  inline int size() const;
  inline bool empty() const;
  inline bool full() const;
  void print() const;

  void realocate(int);
};

template <typename Elem>
ArrayQueue<Elem>::ArrayQueue() : capacity_{10}, ptr_{new Elem[capacity_]} {}

template <typename Elem>
ArrayQueue<Elem>::~ArrayQueue() {
  delete[] ptr_;
}

template <typename Elem>
ArrayQueue<Elem>::ArrayQueue(const ArrayQueue &other)
    : capacity_{other.capacity_},
      lo{other.lo},
      hi{other.hi},
      size_{other.size_},
      ptr_{new Elem[capacity_]} {
  std::copy(other.ptr_ + lo, other.ptr_ + hi, ptr_);
}

template <typename Elem>
ArrayQueue<Elem>::ArrayQueue(ArrayQueue &&other)
    : capacity_{other.capacity_},
      lo{other.lo},
      hi{other.hi},
      size_{other.size_},
      ptr_{other.ptr_} {
  other.ptr_ = nullptr;
}

template <typename Elem>
template <typename T>
ArrayQueue<Elem> &ArrayQueue<Elem>::push(T &&val) {
  if (full()) realocate(2 * capacity_);
  if (!empty()) {
    hi = (hi + 1) % capacity_;
    ptr_[hi - 1] = std::forward<T>(val);
  } else {
    lo = hi = 0;
    ptr_[hi++] = std::forward<T>(val);
  }
  ++size_;
  return *this;
}

template <typename Elem>
inline bool ArrayQueue<Elem>::full() const {
  return size_ == capacity_;
}

template <typename Elem>
void ArrayQueue<Elem>::realocate(int capacity) {
  auto tmp = new Elem[capacity];
  std::copy(ptr_,ptr_+capacity_,tmp);
  capacity_ = capacity;
  ptr_ = tmp;
}

template <typename Elem>
void ArrayQueue<Elem>::print() const {
  std::cout << "How it should look like: " << std::endl;
  for (int i = lo; i < hi; ++i) {
    std::cout << ptr_[i] << " ";
  }
  std::cout << "Lo: " << lo << " Hi: " << hi << std::endl;
  std::cout << "\nActual representation of an array: " << std::endl;
  for (int i = 0; i < capacity_; ++i) {
    std::cout << ptr_[i] << " ";
  }
  std::cout << std::endl << std::endl;
}

template <typename Elem>
inline int ArrayQueue<Elem>::size() const {}

template <typename Elem>
Elem &ArrayQueue<Elem>::top() {}

template <typename Elem>
Elem ArrayQueue<Elem>::pop() {
  size_t toPop = lo;
  lo = (lo + 1) % capacity_;
  --size_;
  return std::move(ptr_[toPop]);
}

template <typename Elem>
inline bool ArrayQueue<Elem>::empty() const {
  return size_ == 0;
}

