#pragma once
#include "figure.h"

template <typename T>
class Rhombus: public Figure<T> {
    friend std::ostream& operator << (std::ostream& os, const Rhombus<T> &fig) {
        os << "Rhombus\n" << fig.points;
        return os;
    }
    friend std::istream& operator >> (std::istream& is, const Rhombus<T> &fig) {
        Array<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < 4; ++i) {
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
        Rhombus();
        Rhombus(const std::initializer_list<Point<T>> &list);
        Rhombus(const Rhombus<Point<T>> &other);
        Rhombus(Rhombus<Point<T>> &&other) noexcept;
        Rhombus(Array<Point<T>> &arr);
        virtual ~Rhombus() noexcept = default;
        operator double() const;
        bool operator==(const Figure<T> &other) const;
        Rhombus<T> &operator = (Figure<T> &other);
    private:
        bool is_valid(const Array<Point<T>> &p);
};