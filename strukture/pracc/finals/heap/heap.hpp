#pragma once
#include <iostream>
#include <algorithm>
#include <cstddef>

template <typename T>
class heap{
  public:
    heap() : elements_{new T[100]}, size_{0} {}

    size_t size() const {return size_;}
    bool empty() const {return size_ == 0;}

    void insert(const T& value){
      elements_[++size_] = value;
      bottomUp(size_);
    }

  private:
    T* elements_;
    size_t size_;
    void topDown(int index){
      if(2*index>=size_) return;
      int leftChild = 2*index;
      int rightChild = 2*index+1;
      int greaterChild = leftChild;
      if(elements_[rightChild] > elements_[greaterChild])
        greaterChild = rightChild;
      if(elements_[index] < elements_[greaterChild])
        std::swap(elements_[index],elements_[greaterChild]);
      topDown(greaterChild);
    }
    void bottomUp(int index){
      while(index>1 && elements_[index] > elements_[index/2]){
        std::swap(elements_[index],elements_[index/2]);
        index/=2;
      }
    }
};
