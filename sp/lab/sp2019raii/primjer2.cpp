#include <iostream>
#include <memory>
#include "elem.h"

template <typename Element>
class DoublyLinkedList {
  private:
    struct DNode {
      Element element_;
      std::unique_ptr<DNode> previous_;
      std::unique_ptr<DNode> next_;

      DNode(const Element& element, std::unique_ptr<DNode> previous,
          std::unique_ptr<DNode> next)
        : element_{element},
        previous_{std::move(previous)},
        next_{std::move(next)} {
          std::cout << "DNode constructor" << std::endl;
        }

      ~DNode() { std::cout << "DNode destructor"<<std::endl; }
    };

    std::unique_ptr<DNode> head_;
    std::unique_ptr<DNode> tail_;

  public:
    void insertFront(const Element& value)
    {
      if(!head_) {
        head_ = std::make_unique<DNode>(value, nullptr, nullptr);
        tail_ = std::move(head_);
      }
      else {
        head_ = std::make_unique<DNode>(value, nullptr, std::move(head_));
      }

      std::cout<< "Tail is nullptr: " << (tail_==nullptr) << std::endl;
      std::cout << "Head is nullptr: " << (head_==nullptr) << std::endl;
    }

    void insertBack(const Element& value)
    {
      if(!tail_){
        tail_ = std::make_unique<DNode>(value, nullptr, nullptr);
        head_ = std::move(tail_);
      }
      else {
        tail_ = std::make_unique<DNode>(value, std::move(tail_), nullptr);
      }

      std::cout<< "Tail is nullptr: " << (tail_==nullptr) << std::endl;
      std::cout << "Head is nullptr: " << (head_==nullptr) << std::endl;
    }
};

int main(int argc, char *argv[])
{
  DoublyLinkedList<El> lista;
  std:: cout << "\nNew element" << std::endl;
  lista.insertFront(El{});
  std:: cout << "\nNew element" << std::endl;
  lista.insertBack(El{});
  std:: cout << "\nNew element" << std::endl;
  lista.insertFront(El{});
  std:: cout << "\nNew element" << std::endl;
  lista.insertBack(El{});
  return 0;
}
