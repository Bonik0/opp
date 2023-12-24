#pragma once
#include "figure.h"

template <typename T>
Figure<T>::Figure() {
    Array<Point<T>> points;
}

template <typename T>
Figure<T>::Figure(const Figure<Point<T>> &other) : points(other.points) {}

template <typename T>
Figure<T>::Figure(Figure<Point<T>> &&other) noexcept {
    std::swap(this->points, other.points);
}

template <typename T>
Array<Point<T>> Figure<T>::get_points() const {
    return points;
}

template <typename T>
Point<T> Figure<T>::get_center() const {
    T sum_x = 0, sum_y = 0;
    for (size_t i = 0; i < points.size(); i++){
        sum_x += points[i].get_x();
        sum_y += points[i].get_y();
    }
    return Point(sum_x / points.size(), sum_y / points.size());
}

template <typename T>
Figure<T>::Figure(const std::initializer_list<Point<T>> &list) : points(list) {}