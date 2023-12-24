#pragma once
#include <iostream>
#include <cmath>
#define EPSILON 0.01

template <typename T>
class Point {
    friend std::ostream& operator << (std::ostream& os, const Point<T> &point) {
        return os << "x = " << point.x << ", y = " << point.y << "\n";
    }
    friend std::istream& operator >> (std::istream& is, const Point<T> &point) {
        is >> point.x; is >> point.y;
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