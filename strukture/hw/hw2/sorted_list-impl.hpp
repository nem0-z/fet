#pragma once
#include "sorted_list.hpp"
#include "iterator.hpp"

template <typename T>
typename sorted_list<T>::iterator sorted_list<T>::begin()
{
    return iterator(nullptr, head_);
}

template <typename T>
typename sorted_list<T>::iterator sorted_list<T>::end()
{
    return iterator(tail_, nullptr);
}

template <typename T>
void sorted_list<T>::print() const
{
    if (empty())
    {
        std::cout << "Empty list.\n"
                  << std::endl;
        return;
    }
    Node *tmp = head_;
    while (tmp)
    {
        cout << tmp->data_ << " ";
        tmp = tmp->next;
    }
    cout << '\n';
}

template <typename T>
sorted_list<T>::sorted_list() = default;

template <typename T>
sorted_list<T>::sorted_list(const sorted_list &other) : size_{other.size_}
{
    if (!other.empty())
    {
        Node *myHead = new Node(other.head_->data_);
        head_ = myHead;
        Node *moveOther = other.head_->next;
        Node *tmp = head_;
        while (moveOther)
        {
            Node *toAdd = new Node(moveOther->data_);
            tmp->next = toAdd;
            toAdd->prev = tmp;
            moveOther = moveOther->next;
            tmp = tmp->next;
        }
        tail_ = tmp->prev;
    }
    else
    {
        head_ = tail_ = nullptr;
    }
}

template <typename T>
sorted_list<T>::sorted_list(sorted_list &&other) : head_{other.head_}, tail_{other.tail_}, size_{other.size_}
{
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
}

template <typename T>
sorted_list<T>::~sorted_list()
{
    clear();
}

template <typename T>
sorted_list<T> &sorted_list<T>::operator=(const sorted_list<T> &other)
{
    if (!other.empty() && this != &other)
    {
        clear();
        return *this = sorted_list(other);
    }
    return *this;
}

template <typename T>
sorted_list<T> &sorted_list<T>::operator=(sorted_list<T> &&other)
{
    if (this != &other)
    {
        clear();
        size_ = other.size_;
        head_ = other.head_;
        tail_ = other.tail_;
        other.head_ = nullptr;
        other.tail_ = nullptr;
        other.size_ = 0;
    }
    return *this;
}

template <typename T>
template <typename F>
void sorted_list<T>::add(F &&value)
{
    Node *toAdd = new Node(std::forward<T>(value));
    //if higher than first
    if (empty())
    {
        head_ = tail_ = toAdd;
    }
    else if (value < front())
    {
        head_->prev = toAdd;
        toAdd->next = head_;
        head_ = toAdd;
    }
    else if (value > back())
    {
        tail_->next = toAdd;
        toAdd->prev = tail_;
        toAdd->next = nullptr; //just in case
        tail_ = toAdd;
    }
    else
    {
        Node *tmp = head_;
        while (tmp)
        {
            if (value > tmp->data_)
            {
                tmp = tmp->next;
            }
            else
            {
                Node *prevNode = tmp->prev;
                prevNode->next = toAdd;
                toAdd->prev = prevNode;
                toAdd->next = tmp;
                tmp->prev = toAdd;
                break;
            }
        }
    }
    ++size_;
}

template <typename T>

typename sorted_list<T>::iterator sorted_list<T>::find(const T &value)
{
    auto it = begin();
    while (it != end())
    {
        if (*it == value)
            return it;
        ++it;
    }
    return end();
} //vraca iterator na pronadjeni ako nije naso onda end

// template<typename UnaryOpt>
// iterator find_if(const UnaryOpt&);
//
template <typename T>
void sorted_list<T>::remove(const typename sorted_list<T>::iterator &iter)
{
    // if (iter == end())
    //     throw std::out_of_range("Retard.\n");

    Node *prev = iter.prevIt;
    Node *current = iter.currentIt;
    prev->next;
    current->next;
    // prev->next = current->next;
    // std::cout << "teeest" << std::endl;
    // current->next->prev = prev;
    // std::cout << "test" << std::endl;
    // delete current;
    // --size_;
} //pazi na corner caseove
//

template <typename T>
T &sorted_list<T>::front() const
{
    return head_->data_;
}

template <typename T>
T &sorted_list<T>::back() const
{
    return tail_->data_;
}

template <typename T>
inline size_t sorted_list<T>::size() const
{
    return size_;
}

template <typename T>
inline bool sorted_list<T>::empty() const
{
    return size_ == 0;
}

template <typename T>
void sorted_list<T>::clear()
{
    if (!empty())
    {
        Node *tmp;
        while (head_)
        {
            tmp = head_->next;
            delete head_;
            head_ = tmp;
        }
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }
}