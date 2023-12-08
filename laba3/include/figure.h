#pragma once


#include <ostream>
#include "point.h"
#include "point_vector.h"

class Figure {
    public:
        Figure();
        Figure(const std::initializer_list<Point> &list);
        Figure(const std::vector<Point> &vector);
        Figure(const Point_vector &other);
        Figure(const Figure &other);
        ~Figure();
        Point_vector get_points() const;
        Point get_center() const;
        virtual operator double () const = 0;
        friend bool operator==(const Figure &left, const Figure &right);
        friend bool operator!=(const Figure &left, const Figure &right);
        friend std::ostream &operator << (std::ostream& os, const Figure& f);
        friend std::istream &operator >> (std::istream& is, Figure& f);
    protected:
        virtual bool is_equal(const Figure &other) const = 0;
        virtual bool is_valid(const Point_vector &p) const = 0;
        virtual void print(std::ostream &os) const = 0;
        virtual void input(std::istream &os) = 0;
        Point_vector points;
};
