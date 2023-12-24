#pragma once

#include <iostream>
#include <memory>
#include "node.h"
#include "allocator.h"

template <typename T, class Allocator = PoolAllocator<Node<T>>>
class Queue{
    private:
        Node<T> *head;
        Node<T> *tail;
        size_t _size;
        Allocator _alloc;
    public:
        Queue();
        Queue(const std::initializer_list<T> &l);
        Queue(const Queue &other);
        Queue(Queue &&other) noexcept;
        ~Queue();
        Queue<T, Allocator> &operator=(Queue<T, Allocator> &other);
        Queue<T, Allocator> &operator=(Queue<T, Allocator> &&other) noexcept;
        size_t size() const;
        bool empty() const;
        void push(T value);
        void push_range(const std::initializer_list<T> &l);
        T pop();
        T front() const;
        T back() const;
        bool operator==(const Queue<T, Allocator> &other) const;
        bool operator!=(const Queue<T, Allocator> &other) const;
        bool operator<(const Queue<T, Allocator> &other) const;
        bool operator>(const Queue<T, Allocator> &other) const;
        friend std::ostream &operator << (std::ostream &os, const Queue<T, Allocator> &q) {
            if(q.empty()){
                return os << "[]";
            }
            os << '[';
            Node<T> *cur = q.head;
            while (cur->next) {
                os << cur->data << ", ";
                cur = cur->next;
            }
            os << cur->data << ']' << std::endl;
            return os;
        }
        class Iterator {
            private:
                Node<T> * node;
            public:
                Iterator(Iterator &other);
                Iterator(Node<T> *new_node);
                ~Iterator() = default;                
                Queue::Iterator &operator ++();
                Queue::Iterator &operator + (size_t n);
                T& operator*() const;
                bool operator ==(const Iterator &other) const;
                bool operator !=(const Iterator &other) const;
                Queue::Iterator &operator=(const Iterator &other);

        };

        class ConstIterator {
            private:
                const Node<T> *node;
            public:
                ConstIterator(ConstIterator &other);
                ConstIterator(Node<T> *new_node);
                ~ConstIterator() = default; 
                Queue::ConstIterator &operator ++();
                Queue::ConstIterator &operator + (size_t n);
                const T& operator *() const;
                bool operator ==(const ConstIterator &other) const;
                bool operator !=(const ConstIterator &other) const;
                Queue::ConstIterator &operator=(const ConstIterator &other);
        };
        Queue::Iterator begin();
        Queue::Iterator end();
        Queue::ConstIterator cbegin();
        Queue::ConstIterator cend();
};


template <typename T, class Allocator>
Queue<T, Allocator>::Queue() : head(nullptr), _size(0), tail(nullptr), _alloc() {}

template <typename T, class Allocator>
Queue<T, Allocator>::Queue(const std::initializer_list<T> &l) {
    head = _alloc.allocate();
    head->data = *l.begin();
    _size = l.size();
    Node<T> *cur = head;
    for (auto elem = l.begin() + 1; elem != l.end(); elem++) {
        cur->next = _alloc.allocate();
        cur->next->data = *elem;
        cur = cur->next;
    }
    tail = cur;
    cur->next = nullptr;
}

template <typename T, class Allocator>
Queue<T, Allocator>::Queue(const Queue<T, Allocator> &other) {
    if(other.empty()){
        _size = 0;
        tail = head = nullptr;
        return;
    }
    _size = other._size;
    head = _alloc.allocate();
    head->data = other.head->data;
    Node<T> * cur = head;
    Node<T> * other_cur = other.head;
    while(other_cur->next != nullptr){
        cur->next = _alloc.allocate();
        cur->next->data = other_cur->next->data;
        cur = cur->next;
        other_cur = other_cur->next;
    }
    tail = cur;
    cur->next = nullptr;
}


template <typename T, class Allocator>
Queue<T, Allocator>::~Queue(){
    while (head != NULL) {
        if (head == tail) {
            _alloc.deallocate(tail);
            head = tail = nullptr;
            _size = 0;
            return;
        }
        Node<T> *tmp = head;
        head = tmp->next;
        _size--;
        _alloc.deallocate(tmp);
    }
}

