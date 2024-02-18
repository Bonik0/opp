
#include "figure_src.h"


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

template <typename T>
Hexagon<T>::Hexagon(): Figure<T>() {}

template <typename T>
Hexagon<T>::Hexagon(const Hexagon<Point<T>> &other): Figure<T>(other) {
}

template <typename T>
Hexagon<T>::Hexagon(Hexagon<Point<T>> &&other) noexcept: Figure<T>(other) {}

template <typename T>
Hexagon<T>::Hexagon(const std::initializer_list<Point<T>> &list) {
    const Array<Point<T>> tmp(list);
    if (!is_valid(tmp)) {
        throw std::range_error("invalid of coordinates");
    } else {
        Array<Point<T>> tmp(list);
        this->points = list;
    }
}

template <typename T>
Hexagon<T>::Hexagon(Array<Point<T>> &arr) {
    if (!is_valid(arr)){
        throw std::range_error("invalid of coordinates");
    } else {
        this->points = arr;
    }
}

template <typename T>
bool Hexagon<T>::is_valid(const Array<Point<T>> &p) {
    if(p.size() != 6){
        return false;
    }
    for (size_t i = 0; i < 6 - 2; i++) {
        if (fabs(Point<T>::distance(p[i], p[i + 1]) - Point<T>::distance(p[i + 1], p[i + 2])) > EPSILON){
            return false;
        }
    }
    if (fabs(Point<T>::distance(p[0], p[5]) - Point<T>::distance(p[0], p[1])) > EPSILON){
        return false;
    }
    double l = Point<T>::distance(p[0], p[1]);
    if (l < EPSILON) {
        return false;
    }
    for (size_t i = 0; i < 6 - 3; i++) {
        if (fabs(Point<T>::distance(p[i], p[i + 3]) - 2 * l) > EPSILON){ 
            return false;
        }
    }
    return true;
}


template <typename T>
Hexagon<T>::operator double() const {
    return std::pow(Point<T>::distance(this->get_points()[0], this->get_points()[1]), 2) * 3 * std::pow(3, 0.5) / 2;
}

template <typename T>
bool Hexagon<T>::operator ==(const Figure<T> &other) const{
    return this->points == other.get_points();
}

template <typename T>
Hexagon<T> &Hexagon<T>::operator = (Figure<T> &other) {
    if(typeid(*this) != typeid(other)){
        throw std::range_error("can't assign different types of figures");
    }
    else {
        this->points = other.get_points();
        return *this;
    }
}