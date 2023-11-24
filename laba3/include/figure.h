#include <iostream>
#include <vector>
#include <ostream>
#include <cmath>
#include "point.h"


class Figure {
    public:
        Figure();
        Figure(const Figure &other);
        Figure(const Figure &&other) noexcept;
        ~Figure() = default;
        std::vector<Point> get_points() const;
        virtual operator double () const = 0;
        friend bool operator == (const Figure &left, const Figure &right);
        Point get_center() const;
        friend std::ostream &operator << (std::ostream& os, const Figure& f);
        friend std::istream &operator >> (std::istream& is, Figure& f);
    protected:
        virtual bool is_equal(const Figure &other) const = 0;
        virtual bool valid(const std::vector<Point> &p) const = 0;
        virtual void print(std::ostream &os) const = 0;
        virtual void input(std::istream &os) = 0;
        std::vector<Point> points;
};
