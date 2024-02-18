#pragma once
#include <iostream>
#include <cmath>
#define EPSILON 0.01

template <typename T>
class Point {
    friend std::ostream& operator << (std::ostream& os, const Point<T> &point) {
        return os << "x = " << point.x << ", y = " << point.y;
    }
    friend std::istream& operator >> (std::istream& is, const Point<T> &point) {
        is >> point.x; 
        is >> point.y;
        return is;
    }

    public :
        Point();
        Point(T new_x, T new_y);
        Point(const Point &other);
        virtual ~Point() noexcept;
        bool operator == (const Point<T> &other) const;
        bool operator != (const Point<T> &other) const;
        Point<T> &operator=(const Point<T> &other);
        T get_x() const;
        T get_y() const;
        static double distance(const Point &left ,const Point &right){
            return sqrt(pow(left.get_x() - right.get_x(), 2) + pow(left.get_y() - right.get_y(),2));
        }
    private:
        T x;
        T y;
};

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

