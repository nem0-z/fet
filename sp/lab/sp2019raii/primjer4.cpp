#include <iostream>
#include <memory>
#include "elem.h"


template <typename Element>
class DoublyLinkedList {
  private:
    struct DNode {
      Element element_;
      std::shared_ptr<DNode> next_;
      std::weak_ptr<DNode> previous_;

      DNode(const Element& element, std::weak_ptr<DNode> previous,
          std::shared_ptr<DNode> next)
        : element_{element},
        previous_{previous},
        next_{std::move(next)} {
          std::cout << "DNode constructor" <<element_<<std::endl;
        }

      ~DNode() { std::cout << "DNode destructor: "<<element_<<std::endl; }
    };

    std::shared_ptr<DNode> head_;
    std::weak_ptr<DNode> tail_;

    void printRefCount(const std::shared_ptr<DNode>& sp)
    {
      std::cout<<sp.use_count()<<std::endl;
    }

  public:
    void insertFront(const Element& value)
    {
      if(!head_) {
        head_ = std::make_shared<DNode>(value, std::weak_ptr<DNode>{}, nullptr);
        tail_ = head_;
      }
      else {
        printRefCount(head_);
        auto temp = std::make_shared<DNode>(value, std::weak_ptr<DNode>{}, head_);
        printRefCount(head_);
        head_->previous_ = temp;
        head_ = temp;
      }
      printRefCount(head_);
      std::cout<< "Tail is expired: " << (tail_.expired()) << std::endl;
      std::cout << "Head is nullptr: " << (head_==nullptr) << std::endl;
    }

};

int main(int argc, char *argv[])
{
  DoublyLinkedList<int> lista;
  lista.insertFront(5);
  lista.insertFront(10);
  lista.insertFront(20);
  return 0;
}
