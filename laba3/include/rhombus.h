#pragma once

#include "figure.h"
#include <cmath>

class Rhombus final: public Figure {
    public:
        Rhombus();
        Rhombus(const std::initializer_list<Point> &list);
        Rhombus(const std::vector<Point> &vector);
        Rhombus(const Point_vector &other);
        Rhombus(const Figure &other);
        ~Rhombus();
        Rhombus &operator = (const Figure &other); 
        operator double() const override;
    private:
        bool is_equal(const Figure &other) const override;
        bool is_valid(const Point_vector &p) const override;
        void print(std::ostream &os) const override;
        void input(std::istream &os) override;
};