template <typename T, class Allocator>
Queue<T, Allocator>::Queue(Queue<T, Allocator> &&other) noexcept{
    _size = other._size;
    head = other.head;
    tail = other.tail;
    other._size = 0;
    other.tail = nullptr;
    other.head = nullptr;
    _alloc = std::move(other._alloc);
}

template<typename T, class Allocator>
Queue<T, Allocator> &Queue<T, Allocator>::operator=(Queue<T, Allocator> &other) {
    if(other.empty()){
        _size = 0;
        tail = head = nullptr;
        return *this;
    }
    _size = other._size;
    head = _alloc.allocate();
    head->data = other.head->data;
    Node<T> * cur = head;
    Node<T> * other_cur = other.head;
    while(other_cur->next != nullptr){
        cur->next = _alloc.allocate();
        cur->next->data = other_cur->next->data;
        cur = cur->next;
        other_cur = other_cur->next;
    }
    tail = cur;
    cur->next = nullptr;
    return *this;
}

template<typename T, class Allocator>
Queue<T, Allocator> &Queue<T, Allocator>::operator=(Queue<T, Allocator> &&other) noexcept {
    _size = other._size;
    head = other.head;
    tail = other.tail;
    other._size = 0;
    other.head = nullptr;
    other.tail = nullptr;
    _alloc = std::move(other._alloc);
    return *this;
}

template<typename T, class Allocator>
size_t Queue<T, Allocator>::size() const{
    return _size;
}

template<typename T, class Allocator>
bool Queue<T, Allocator>::empty() const {
    return _size == 0;
}

template<typename T, class Allocator>
void Queue<T, Allocator>::push(T value){
    Node<T> *tmp = _alloc.allocate();
    tmp->data = value;
    if (_size == 0) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tmp;
    }
    _size++;
}

template<typename T, class Allocator>
void Queue<T, Allocator>::push_range(const std::initializer_list<T> &l){
    if(_size == 0){
        head = _alloc.allocate();
        head->data = *l.begin();
        tail = head;
    } else {
        tail->next = _alloc.allocate();
        tail->next->data = *l.begin();
        tail = tail->next;
    }
    for(auto elem = l.begin() + 1; elem != l.end(); elem++){
        tail->next = _alloc.allocate();
        tail->next->data = *elem;
        tail = tail->next;
    }
    tail->next = nullptr;
    _size += l.size();
}

template<typename T, class Allocator>
T Queue<T, Allocator>::pop(){
    if(_size == 0){
        throw std::range_error("Empty queue");
    }
    if(_size == 1){
        T ans = head->data;
        _alloc.deallocate(head);
        head = tail = nullptr;
        _size--;
        return ans;
    }
    Node<T> *first = head;
    head = head->next;
    T ans = first->data;
    _alloc.deallocate(first);
    _size--;
    return ans;

}

template <typename T, class Allocator>
T Queue<T, Allocator>::front() const{ 
    if (_size == 0){
        throw std::range_error("Empty queue");
    }
    return head->data;
}

template <typename T, class Allocator>
T Queue<T, Allocator>::back() const{ 
    if (_size == 0){
        throw std::range_error("Empty queue");
    }
    return tail->data;
}


template <typename T, class Allocator>
bool Queue<T, Allocator>::operator==(const Queue<T, Allocator> &other) const{
    if(_size != other._size){
        return false;
    }
    Node<T> * first = head;
    Node<T> * second = other.head;
    while(first != nullptr && second != nullptr){
        if(first->data != second->data){
            return false;
        }
        first = first->next;
        second = second->next;
    }
    if(first == nullptr && second == nullptr){
        return true;
    }
    return false;
}


template <typename T, class Allocator>
bool Queue<T, Allocator>::operator!=(const Queue<T, Allocator> &other) const{
    return !(*this == other);
}

template <typename T, class Allocator>
bool Queue<T, Allocator>::operator<(const Queue<T, Allocator> &other) const{
    if(_size != other._size){
        return _size < other._size;
    }
    Node<T> * first = head;
    Node<T> * second = other.head;
    while(first != nullptr && second != nullptr){
        if(first->data != second->data){
            return first->data < second->data;
        }
        first = first->next;
        second = second->next;
    }
    if(first == nullptr && second == nullptr){
        return false;
    }
    if(first == nullptr){
        return true;
    }
    return false;
}


