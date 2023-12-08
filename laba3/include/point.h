#pragma once

#include <iostream>
#include <vector>
#include <cmath>

#define EPSILON 0.01

class Point {
    public:
        Point();
        Point(const double new_x, const double new_y);
        Point(const Point &other);
        ~Point() = default;
        Point &operator = (const Point &other);
        bool operator == (const Point &other) const;
        bool operator != (const Point &other) const;
        double get_x() const;
        double get_y() const;
        static double distance(const Point& left, const Point& right);
        friend std::ostream& operator << (std::ostream &os, const Point& point);
        friend std::istream& operator >> (std::istream& is, Point& point);
    private:
        double x;
        double y;
};
