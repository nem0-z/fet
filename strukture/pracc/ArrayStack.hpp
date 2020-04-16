#include <iostream>

template <typename Elem>
class ArrayStack
{
private:
    int _capacity;
    int _topIndex;
    Elem *_ptr;

public:
    ArrayStack(int size = 100);
    ArrayStack(const ArrayStack &);
    ArrayStack(ArrayStack &&);
    ~ArrayStack();

    template <typename T>
    ArrayStack &push(T &&);

    Elem pop();
    Elem &top();
    const Elem &pop() const;

    inline int size() const;
    inline bool empty() const;

    void realocate(int);
};

template <typename Elem>
ArrayStack<Elem>::ArrayStack(int size) : _capacity{size}
{
}
