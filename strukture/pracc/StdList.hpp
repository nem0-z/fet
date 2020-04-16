#pragma once
#include <iostream>

template <typename Elem>
class StdList
{
private:
    class Node
    {
    public:
        Elem _data;
        Node *_next = nullptr;
        Node *_prev = nullptr;

        Node(Elem data = 0) : _data{data}, _next{nullptr}, _prev{nullptr} {}
    };
    uint32_t _size;
    Node *_head;
    Node *_tail;

public:
    StdList();
    StdList(const StdList &);
    StdList(StdList &&);
    ~StdList();

    StdList &operator=(const StdList &);
    StdList &operator=(StdList &&);

    StdList &insert(uint32_t);

    StdList &push_back(const Elem &);
    StdList &push_front(const Elem &);

    StdList &pop_back();
    StdList &pop_front();

    Elem &at(uint32_t);
    const Elem &at(uint32_t) const;

    inline bool empty() const;
    inline uint32_t size() const;

    void print() const;
    void clear();
};

template <typename Elem>
void StdList<Elem>::print() const
{
    if (empty())
    {
        return;
    }
    Node *tmp = _head;
    while (tmp)
    {
        std::cout << tmp->_data << " ";
        tmp = tmp->_next;
    }
    std::cout << '\n';
}

template <typename Elem>
void StdList<Elem>::clear()
{
    Node *tmp = _head;

    while (_head)
    {
        tmp = _head->_next;
        delete _head;
        _head = tmp;
    }
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
}

template <typename Elem>
StdList<Elem>::StdList() : _size{0}, _head{new Node}, _tail{new Node} {}

template <typename Elem>
StdList<Elem>::StdList(const StdList &other)
{
}

template <typename Elem>
StdList<Elem>::~StdList()
{
    clear();
}

template <typename Elem>
inline uint32_t StdList<Elem>::size() const { return _size; }

template <typename Elem>
inline bool StdList<Elem>::empty() const { return _size == 0; }

template <typename Elem>
StdList<Elem> &StdList<Elem>::push_back(const Elem &item)
{
    Node *toAdd = new Node(item);
    if (empty())
    {
        _head = toAdd;
        _tail = toAdd;
    }
    else if (_size == 1)
    {
        _head->_next = toAdd;
        _tail = toAdd;
        _tail->_prev = _head;
    }
    else
    {
        _tail->_next = toAdd;
        toAdd->_prev = _tail;
        _tail = toAdd;
        _tail->_next = nullptr;
    }

    ++_size;
    return *this;
}