#include <iostream>
#include <initializer_list>

namespace test{

  struct vector{

    public:

    vector() = default;

    vector(std::initializer_list<int> lista)
    {
      size = lista.size();
      ptr = new int[size];
      std::copy(lista.begin(),lista.end(),ptr);
    }

    vector(const int& counter, const int& value)
    {
      size = counter;
      ptr = new int[size];
      for(auto i = 0; i < size; ++i)
        ptr[i] = value;
    }

    vector(const vector& drugi)
    {
      size = drugi.size;
      ptr = new int[size];
      std::copy(drugi.ptr,drugi.ptr+size,ptr);
    }

    vector(vector&& drugi)
    {
      size = drugi.size;
      ptr = drugi.ptr;
      drugi.size = 0;
      drugi.ptr = nullptr;
    }
    
    ~vector()
    {
      delete [] ptr;
    }
    
    int* begin ()
    {
      return ptr;
    }

    int* end ()
    {
      return ptr+size;
    }

    int& at(const int& position)
    {
      if(position>=size) 
        throw std::out_of_range("Out of range!");
      else
      return ptr[position];
    }

    size_t& checkSize()
    {
      return size;
    }

    void push_back(const int& val)
    {
      size+=1;
      int* pbptr = new int[size];
      std::copy(ptr,ptr+size-1,pbptr);
      delete [] ptr;
      pbptr[size-1] = val;
      ptr = pbptr;
      
    }

    vector& operator=(const vector& drugi)
    {
	    delete [] ptr;
      size = drugi.size;
      ptr = new int[size];
      std::copy(drugi.ptr,drugi.ptr+size,ptr);
      return *this;
    }

    vector& operator=(vector&& drugi)
    {
      delete[] ptr;
      ptr = drugi.ptr;
      size = drugi.size;
      drugi.size = 0;
      drugi.ptr = nullptr;
      return *this;
    }

    private:
    size_t size;
    int* ptr;

  };

}

int main(void)
{
  test::vector foo{5,2,1};
  for(const auto& x:foo) std::cout<<x<<" ";
  foo = test::vector{5,1};
  for(const auto& x:foo) std::cout<<x<<" ";
  return 0;
}
