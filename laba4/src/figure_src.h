#pragma once

#include "point_src.h"
#include "array_src.h"

template <typename T>
class Figure {
    friend std::ostream& operator << (std::ostream& os, const Figure<T> &fig) {
        switch (fig.points.size()) {
            case 4:
                os << "Rhombus\n" << fig.points;
                break;
            case 5:
                os << "Pentagon\n" << fig.points;
                break;
            case 6:
                os << "Hexagon\n" << fig.points;
                break;
            default:
                os << "Unknown figure\n" << fig.points;
                break;
        }
        return os;
    }
    public:
        Figure();
        Figure(const Figure<Point<T>> &other);
        Figure(Figure<Point<T>> &&other) noexcept;
        Figure(const std::initializer_list<Point<T>> &list);
        ~Figure() = default;
        Array<Point<T>> get_points() const;
        Point<T> get_center() const;
        virtual operator double() const = 0;
    protected:
        Array<Point<T>> points;
};

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
    return Point<T>(sum_x / points.size(), sum_y / points.size());
}

template <typename T>
Figure<T>::Figure(const std::initializer_list<Point<T>> &list) : points(list) {}