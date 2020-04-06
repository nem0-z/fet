#include "ArrayList.hpp"

//Default constructor - O(1)
template <typename T>
ArrayList<T>::ArrayList(size_t capacityVar)
    : size_{0},
      capacity_{capacityVar},
      elements_{new T[capacity_]}
{
}

//Initializer list constructor - O(n)
template <typename T>
ArrayList<T>::ArrayList(std::initializer_list<T> initList)
    : size_{initList.size()},
      capacity_{initList.size()},
      elements_{new T[capacity_]}
{
  std::copy(initList.begin(), initList.end(), elements_);
}

//Copy constructor - O(n)
template <typename T>
ArrayList<T>::ArrayList(const ArrayList &other)
    : size_{other.size_},
      capacity_{other.capacity_},
      elements_{new T[capacity_]}
{
  std::copy(other.elements_, other.elements_ + size_, elements_);
}

//Move constructor - O(1)
template <typename T>
ArrayList<T>::ArrayList(ArrayList &&other)
    : size_{other.size_},
      capacity_{other.capacity_},
      elements_{other.elements_}
{
  other.elements_ = nullptr;
}

//Copy assignment operator - O(n)
template <typename T>
ArrayList<T> &ArrayList<T>::operator=(const ArrayList &other)
{
  if (this != &other)
  {
    delete[] elements_;
    size_ = other.size();
    capacity_ = other.capacity();
    elements_ = new T[capacity_];
    std::copy(other.elements_, other.elements_ + size_, elements_);
  }
  return *this;
}

//Move assignment operator - O(1)
template <typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList &&other)
{
  delete[] elements_;
  elements_ = other.elements_;
  size_ = other.size();
  capacity_ = other.capacity();
  other.elements_ = nullptr;
  return *this;
}

//Destructor - O(n)
template <typename T>
ArrayList<T>::~ArrayList() { delete[] elements_; }

//Size - O(1)
template <typename T>
inline int ArrayList<T>::size() const
{
  return size_;
}

//Capacity- O(1)
template <typename T>
inline int ArrayList<T>::capacity() const
{
  return capacity_;
}

//Operator[]- O(1)
template <typename T>
const T &ArrayList<T>::operator[](int index) const
{
  return elements_[index];
}

//At - O(1)
template <typename T>
const T &ArrayList<T>::at(int index) const
{
  if (index < 0 || index > size_)
    throw std::out_of_range("Nope!");
  return elements_[index];
}

//At - O(1)
template <typename T>
T &ArrayList<T>::at(int index)
{
  if (index < 0 || index > size_)
    throw std::out_of_range("Nope!");
  return elements_[index];
}

//Empty - O(1)
template <typename T>
bool ArrayList<T>::empty() const
{
  return size_ == 0;
}

//Full - O(1)
template <typename T>
bool ArrayList<T>::full() const
{
  return size_ == capacity_;
}

//Back - O(1)
template <typename T>
T &ArrayList<T>::back() const { return elements_[size_ - 1]; }

//Front - O(1)
template <typename T>
T &ArrayList<T>::front() const { return *elements_; }

//Cbegin - O(1)
template <typename T>
typename ArrayList<T>::const_iterator ArrayList<T>::cbegin() const
{
  return const_iterator(elements_);
}

//Cend - O(1)
template <typename T>
typename ArrayList<T>::const_iterator ArrayList<T>::cend() const
{
  return const_iterator(elements_ + size_);
}

//Begin - O(1)
template <typename T>
typename ArrayList<T>::iterator ArrayList<T>::begin() const
{
  return iterator(elements_);
}

//End - O(1)
template <typename T>
typename ArrayList<T>::iterator ArrayList<T>::end() const
{
  return iterator(elements_ + size_);
}

//Print - O(n)
template <typename T>
void ArrayList<T>::print() const
{
  for (auto it = begin(); it != end(); ++it)
    std::cout << *it << " ";
  std::cout << '\n';
}

//Reserve- O(n)
template <typename T>
void ArrayList<T>::reserve()
{
  capacity_ *= 2;
  auto tmp = new T[capacity_];
  std::copy(elements_, elements_ + size_, tmp);
  delete[] elements_;
  elements_ = tmp;
}

