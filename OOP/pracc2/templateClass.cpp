#include <iostream>

template <typename T>
class myArr {
  private:
  size_t size;
  T* ptr;

  public:
  T& operator[](int pos) const {return ptr[pos];}
  size_t getSize() const {return size;}

  myArr(size_t a) : size{a}, ptr{new T[size]} {
    for(int i = 0 ; i<size; ++i) ptr[i] = 2;
  }
  myArr(const myArr& other) : size{other.size}, ptr{new T[size]} {
    std::copy(other.ptr, other.ptr + size, ptr);
  }
  template<typename A>
    myArr(const myArr<A>& other) : size{other.getSize()}, ptr{new T[size]} {
      // for(int i = 0; i<size; ++i) ptr[i] = other[i];
    }
  myArr(myArr&& other) : size{other.size}, ptr{new T[size]} {
    std::cout<<1<<std::endl;
  }

  template<typename A>
    myArr(myArr<A>&& other)  {
      std::cout<<2<<std::endl;
    }

};

template<typename T>
void printArr(myArr<T> array) {
  for(int i = 0 ; i<array.getSize(); ++i) 
    std::cout<<array[i]<<" ";
  std::cout<<"\n\n";
}

int main(int argc, char* argv[]) {
  myArr<int> x(5);  
  printArr(x);
  myArr<double> c = x;
  printArr(c);
  myArr<short> y = std::move(x);
  return 0; 
}

