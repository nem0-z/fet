#include <algorithm>
#include <initializer_list>
#include <iostream>
#include <iterator>

template <typename T>
class nasVektor {
  public:
  nasVektor() = default;
  nasVektor(int d, int g) : d_{d}, g_{g}, ptr_{new T[g_ - d_ + 1]} {}
  nasVektor(std::initializer_list<T> initList)
      : d_{0}, g_{initList.size() - 1}, ptr_{new T[g_ + 1]} {
    std::copy(initList.begin(), initList.end(), ptr_);
  }
  nasVektor(std::initializer_list<T> initList, int d = 0)
      : d_{d}, g_{d_ + initList.size() - 1}, ptr_{new T[g_ - d_ + 1]} {
    std::copy(initList.begin(), initList.end(), ptr_);
  }
  nasVektor(const nasVektor& o) {
    d_ = o.d_;
    g_ = o.g_;
    const int size = g_ - d_ + 1;
    ptr_ = new T[size];
    for (int i = 0; i < size; ++i) {
      ptr_[i] = o.ptr_[i];
    }
  }
  nasVektor(nasVektor&& o) : d_{o.d_}, g_{o.g_}, ptr_{o.ptr_} {
    o.ptr_ = nullptr;
  }
  ~nasVektor() { delete[] ptr_; }

  nasVektor& operator=(const nasVektor& o) {
    d_ = o.d_;
    g_ = o.g_;
    const int size = g_ - d_ + 1;
    ptr_ = new T[size];
    for (int i = 0; i < size; ++i) {
      ptr_[i] = o.ptr_[i];
    }
    return *this;
  }
  nasVektor& operator=(nasVektor& o) {
    delete[] ptr_;
    ptr_ = o.ptr_;
    d_ = o.d_;
    g_ = o.g_;
    o.ptr_ = nullptr;
    o.d_ = 0;
    o.g_ = 0;
    return *this;
  }
  T& operator[](int index) {
    if (index < d_ || index > g_) {
      const char* str = "Out of range";
      throw std::out_of_range(str);
    }
    return ptr_[index - d_];
  }
  const T& operator[](int index) const {
    if (index < d_ || index > g_) {
      const char* str = "Out of range";
      throw std::out_of_range(str);
    }
    return ptr_[index - d_];
  }
  void realociraj(int d, int g) {
    if (g < d) throw std::invalid_argument("Glup si");
    T* noviNiz = new T[g - d + 1];
    delete[] ptr_;
    ptr_ = noviNiz;
    d_ = d;
    g_ = g;
  }
  int donja_granica() const { return d_; }
  int gornja_granica() const { return g_; }
  int size() const { return g_ - d_ + 1; }
  class iterator;
  iterator begin() { return iterator(ptr_); }
  iterator end() { return iterator(ptr_ + size()); }

  private:
  int d_, g_;  // donja i gornja granica
  T* ptr_;
};

template <typename T>
class nasVektor<T>::iterator {  // iterator_category,value_type,difference_type,pointer,reference
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using difference_type = T;
  using pointer = T*;
  using reference = T&;

  iterator(T* p) : pel{p} {}

  T& operator*() { return *pel; }
  iterator& operator++() {
    ++pel;
    return *this;
  }
  iterator operator++(int) {
    auto tmp = *this;
    ++pel;
    return tmp;
  }
  iterator& operator--() {
    --pel;
    return *this;
  }
  iterator operator--(int) {
    auto tmp = *this;
    --pel;
    return tmp;
  }
  bool operator!=(const iterator& o) const { return pel != o.pel; }
  bool operator==(const iterator& o) const { return pel == o.pel; }

  private:
  T* pel;
};

int main() {
  nasVektor<int> vec;
  return 0;
}
