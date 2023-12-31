#pragma once
#include "figure.h"

template <typename T>
class Hexagon: public Figure<T> {
    friend std::ostream& operator << (std::ostream& os, const Hexagon<T> &fig) {
        os << "Hexagon\n" << fig.points;
        return os;
    }
    friend std::istream& operator >> (std::istream& is, const Hexagon<T> &fig) {
        Array<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < 6; ++i) {
            is >> tmp;
            tmpV.push_back(tmp);
        }
        if (!is_valid(tmpV)) {
            throw std::range_error("Error! Square Constructor: invalid points");
        } else {
            fig->points = tmpV;
        }   
        return is;
    }
    public:
        Hexagon();
        Hexagon(const std::initializer_list<Point<T>> &list);
        Hexagon(const Hexagon<Point<T>> &other);
        Hexagon(Hexagon<Point<T>> &&other) noexcept;
        Hexagon(Array<Point<T>> &arr);
        virtual ~Hexagon() noexcept = default;
        operator double() const;
        bool operator==(const Figure<T> &other) const;
        Hexagon<T> &operator = (Figure<T> &other);
    private:
        bool is_valid(const Array<Point<T>> &p);
};