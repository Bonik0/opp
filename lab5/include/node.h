#pragma once

#include <iostream>

template <typename T>
class Node {
    public:
        T data;
        Node *next;
        Node();
        Node(T value);
        Node(const Node &other);
        ~Node() = default;
};

template <typename T>
Node<T>::Node() : next(nullptr), data(0) {}

template <typename T>
Node<T>::Node(T value) : next(nullptr), data(value) {}

template <typename T>
Node<T>::Node(const Node<T> &other) {
    data = other.data;
    next = other.next;
}