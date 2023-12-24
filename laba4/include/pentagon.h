#pragma once
#include "figure.h"

template <typename T>
class Pentagon: public Figure<T> {
    friend std::ostream& operator << (std::ostream& os, const Pentagon<T> &fig) {
        os << "Pentagon\n" << fig.points;
        return os;
    }
    friend std::istream& operator >> (std::istream& is, const Pentagon<T> &fig) {
        Array<Point<T>> tmpV;
        Point<T> tmp;
        for (size_t i = 0; i < 5; ++i) {
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
        Pentagon();
        Pentagon(const std::initializer_list<Point<T>> &list);
        Pentagon(const Pentagon<Point<T>> &other);
        Pentagon(Pentagon<Point<T>> &&other) noexcept;
        Pentagon(Array<Point<T>> &arr);
        virtual ~Pentagon() noexcept = default;
        operator double() const;
        bool operator==(const Figure<T> &other) const;
        Pentagon<T> &operator = (Figure<T> &other);
    private:
        bool is_valid(const Array<Point<T>> &p);
};