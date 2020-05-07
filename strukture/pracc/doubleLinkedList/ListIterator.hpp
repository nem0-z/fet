#pragma once

template <typename Elem>
class StdList<Elem>::iterator : public std::iterator<std::forward_iterator_tag, Elem>
{
private:
    Node *previous;
    Node *current;

public:
    iterator(Node *prev = nullptr, Node *curr = nullptr) : previous{prev}, current{curr} {}

    iterator &operator++()
    {
        previous = current;
        if (current != nullptr)
        {
            current = current->next_;
        }
        return *this;
    }
    iterator operator++(int)
    {
        auto tmp = *this;
        ++(*this);
        return tmp;
    }

    iterator &operator--()
    {
        current = previous;
        if (previous != nullptr)
            previous = previous->prev_;
        return *this;
    }

    iterator operator--(int)
    {
        auto tmp = *this;
        --(*this);
        return tmp;
    }

    Elem &operator*()
    {
        return current->data_;
    }
    const Elem &operator*() const
    {
        return current->data_;
    }

    bool operator==(const iterator &other) const
    {
        return current == other.current;
    }

    bool operator!=(const iterator &other) const
    {
        return current != other.current;
    }

    bool isBegin() const
    {
        return current != nullptr && previous == nullptr;
    }

    bool isEnd() const
    {
        return current == nullptr && previous != nullptr;
    }
    friend class StdList;
};