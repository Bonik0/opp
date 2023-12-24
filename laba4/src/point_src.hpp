#pragma once
#include "point.h"

template <typename T>
Point<T>::Point() : x(), y() {}

template <typename T>
Point<T>::Point(T new_x, T new_y) : x(new_x), y(new_y) {}

template <typename T>
Point<T>::Point(const Point<T> &other) : x(other.x), y(other.y) {}

template <typename T>
Point<T>::~Point() noexcept{}

template <typename T>
bool Point<T>::operator == (const Point<T> &other) const {
    return Point::distance(*this, other) < EPSILON ? true : false;
}

template <typename T>
bool Point<T>::operator != (const Point<T> &other) const {
    return !(*this == other);
}

template <typename T>
T Point<T>::get_x() const {
    return x;
}

template <typename T>
T Point<T>::get_y() const {
    return y;
}

template <typename T>
Point<T> &Point<T>::operator=(const Point<T> &other) {
    y = other.y;
    x = other.x;
    return *this;
}

