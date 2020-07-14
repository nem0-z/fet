#pragma once
#include <iostream>

template <typename T>
class ForwardList
{

private:
    class Node
    {
    public:
        T data_;
        Node *next;
        Node(const T &data, Node *ptr = nullptr) : data_{data}, next{ptr} {}
    };
    Node *head;
    Node *last;
    size_t size_ = 0; //why did we do this?? you knew when you did it, do you know now? uhm no need for that actually
			//you were just stupid

public:
    ForwardList();
    ForwardList(const ForwardList &);
    ForwardList(ForwardList &&);
    ForwardList &operator=(ForwardList &&other)
    {
        if (this != &other)
        {
            clear();
            head = other.head;
            last = other.last;
            size_ = other.size_;
            other.head = nullptr;
            other.last = nullptr;
        }
        return *this;
    }
    ForwardList &operator=(const ForwardList &other)
    {
        clear();
        return *this = ForwardList{other};
    }
    ~ForwardList();
    ForwardList &push_back(const T &);
    ForwardList &pop_back();
    ForwardList &push_front(const T &);
    ForwardList &pop_front();
    ForwardList &insert(int, const T &);
    bool empty() const;
    void print() const;
    void clear();
    void replace(const T &, const T &);
    int find(const T &);
    size_t size() const { return size_; }
    class iterator;
    class const_iterator;
    iterator begin();
    iterator end();
    const_iterator cbegin();
    const_iterator cend();
};

template <typename T>
void ForwardList<T>::replace(const T &oldVal, const T &newVal)
{
    Node *tmp = head;
    while (tmp)
    {
        if (tmp->data_ == oldVal)
            tmp->data_ = newVal;
        tmp = tmp->next;
    }
}

template <typename T>
int ForwardList<T>::find(const T &val)
{
    int i = 0;
    Node *tmp = head;
    while (tmp)
    {
        if (tmp->data_ == val)
            return i;
        tmp = tmp->next;
        ++i;
    }
    return -1;
}

template <typename T>
ForwardList<T> &ForwardList<T>::insert(int index, const T &val)
{
    if (index < 0 || index > size_)
        throw std::out_of_range("Ajla ne smaraj :)");
    Node *tmp = head;
    Node *newNode = new Node(val);
    while (index--)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    std::swap(newNode->data_, tmp->data_);
    return *this;
}

template <typename T>
void ForwardList<T>::clear()
{
    Node* tmp = head;
    while (head)
    {
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
    head = nullptr;
    last = nullptr; //kaze ajla cisto da se zna :)
}

template <typename T>
void ForwardList<T>::print() const
{
    Node *tmp = head;
    while (tmp)
    {
        std::cout << tmp->data_ << " ";
        tmp = tmp->next;
    }
    std::cout << '\n';
}

template <typename T>
bool ForwardList<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
ForwardList<T>::ForwardList() : head{nullptr}, last{nullptr}, size_{0} {}

template <typename T>
ForwardList<T>::ForwardList(const ForwardList &other)
{
    Node *tmp = other.head;
    while (tmp)
    {
        push_back(tmp->data_);
        tmp = tmp->next;
    }
}

template <typename T>
ForwardList<T>::ForwardList(ForwardList &&other)
    : head{other.head}, last{other.last}, size_{other.size_}
{
    other.head = nullptr;
    other.last = nullptr;
}

template <typename T>
ForwardList<T>::~ForwardList()
{
    clear();
}

template <typename T>
ForwardList<T> &ForwardList<T>::push_back(const T &val)
{
    Node *newNode = new Node(val);
    if (empty())
    {
        head = last = newNode;
    }
    else
    {
        last->next = newNode;
    }
    last = newNode;
    ++size_;
    return *this;
}

template <typename T>
ForwardList<T> &ForwardList<T>::pop_back()
{
    Node *tmp = head;
    if (empty())
        return *this;
    while (tmp->next != last)
    {
        tmp = tmp->next;
    }
    delete last;
    tmp->next = nullptr;
    last = tmp;
    --size_;
    return *this;
}

template <typename T>
ForwardList<T> &ForwardList<T>::push_front(const T &val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (empty())
        last = newNode;
    ++size_;
    return *this;
}

template <typename T>
ForwardList<T> &ForwardList<T>::pop_front()
{
    if (empty())
        return *this;
    Node *tmp = head->next;
    delete head;
    head = tmp;
    --size_;
    return *this;
}

template <typename T>
class ForwardList<T>::iterator : public std::iterator<std::forward_iterator_tag, T>
{
private:
public:
};
