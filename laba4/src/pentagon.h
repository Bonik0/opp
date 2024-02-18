
#include "figure_src.h"

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

template <typename T>
Pentagon<T>::Pentagon(): Figure<T>() {}

template <typename T>
Pentagon<T>::Pentagon(const Pentagon<Point<T>> &other): Figure<T>(other) {
}

template <typename T>
Pentagon<T>::Pentagon(Pentagon<Point<T>> &&other) noexcept: Figure<T>(other) {}

template <typename T>
Pentagon<T>::Pentagon(const std::initializer_list<Point<T>> &list) {
    const Array<Point<T>> tmp(list);
    if (!is_valid(tmp)) {
        throw std::range_error("invalid of coordinates");
    } else {
        Array<Point<T>> tmp(list);
        this->points = list;
    }
}

template <typename T>
Pentagon<T>::Pentagon(Array<Point<T>> &arr) {
    if (!is_valid(arr)){
        throw std::range_error("invalid of coordinates");
    } else {
        this->points = arr;
    }
}

template <typename T>
bool Pentagon<T>::is_valid(const Array<Point<T>> &p) {
    if(p.size() != 5){
        return false;
    }
    double l = Point<T>::distance(p[0], p[1]);
    if(l < EPSILON){
        return false;
    }
    for (size_t i = 1; i < 4; i++) {
        if (fabs(Point<T>::distance(p[i], p[i + 1]) - l) > EPSILON){
            return false;
        }
    }
    if (fabs(Point<T>::distance(p[0], p[4]) - l) > EPSILON){
        return false;
    }
    for(size_t i = 0; i < 3; i++){
        if (fabs(Point<T>::distance(p[i], p[i + 2]) / l) - (1.0 + sqrt(5.0)) / 2.0 > EPSILON){
            return false;
        }
    }
    return true;
}


template <typename T>
Pentagon<T>::operator double() const {
    return std::pow(Point<T>::distance(this->get_points()[0], this->get_points()[1]), 2) * ((sqrt(5.0) * sqrt(5.0 + 2.0 * sqrt(5.0)))/ 4.0);
}

template <typename T>
bool Pentagon<T>::operator ==(const Figure<T> &other) const{
     return this->points == other.get_points();
}

template <typename T>
Pentagon<T> &Pentagon<T>::operator = (Figure<T> &other) {
    if(typeid(*this) != typeid(other)){
        throw std::range_error("can't assign different types of figures");
    }
    else {
        this->points = other.get_points();
        return *this;
    }
}