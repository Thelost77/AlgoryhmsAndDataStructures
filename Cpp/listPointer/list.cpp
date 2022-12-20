#include <iostream>
#include <utility>
#include "list.h"

template <typename T>
ListNode<T> *List<T>::insert(const T &element, ListNode<T> *position)
{
    ListNode<T> *listNode = new ListNode<T>(element);
    size_++;
    listNode->next = position;

    if (position)
    {
        listNode->prev = position->prev;
        position->prev = listNode;
    }
    else
    {
        listNode->prev = tail_;
        tail_ = listNode;
    }

    if (listNode->prev)
        listNode->prev->next = listNode;
    else
        head_ = listNode;

    return listNode;
}
template <typename T>
void List<T>::push_back(const T &element)
{
    insert(element, nullptr);
}
template <typename T>
void List<T>::push_front(const T &element)
{
    insert(element, head_);
}
template <typename T>
List<T>::~List()
{
    ListNode<T> *current(head_);
    while (current)
    {
        ListNode<T> *next(current->next);
        delete current;
        current = next;
    }
}
template <typename T>
void List<T>::print(std::ostream &os)
{
    ListNode<T> *current(head_);
    while (current)
    {
        os << current.data;
        current = current->next;
    }
}
template <typename T>
void List<T>::bubbleSort()
{
    if (size_ < 2)
        return;
    iterator itHead = this->begin();
    iterator itTail{tail_};
    for (iterator it = itHead; it != itTail; ++it)
    {
        for (iterator it2 = itTail; it2 != itHead; --it2)
        {
            iterator itCompare = it2;
            --itCompare;
            if (itCompare > it2)
                std::swap(*itCompare, *it2);
        }
    }
}
