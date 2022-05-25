#include <iostream>
#include <memory>
#include "elem.h"

template <typename Element>
class LinkedList {
  private:
    struct Node {
      Element element_;
      std::unique_ptr<Node> next_;

      Node(const Element& element, std::unique_ptr<Node> next)
        : element_{element}, next_{std::move(next)}
      {
        std::cout<<"Node constructor"<<std::endl;
      }

      ~Node(){std::cout<<"Node destructor"<<std::endl;}
    };

    std::unique_ptr<Node> head_; //nullptr po defaultu

  public:
    void add(const Element& value)
    {
      head_ = std::make_unique<Node>(value, std::move(head_));
    }
};

El f(El e){
  std::cout<<"Function"<<std::endl;
  return e;
}

int main(int argc, char *argv[])
{
  // std::cout<<"Creating list1"<<std::endl;
  // LinkedList<int> list1;
  // std::cout<<std::endl<<"Adding integer 5"<<std::endl;
  // list1.add(5);
  // std::cout<<std::endl<<"Adding integer 1"<<std::endl;
  // list1.add(1);
  // std::cout<<std::endl<<"Adding integer 10"<<std::endl;
  // list1.add(10);

  // std::cout<<std::endl<<"Creating el"<<std::endl;
  // El el;
  // std::cout<<std::endl<<"Creating el2"<<std::endl;
  // El el2;
  // std::cout<<std::endl<<"Copy assignment"<<std::endl;
  // el = el2;
  // std::cout<<std::endl<<"Copy constructor"<<std::endl;
  // El el3 = el;
  // std::cout<<std::endl<<"Move constructor"<<std::endl;
  // El el4 = f(el);
  // std::cout<<std::endl<<"Move assignment"<<std::endl;
  // el3 = std::move(el);

  std::cout<<std::endl<<"Creating list2"<<std::endl;
  LinkedList<El> list2;
  std::cout<<std::endl<<"Adding el"<<std::endl;
  list2.add(El{});
  std::cout<<std::endl<<"Adding el"<<std::endl;
  list2.add(El{});

  std::cout<<std::endl<<"Destroying all"<<std::endl;

  return 0;
}
