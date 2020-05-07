#include <iostream>

template <typename Elem>
class ListStack {
  private:
  class Node {
public:
    Node* next_ = nullptr;
    Elem data_{};

    Node(Elem data) : data_{data} {}
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  size_t size_;

  public:
  ListStack() : size_{0} {}
  ListStack(const ListStack& other) : size_{other.size_} {
    Node* start = new Node(other.head_->data_);
    head_ = start;
    Node* tmpOther = other.head_->next_;
    Node* tmp = head_;
    while (tmpOther) {
      Node* newNode = new Node(tmpOther->data_);
      tmp->next_ = newNode;
      tmp = tmp->next_;
      tmpOther = tmpOther->next_;
    }
    tail_ = tmp;
  }
  ListStack(ListStack&& other)
      : head_{other.head_}, tail_{other.tail_}, size_{other.size_} {
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }
  ~ListStack() {
    if (!empty()) {
      while (head_) {
        Node* tmp = head_->next_;
        delete head_;
        head_ = tmp;
      }
    }
  }

  inline bool empty() const { return size_ == 0; }
  inline int size() const { return size_; }

  template <typename T>
  ListStack<Elem>& push(T&& val) {
    Node* newNode = new Node(std::forward<T>(val));
    if (empty()) {
      head_ = tail_ = newNode;
    } else {
      auto tmp = head_;
      head_ = newNode;
      head_->next_ = tmp;
    }
    ++size_;
  }

  void print() const {
    if (!empty()) {
      Node* tmp = head_;
      while (tmp) {
        std::cout << tmp->data_ << " ";
        tmp = tmp->next_;
      }
    }
    std::cout << std::endl;
  }

  Elem pop() {
    auto toDelete = std::move(head_->data_);
    head_ = head_->next_;
    --size_;
    return toDelete;
  }

  Elem& top() { return head_->data_; }
};
