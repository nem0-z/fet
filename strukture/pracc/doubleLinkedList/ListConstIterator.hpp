#pragma once

template <typename Elem>
class StdList<Elem>::const_iterator : public std::iterator<std::forward_iterator_tag, Elem>
{
private:
    const Node *previous;
    const Node *current;

public:
    const_iterator(Node *prev = nullptr, Node *curr = nullptr) : previous{prev}, current{curr} {}

    const_iterator &operator++()
    {
        previous = current;
        if (current != nullptr)
        {
            current = current->next_;
        }
        return *this;
    }

    const_iterator &operator--()
    {
        current = previous;
        if (previous != nullptr)
            previous = previous->prev_;
        return *this;
    }

    const_iterator operator--(int)
    {
        auto tmp = *this;
        --(*this);
        return tmp;
    }
    const_iterator operator++(int)
    {
        auto tmp = *this;
        ++(*this);
        return tmp;
    }

    const Elem &operator*() const
    {
        return current->data_;
    }

    bool operator==(const const_iterator &other) const
    {
        return current == other.current;
    }

    bool operator!=(const const_iterator &other) const
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
