#include <algorithm>
#include <initializer_list>
#include <iostream>

template <typename T>

class MojNiz {
  private:
  size_t maxCapacity = 0;
  T* ptr = nullptr;
  size_t arraySize = 0;

  public:
  MojNiz() : maxCapacity{1}, ptr{new T[maxCapacity]} {}

  size_t size() const { return arraySize; }

  T& at(int counter) const {
    if (counter >= arraySize || counter < 0)
      throw std::out_of_range("Out of range!");
    return ptr[counter];
  }

  size_t capacity() const { return maxCapacity; }

  MojNiz(std::initializer_list<T> initList)
      : maxCapacity{initList.size()},
        ptr{new T[maxCapacity]},
        arraySize{initList.size()} {
    std::copy(initList.begin(), initList.end(), ptr);
  }

  template <typename A>
  MojNiz(const MojNiz<A>& other)
      : maxCapacity{other.capacity()},
        ptr{new T[maxCapacity]},
        arraySize{other.size()} {
    for (int i = 0; i < arraySize; ++i) ptr[i] = other[i];
  }

  MojNiz(const MojNiz& other)
      : maxCapacity{other.capacity()},
        ptr{new T[maxCapacity]},
        arraySize{other.size()} {
    for (int i = 0; i < arraySize; ++i) ptr[i] = other[i];
  }

  template <typename A>
  MojNiz(MojNiz<A>&& other) noexcept
      : maxCapacity{other.capacity()},
        ptr{new T[maxCapacity]},
        arraySize{other.size()} {
  } // why is this one not used when moving two diff types?

  MojNiz(MojNiz&& other)
      : maxCapacity{other.maxCapacity},
        ptr{other.ptr},
        arraySize{other.arraySize} {
    other.ptr = nullptr;
    other.arraySize = 0;
    other.maxCapacity = 0;
  }

  ~MojNiz() { delete[] ptr; }

  T& operator[](const int& position) const { return ptr[position]; }

  template <typename A>
  MojNiz& operator=(const MojNiz<A>& other) {
    delete[] ptr;
    arraySize = other.size();
    maxCapacity = other.capacity();
    ptr = new T[maxCapacity];
    for (int i = 0; i < arraySize; ++i) ptr[i] = other[i];
    return *this;
  }

  MojNiz& operator=(MojNiz&& other) {
    delete[] ptr;
    ptr = other.ptr;
    arraySize = other.arraySize;
    maxCapacity = other.maxCapacity;
    other.ptr = nullptr;
    other.arraySize = 0;
    return *this;
  }

  MojNiz operator*(const int& multiplicator) const {
    MojNiz tmp;
    tmp.ptr = new T[arraySize];
    tmp.arraySize = arraySize;
    for (int i = 0; i < arraySize; ++i) {
      tmp[i] = multiplicator * (ptr[i]);
    }
    return tmp;
  }

  template <typename A>
  auto operator+(const MojNiz<A>& other)
      -> MojNiz<decltype(ptr[0] + other[0])> const {
    if (arraySize != other.size()) throw std::invalid_argument("Nope");
    MojNiz<decltype(ptr[0] + other[0])> tmp = *this;
    for (int i = 0; i < arraySize; ++i) tmp[i] = ptr[i] + other[i];
    return tmp;
  } //is there any way to shorten this decltype thing

  MojNiz operator++(int) {
    MojNiz tmp = *this;
    for (int i = 0; i < arraySize; ++i) ++ptr[i];
    return tmp;
  }

  MojNiz& operator++() {
    for (int i = 0; i < arraySize; ++i) ++ptr[i];
    return *this;
  }

  void push_back(const int& val) {
    if (maxCapacity == arraySize) {
      maxCapacity *= 2;
      auto tmp = new T[maxCapacity];
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
