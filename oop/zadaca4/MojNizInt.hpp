#include <algorithm>
#include <initializer_list>
#include <iostream>

class MojNizInt {
  private:
  int maxCapacity = 0;
  int* ptr = nullptr;
  int arraySize = 0;

  public:
  MojNizInt() : maxCapacity{1}, ptr{new int[maxCapacity]} {}

  int size() const { return arraySize; }

  int& at(int counter) const {
    if (counter >= arraySize || counter < 0)
      throw std::out_of_range("Out of range!");
    return ptr[counter];
  }

  size_t capacity() const { return maxCapacity; }

  MojNizInt(std::initializer_list<int> initList) {
    maxCapacity = initList.size();
    arraySize = maxCapacity;
    ptr = new int[maxCapacity];
    std::copy(initList.begin(), initList.end(), ptr);
  }

  MojNizInt(const MojNizInt& other)
      : maxCapacity{other.maxCapacity},
        ptr{new int[other.maxCapacity]},
        arraySize{other.arraySize} {
    std::copy(other.ptr, other.ptr + arraySize, ptr);
  }

  MojNizInt(MojNizInt&& other)
      : maxCapacity{other.maxCapacity},
        ptr{other.ptr},
        arraySize{other.arraySize} {
    other.ptr = nullptr;
    other.arraySize = 0;
    other.maxCapacity = 0;
  }

  ~MojNizInt() { delete[] ptr; }

  int& operator[](const int& position) const { return ptr[position]; }

  MojNizInt& operator=(const MojNizInt& other) {
    delete[] ptr;
    arraySize = other.size();
    maxCapacity = other.capacity();
    ptr = new int[maxCapacity];
    std::copy(other.ptr, other.ptr + arraySize, ptr);
    return *this;
  }

  MojNizInt& operator=(MojNizInt&& other) {
    delete[] ptr;
    ptr = other.ptr;
    arraySize = other.size();
    maxCapacity = other.capacity();
    other.ptr = nullptr;
    other.arraySize = 0;
    return *this;
  }

  MojNizInt operator*(const int& multiplicator) const {
    MojNizInt tmp;
    tmp.ptr = new int[arraySize];
    tmp.arraySize = arraySize;
    for (int i = 0; i < arraySize; ++i) {
      tmp[i] = multiplicator * (ptr[i]);
    }
    return tmp;
  }

  MojNizInt operator+(const MojNizInt& other) const {
    if (size() != other.size()) throw std::invalid_argument("Nope");
    MojNizInt tmp;
    tmp.ptr = new int[arraySize];
    tmp.arraySize = arraySize;
    for (int i = 0; i < arraySize; ++i) {
      tmp[i] = ptr[i] + (other.ptr)[i];
    }
    return tmp;
  }

  MojNizInt operator++(int) {
    MojNizInt tmp = *this;
    for (int i = 0; i < arraySize; ++i) ++ptr[i];
    return tmp;
  } // postfix operator++

  MojNizInt& operator++() {
    for (int i = 0; i < arraySize; ++i) ++ptr[i];
    return *this;
  } //prefix operator++

  void push_back(const int& val) {
    if (maxCapacity == arraySize) {
      maxCapacity *= 2;
      auto tmp = new int[maxCapacity];
      std::copy(ptr, ptr + arraySize, tmp);
      tmp[arraySize] = val;
      delete[] ptr;
      ptr = tmp;
    } else {
      ptr[arraySize] = val;
    }
    ++arraySize;
  }

  void pop_back() { --arraySize; }

  int& back() { return ptr[arraySize - 1]; }

  int& front() { return ptr[0]; }
};
