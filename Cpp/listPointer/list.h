#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>
template <typename T>
struct ListNode
{
    ListNode(const T &element) : data(element), next(nullptr), prev(nullptr)
    {
    }

    T data;
    ListNode<T> *next;
    ListNode<T> *prev;
};
#endif

#ifndef LIST_H
#define LIST_H
#include <iostream>
template <typename T>
class List
{
    public:
        List() : head_(nullptr), tail_(nullptr), size_(0) {}

        int size() { return size_; }
        void push_front(const T &element);
        void push_back(const T &element);
        ListNode<T> *insert(const T &element, ListNode<T> *position);
        void print(std::ostream &os);
        void bubbleSort();
        ~List();
        class iterator
        {
        private:
            ListNode<T> *pos_;

        public:
            iterator(ListNode<T> *pos = nullptr) : pos_(pos){};
            T &operator*()
            {
                return pos_->data;
            }
            T *operator->()
            {
                return &(pos_->data);
            }
            bool operator!=(const iterator &rhs)
            {
                return pos_ != rhs.pos_;
            }
            bool operator>(const iterator &rhs)
            {
                return pos_->data > rhs.pos_->data;
            }
            iterator operator++()
            {
                pos_ = pos_->next;
                return *this;
            }
            iterator operator--()
            {
                pos_ = pos_->prev;
                return *this;
            }
        };
        class reverse_iterator
        {
        public:
            reverse_iterator(ListNode<T> *p = nullptr) : pos_(p) {}

            T &operator*()
            {
                return pos_->data;
            }

            T *operator->()
            {
                return &(pos_->data);
            }

            bool operator!=(const reverse_iterator &rhs)
            {
                return this->pos_ != rhs.pos_;
            }

            bool operator>(const iterator &rhs)
            {
                return pos_->data > rhs.pos_->data;
            }

            reverse_iterator operator++()
            {
                pos_ = pos_->prev;
                return *this;
            }

            reverse_iterator operator--()
            {
                pos_ = pos_->next;
                return *this;
            }

        private:
            ListNode<T> *pos_;
        };

        reverse_iterator reverseBegin()
        {
            return reverse_iterator(tail_);
        }

        reverse_iterator reverseEnd()
        {
            return reverse_iterator(nullptr);
        }

        iterator begin()
        {
            return iterator(head_);
        }
        iterator end()
        {
            return iterator(nullptr);
        }

    private:
        ListNode<T> *head_;
        ListNode<T> *tail_;
        int size_;
};
#endif
