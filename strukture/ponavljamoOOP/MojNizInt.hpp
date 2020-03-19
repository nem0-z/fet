#include <algorithm>
#include <initializer_list>
#include <iostream>
class MojNizInt {
  public:
  MojNizInt() : capacity_{1}, ptr_{new int[capacity_]} {}
  MojNizInt(std::initializer_list<int> initList)
      : capacity_{initList.size()},
        ptr_{new int[initList.size()]},
        size_{initList.size()} {
    std::copy(initList.begin(), initList.end(), ptr_);
  }
  MojNizInt(const MojNizInt& other)
      : capacity_{other.capacity()},
        ptr_{new int[capacity_]},
        size_{other.size()} {
    std::copy(other.ptr_, other.ptr_ + size_, ptr_);
  }
  MojNizInt(MojNizInt&& other)
      : capacity_{other.capacity()}, ptr_{other.ptr_}, size_{other.size()} {
    other.ptr_ = nullptr;
    other.size_ = 0;
    other.capacity_ = 0;
  }
  ~MojNizInt() { delete[] ptr_; }
  MojNizInt& operator=(const MojNizInt& other) {
    if (ptr_ != other.ptr_) {
      capacity_ = other.capacity();
      ptr_ = new int[capacity_];
      size_ = other.size();
      std::copy(other.ptr_, other.ptr_ + size_, ptr_);
    }
    return *this;
  }
  MojNizInt& operator=(MojNizInt&& other) {
    if (ptr_ != other.ptr_) {
      capacity_ = other.capacity();
      ptr_ = other.ptr_;
      size_ = other.size();
      other.capacity_ = 0;
      other.ptr_ = nullptr;
      other.size_ = 0;
    }
    return *this;
  }

  int& operator[](const int& val) const { return ptr_[val]; }
  int& at(const int& val) const {
    if (val < 0 || val >= size_) throw std::out_of_range("Error!");
    return ptr_[val];
  }
  size_t size(void) const { return size_; }
  size_t capacity(void) const { return capacity_; }
  MojNizInt operator*(const int& multiplicator) const {
    auto newArr = *this;
    for (int i = 0; i < newArr.size(); ++i) {
      newArr[i] = ptr_[i] * multiplicator;
    }
    return newArr;
  }
  MojNizInt operator+(const MojNizInt& other) const {
    if (size_ != other.size()) throw std::invalid_argument("Error!");
    auto newArr = *this;
    for (int i = 0; i < newArr.size(); ++i) {
      newArr[i] = ptr_[i] + other[i];
    }
    return newArr;
  }
  MojNizInt& operator++(void) {
    for (int i = 0; i < size_; ++i) {
      ++ptr_[i];
    }
    return *this;
  }
  MojNizInt operator++(int) {
    auto tmp = *this;
    for (int i = 0; i < size_; ++i) {
      ++ptr_[i];
    }
    return tmp;
  }
  void push_back(const int& val) {
    if (capacity_ == size_) {
      capacity_ *= 2;
      auto newPtr = new int[capacity_];
      std::copy(ptr_, ptr_ + size_, newPtr);
      newPtr[size_] = val;
      delete[] ptr_;
      ptr_ = newPtr;
    } else {
      ptr_[size_] = val;
    }
    ++size_;
  }
  void pop_back(void) { --size_; }
  int& front(void) { return ptr_[0]; }
  int& back(void) { return ptr_[size_ - 1]; }

  private:
  size_t capacity_{0};
  int* ptr_{nullptr};
  size_t size_{0};
};

