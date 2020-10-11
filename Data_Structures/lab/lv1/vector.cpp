#include <iostream>

// razlika izmedju new i malloc je sto new moze pozvati konstruktor i logy
// malloc vraca void*

template <typename T>
class MojNiz {
  private:
  size_t capacity{100};
  size_t size_{0};
  T* data = new T[capacity];

  public:
  MojNiz() = default;
  MojNiz(const MojNiz& o)
      : capacity{o.capacity}, size_{o.size_}, data{new T[capacity]} {
    for (auto i = 0; i < size_; ++i) data[i] = o.data[i];
    // size_{4};
    // size_ = 4;
  }
  MojNiz(MojNiz&& o) : capacity{o.capacity}, size_{o.size_}, data{o.data} {
    o.capacity = 0;
    o.size_ = 0;
    o.data = nullptr;
    std::cout << "Move" << std::endl;
  }
  MojNiz& operator=(MojNiz&& o) {
    delete[] data;
    data = o.data;
    size_ = o.size_;
    capacity = o.capacity;
    o.data = nullptr;
    o.size_ = 0;
    o.capacity = 0;
    return *this;
  }
  MojNiz& operator=(const MojNiz& o) {
    // delete[] data;
    // capacity = o.capacity;
    // size_ = o.size_;
    // data = new T[capacity];
    // std::copy(o.data, o.data + size_, data);
    // return *this;
    return *this = MojNiz{o};  // MAGIC
  }
  T& operator[](size_t i) { return data[i]; }
  void push_back(T);
  ~MojNiz() { delete[] data; }
};

template <typename T>
void MojNiz<T>::push_back(T val) {
  if (size_ == capacity) {
    {
      std::cout << "Realociram" << std::endl;
    }
    capacity *= 2;
    auto tmp = new T[capacity];
    std::copy(data, data + size_, tmp);
    delete[] data;
    data = tmp;
  }
  data[size_++] = val;
}

int main(void) {
  MojNiz<int> arr;
  for (auto i = 0; i < 400; ++i) {
    arr.push_back(i);
    std::cout << arr[i] << std::endl;
  }
  MojNiz<int> arr1 = std::move(arr);
  arr = arr1;
  arr1 = std::move(arr);
  return 0;
}

