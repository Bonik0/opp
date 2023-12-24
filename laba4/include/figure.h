#pragma once
#include "point.h"
#include "array.h"
template <typename T>
class Figure {
    friend std::ostream& operator << (std::ostream& os, const Figure<T> &fig) {
        switch (fig._points.size()) {
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