//Push back - O(1)
template <typename T>
ArrayList<T> &ArrayList<T>::push_back(const T &value)
{
  if (full())
    reserve();
  elements_[size_++] = value;
  return *this;
}

//Pop back - O(1)
template <typename T>
ArrayList<T> &ArrayList<T>::pop_back()
{
  if (!empty())
  {
    --size_;
  }
  return *this;
}

//Push front - O(n)
template <typename T>
ArrayList<T> &ArrayList<T>::push_front(const T &value)
{
  if (full())
    reserve();
  for (int i = size_; i > 0; --i)
    elements_[i] = elements_[i - 1];
  elements_[0] = value;
  ++size_;
  return *this;
}

//Pop front - O(n)
template <typename T>
ArrayList<T> &ArrayList<T>::pop_front()
{
  if (!empty())
  {
    for (int i = 0; i < size_ - 1; ++i)
      elements_[i] = elements_[i + 1];
    --size_;
  }
  return *this;
}

//Insert - O(n)
template <typename T>
ArrayList<T> &ArrayList<T>::insert(const int &index, const T &value)
{
  if (index < 0 || index > size_)
    throw std::out_of_range("Out of range index!");
  if (full())
    reserve();
  for (int i = size_; i > index; --i)
  {
    elements_[i] = elements_[i - 1];
  }
  ++size_;
  elements_[index] = value;
  return *this;
}

//Insert - this will just call O(n) insert from above
//Used for calculating index
template <typename T>
template <typename RandomAccessIter>
void ArrayList<T>::insert(const RandomAccessIter &pos, const T &value)
{
  int index = cend().operator-(pos);
  insert(index, value);
}

//Invert - O(n)
template <typename T>
ArrayList<T> &ArrayList<T>::invert()
{
  for (int i = 0; i < size_ / 2; ++i)
    std::swap(elements_[i], elements_[size_ - 1 - i]);
  return *this;
}

//Find - O(n)
template <typename T>
typename ArrayList<T>::iterator ArrayList<T>::find(const T &value)
{
  for (auto it = begin(); it != end(); ++it)
  {
    if (*it == value)
      return it;
  }
  return end();
}

//Replace - O(n)
template <typename T>
ArrayList<T> &ArrayList<T>::replace(const T &oldValue, const T &newValue)
{
  for (int i = 0; i < size_; ++i)
    if (elements_[i] == oldValue)
      elements_[i] = newValue;
  return *this;
}

//Remove- O(n)
template <typename T>
void ArrayList<T>::remove(typename ArrayList<T>::iterator pos)
{
  if (empty())
    throw std::logic_error("Empty list!");
  for (auto it1 = pos, it2 = pos + 1; it1 != end();)
  {
    *it1++ = *it2++;
  }
  --size_;
}

template <typename T>
typename ArrayList<T>::iterator ArrayList<T>::find_if(const std::function<bool(T)> &predicate)
{
  for (auto it = begin(); it != end(); ++it)
  {
    if (predicate(*it))
      return it;
  }
  return end();
}

template <typename T>
typename ArrayList<T>::iterator ArrayList<T>::remove_if(const std::function<bool(T)> &predicate)
{
  for (auto it = begin(); it != end(); ++it)
  {
    if (predicate(*it))
    {
      remove(it);
      return it;
    }
  }
  return end();
}

// Methods underneath are just overloads for different iterator types, O(1)
template <typename T>
int operator+(typename ArrayList<T>::const_iterator lhs,
              typename ArrayList<T>::iterator rhs)
{
  return lhs.ptr_ + rhs.ptr_;
}

template <typename T>
int operator-(typename ArrayList<T>::const_iterator lhs,
              typename ArrayList<T>::iterator rhs)
{
  return static_cast<int>(lhs.ptr_ - rhs.ptr_);
}

template <typename T>
int operator+(typename ArrayList<T>::iterator lhs,
              typename ArrayList<T>::const_iterator &rhs)
{
  return lhs.ptr_ + rhs.ptr_;
}

template <typename T>
int operator-(typename ArrayList<T>::iterator lhs,
              typename ArrayList<T>::const_iterator &rhs)
{
  return lhs.ptr_ - rhs.ptr_;
}