template <typename T, class Allocator>
bool Queue<T, Allocator>::operator>(const Queue<T, Allocator> &other) const{
    return !(*this == other || *this < other);
}

template <typename T, class Allocator>
Queue<T, Allocator>::Iterator::Iterator(Iterator &other) : node(other.node) {}


template <typename T, class Allocator>
Queue<T, Allocator>::Iterator::Iterator(Node<T> *new_node) : node(new_node) {}

template <typename T, class Allocator>
typename Queue<T, Allocator>::Iterator &Queue<T, Allocator>::Iterator::operator++() {
    if (node == nullptr) {
        throw std::range_error("Out of range");
    }
    node = node->next;
    return *this;
}


template <typename T, class Allocator>
T& Queue<T, Allocator>::Iterator::operator *() const {
    return node->data;
}

template <typename T, class Allocator>
bool Queue<T, Allocator>::Iterator::operator == (const Iterator &other) const {
    return node == other.node;
}

template <typename T, class Allocator>
bool Queue<T, Allocator>::Iterator::operator != (const Iterator &other) const{
    return !(other == *this);
}

template <typename T, class Allocator>
typename Queue<T, Allocator>::Iterator &Queue<T, Allocator>::Iterator::operator=(const typename Queue<T, Allocator>::Iterator &other) {
    node = other.node;
    return *this;
}

template <typename T, class Allocator>
typename Queue<T, Allocator>::Iterator Queue<T, Allocator>::begin() {
    return Iterator(head);
}

template <typename T, class Allocator>
typename Queue<T, Allocator>::Iterator Queue<T, Allocator>::end() {
    return Iterator(nullptr);
}

template <typename T, class Allocator>
typename Queue<T, Allocator>::Iterator &Queue<T, Allocator>::Iterator::operator+(size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (node == nullptr) {
            throw std::range_error("Out of range");
        }
        node = node->next;
    }
    if (node == nullptr) {
        throw std::range_error("Out of range");
    }
    return *this;
}

template <typename T, class Allocator>
Queue<T, Allocator>::ConstIterator::ConstIterator(ConstIterator &other) : node(other.node) {}


template <typename T, class Allocator>
Queue<T, Allocator>::ConstIterator::ConstIterator(Node<T> *new_node) : node(new_node) {}


template <typename T, class Allocator>
typename Queue<T, Allocator>::ConstIterator &Queue<T, Allocator>::ConstIterator::operator++() {
    if (node == nullptr) {
        throw std::range_error("Out of range");
    }
    node = node->next;
    return *this;
}


template <typename T, class Allocator>
typename Queue<T, Allocator>::ConstIterator &Queue<T, Allocator>::ConstIterator::operator+(size_t n) {
    for (size_t i = 0; i < n; i++) {
        if (node == nullptr) {
            throw std::range_error("Out of range");
        }
        node = node->next;
    }
    if (node == nullptr) {
        throw std::range_error("Out of range");
    }
    return *this;
}

template <typename T, class Allocator>
const T& Queue<T, Allocator>::ConstIterator::operator *() const {
    return node->data;
}

template <typename T, class Allocator>
bool Queue<T, Allocator>::ConstIterator::operator == (const ConstIterator &other) const {
    return node == other.node;
}

template <typename T, class Allocator>
bool Queue<T, Allocator>::ConstIterator::operator != (const ConstIterator &other) const{
    return !(other == *this);
}

template <typename T, class Allocator>
typename Queue<T, Allocator>::ConstIterator &Queue<T, Allocator>::ConstIterator::operator=(const typename Queue<T, Allocator>::ConstIterator &other) {
    node = other.node;
    return *this;
}


template <typename T, class Allocator>
typename Queue<T, Allocator>::ConstIterator Queue<T, Allocator>::cbegin() {
    return ConstIterator(head);
}

template <typename T, class Allocator>
typename Queue<T, Allocator>::ConstIterator Queue<T, Allocator>::cend() {
    return ConstIterator(nullptr);
}