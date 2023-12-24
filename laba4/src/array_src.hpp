#pragma once
#include "array.h"

template <class T>
Array<T>::Array() : _size{0}, capacity{0}, array{nullptr} {}

template <class T>
Array<T>::Array(const std::initializer_list<T> &list) {
    _size = list.size();
    capacity = _size * 2;
    array = std::make_unique<T[]>(capacity);
    size_t i = 0;
    for (T el: list) {
        array[i++] = el;
    }
}

template <class T>
Array<T>::Array(Array<T> &&other) noexcept {
    _size = other._size;
    capacity = other.capacity;
    array = std::move(other.array);
}

template <class T>
Array<T>::Array(const Array<T> &other) {
    _size = other._size;
    capacity = other.capacity;
    array = std::make_unique<T[]>(capacity);
    for (int i = 0; i < other.size(); i++) {
        array[i] = other[i];
    }
}

template <class T>
T &Array<T>::operator[] (const size_t &index) const {
    if (index >= _size) {
        throw std::range_error("index is bigger, than size");
    }
    return array[index];
}

template <class T>
size_t Array<T>::size() const {
    return _size;
}

template <class T>
void Array<T>::push_back(const T &elem) {
    if (_size >= capacity) {
        this->relloc(capacity * 2);
    } 
    array[_size] = elem;
    _size++;
}

template <class T>
void Array<T>::erase(const size_t &index) {
    if (index >= _size) {
        throw std::range_error("index is bigger, than size");
    }
    for (size_t i = index; i < _size - 1; i++) {
        array[i] = array[i+1];
    }
    _size--;
    if(_size * 2 == capacity){
        this->relloc(capacity / 2);
    }
}

template <class T>
void Array<T>::pop_back() {
    if (_size == 0) {
        throw std::range_error("can't pop from empty array");
    }
    _size--;
    if(_size * 2 == capacity){
        this->relloc(capacity / 2);
    }
}

template <class T>
Array<T> &Array<T>::operator=( Array<T> &other) {
    _size = other._size;
    capacity = other.capacity;
    array = std::make_unique<T[]>(capacity);
    std::memcpy(array.get(), other.array.get(), other.size() * sizeof(T));
    return *this;
}

template <class T>
Array<T> &Array<T>::operator=(Array<T> &&other) noexcept{
    std::swap(_size, other._size);
    std::swap(array, other.array);
    std::swap(capacity, other.capacity);
    return *this;
}

template <class T>
void Array<T>::relloc(size_t new_capacity){
    capacity = new_capacity;
    std::unique_ptr<T[]> newArray = std::make_unique<T[]>(new_capacity);
    for (int i = 0; i < _size; i++) {
        newArray[i] = array[i];
    }
    array = std::move(newArray);


}

template <class T>
bool Array<T>::operator == (const Array<T> &other) const{
    if(_size != other._size){
        return false;
    }
    for(size_t i = 0; i < _size; i++){
        if (array[i] != other.array[i]){
            return false;
        }
    }
    return true;
}



template <class T>
bool Array<T>::operator != (const  Array<T> &other) const{
    return !(*this == other);
}