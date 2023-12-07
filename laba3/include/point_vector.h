#pragma once

#include "point.h"
#include <vector>
#include <cstring>

class Point_vector {
private:
    Point *array;
    size_t _size;
    size_t capacity;
    void relloc(size_t new_capacity);
public:
    Point_vector();
    Point_vector(const std::initializer_list<Point> &list);
    Point_vector(const std::vector<Point> &vector);
    Point_vector(const Point_vector &other);
    Point_vector(size_t n);
    Point_vector(size_t n,const Point point);
    Point_vector &operator = (const Point_vector &other);
    bool operator == (const Point_vector &other) const;
    bool operator != (const Point_vector &other) const;
    ~Point_vector();
    void push_back(const Point point);
    void pop_back();
    void erase(size_t index);
    Point* get_arrey() const;
    size_t size() const;
    Point operator[](size_t index) const;
    friend std::ostream &operator << (std::ostream& os, const Point_vector& vector);
};