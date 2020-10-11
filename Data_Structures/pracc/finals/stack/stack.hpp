#pragma once
#include <cstddef>
#include <utility>
#include <stdexcept>
#include <iostream>

template <typename T>
class stack {
  public:
  stack();
  ~stack();
  stack(const stack&);
  stack(stack&&);

  template <typename U>
  void push(U&&);
  T& top() { return head_->data_; }
  const T& top() const { return head_->data_; }
  void pop();

  size_t size() const { return size_; }
  bool empty() const { return size_ == 0; }
  void print() const;

  private:
  class Node {
public:
    T data_;
    Node* next_;
    template <typename U>
      Node(U&& value) : next_{nullptr}{
        data_ = std::forward<U>(value);
      }
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  size_t size_;
};

template <typename T>
stack<T>::stack() : size_{0}{}

template <typename T>
stack<T>::~stack(){
  Node* tmp = head_;
  while(head_){
    tmp = tmp->next_;
    delete head_;
    head_ = tmp;
  }
}

template <typename T>
stack<T>::stack(const stack<T>& other) : size_{other.size_}{
  if(!other.empty()){
    head_ = tail_ = new Node(other.head_->data_);
    Node* tmp = other.head_->next_;
    while(tmp){
      Node* toAdd = new Node(tmp->data_);
      tail_->next_ = toAdd;
      tail_ = toAdd;
      tmp = tmp->next_;
    }
  }
}

template <typename T>
template <typename U>
void stack<T>::push(U&& value){
  Node* toAdd = new Node(std::forward<U>(value));
  if(empty())
    head_ = tail_ = toAdd;
  else{
    toAdd -> next_ = head_;
    head_ = toAdd;
  }
  ++size_;
}

template <typename T>
void stack<T>::pop(){
  if(empty())
    throw std::out_of_range("Debil");
  head_ = head_->next_;
  --size_;
}

template <typename T>
void stack<T>::print() const{
  if(!empty()){
    Node* tmp = head_;
    while(tmp){
      std::cout << tmp->data_ << " ";
      tmp = tmp->next_;
    }
    std::cout << std::endl;
  }
}
