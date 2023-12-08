#pragma once

#include "figure.h"
#include <cmath>

class Pentagon final: public Figure {
    public:
        Pentagon();
        Pentagon(const std::initializer_list<Point> &list);
        Pentagon(const std::vector<Point> &vector);
        Pentagon(const Point_vector &other);
        Pentagon(const Figure &other);
        ~Pentagon();
        Pentagon &operator = (const Figure &other); 
        operator double() const override;
    private:
        bool is_equal(const Figure &other) const override;
        bool is_valid(const Point_vector &p) const override;
        void print(std::ostream &os) const override;
        void input(std::istream &os) override;
};