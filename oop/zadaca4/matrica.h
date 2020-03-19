#pragma once
#include <iostream>

template <typename T>
class Matrica {
  private:
  size_t rows_ = 0;
  size_t columns_ = 0;
  T* ptr = nullptr;

  public:
  Matrica(size_t rows, size_t columns)
      : rows_{rows}, columns_{columns}, ptr{new T[rows_ * columns_]} {}

  size_t row() const { return rows_; }
  size_t column() const { return columns_; }
  size_t dimension() const { return rows_ * columns_; }
  T& operator[](const int& pos) const { return ptr[pos]; }

  Matrica(std::initializer_list<T> initList)
      : rows_{*(initList.begin())}, columns_{*(initList.begin() + 1)} {
    const size_t dim = dimension();
    const size_t listSize = initList.size() - 2;
    ptr = new T[dim];
    if (listSize > dim) throw std::domain_error("Nope!");
    for (int i = 0; i < listSize; ++i)
      std::copy(initList.begin() + 2, initList.end(), ptr);
    // we use first 2 values from initList
    // for defining matrix dimensions
  }

  Matrica(const Matrica& other) : rows_{other.row()}, columns_{other.column()} {
    const size_t dim = dimension();
    ptr = new T[dim];
    for (int i = 0; i < dim; ++i) ptr[i] = other[i];
  }

  template <typename A>
  Matrica(const Matrica<A>& other)
      : rows_{other.row()}, columns_{other.column()} {
    const size_t dim = dimension();
    ptr = new T[dim];
    for (int i = 0; i < dim; ++i) ptr[i] = other[i];
  }

  ~Matrica() { delete[] ptr; }

  const T& operator()(const size_t& row, const size_t& column) const {
    const size_t pos = row * columns_ + column;
    return ptr[pos];
  }

  T& operator()(const size_t& row, const size_t& column) {
    const size_t pos = row * columns_ + column;
    return ptr[pos];
  }

  template <typename A>
  Matrica operator+(const Matrica<A>& other) const {
    if (other.dimension() != dimension()) throw std::domain_error("NOpe");
    Matrica<decltype(ptr[0] + other[0])> rez = *this;
    for (int i = 0; i < dimension(); ++i) {
      rez[i] = ptr[i] + other[i];
    }
    return rez;
  }
  template <typename A>
  Matrica operator-(const Matrica<A>& other) const {
    if (other.dimension() != dimension()) throw std::domain_error("NOpe");
    Matrica<decltype(ptr[0] + other[0])> rez = *this;
    for (int i = 0; i < dimension(); ++i) {
      rez[i] = ptr[i] - other[i];
    }
    return rez;
  }

  template <typename A>
  Matrica& operator+=(const Matrica<A>& other) {
    if (other.dimension() != dimension()) throw std::domain_error("NOpe");
    for (int i = 0; i < dimension(); ++i) {
      ptr[i] += other[i];
    }
    return *this;
  }
  template <typename A>
  Matrica& operator-=(const Matrica<A>& other) {
    if (other.dimension() != dimension()) throw std::domain_error("NOpe");
    for (int i = 0; i < dimension(); ++i) {
      ptr[i] -= other[i];
    }
    return *this;
  }

  Matrica operator*(const T val) const {
    Matrica rez = *this;
    for (int i = 0; i < dimension(); ++i) ptr[i] *= val;
    return rez;
  }

  Matrica& operator*(const T& val) {
    for (int i = 0; i < dimension(); ++i) ptr[i] *= val;
    return *this;
  }  // hmm

  Matrica operator/(const T val) {
    Matrica rez = *this;
    for (int i = 0; i < dimension(); ++i) ptr[i] /= val;
    return rez;
  }

  void operator*=(const T val) {
    for (int i = 0; i < dimension(); ++i) ptr[i] *= val;
  }

  void operator/=(const T val) {
    for (int i = 0; i < dimension(); ++i) ptr[i] /= val;
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, Matrica<T> matrix) {
  for (int i = 0; i < matrix.row(); ++i) {
    for (int j = i * matrix.column(); j < matrix.row() * i + matrix.column();
         ++j) {
      out << matrix[j] << " ";
    }
    out << std::endl;
  }
  return out;
}

