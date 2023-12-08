#pragma once

#include "figure.h"
#include <cmath>

class Hexagon final: public Figure {
    public:
        Hexagon();
        Hexagon(const std::initializer_list<Point> &list);
        Hexagon(const std::vector<Point> &vector);
        Hexagon(const Point_vector &other);
        Hexagon(const Figure &other);
        ~Hexagon();
        Hexagon &operator = (const Hexagon &other); 
        operator double() const override;
    private:
        bool is_equal(const Figure &other) const override;
        bool is_valid(const Point_vector &p) const override;
        void print(std::ostream &os) const override;
        void input(std::istream &os) override;
};