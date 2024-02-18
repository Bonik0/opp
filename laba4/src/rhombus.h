
#include "figure_src.h"

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

template <typename T>
Rhombus<T>::Rhombus(): Figure<T>() {}

template <typename T>
Rhombus<T>::Rhombus(const Rhombus<Point<T>> &other): Figure<T>(other) {}

template <typename T>
Rhombus<T>::Rhombus(Rhombus<Point<T>> &&other) noexcept: Figure<T>(other) {}

template <typename T>
Rhombus<T>::Rhombus(const std::initializer_list<Point<T>> &list) {
    const Array<Point<T>> tmp(list);
    if (!is_valid(tmp)) {
        throw std::range_error("invalid of coordinates");
    } else {
        Array<Point<T>> tmp(list);
        this->points = list;
    }
}

template <typename T>
Rhombus<T>::Rhombus(Array<Point<T>> &arr) {
    if (!is_valid(arr)){
        throw std::range_error("invalid of coordinates");
    } else {
        this->points = arr;
    }
}

template <typename T>
bool Rhombus<T>::is_valid(const Array<Point<T>> &p) {
    if(p.size() != 4){
        return false;
    }
    double l = Point<T>::distance(p[0], p[1]);
    if(l < EPSILON){
        return false;
    }
    for (size_t i = 1; i < 3; i++) {
        if (fabs(Point<T>::distance(p[i], p[i + 1]) - l) > EPSILON){
            return false;
        }
    }
     if (fabs(Point<T>::distance(p[0], p[3]) - Point<T>::distance(p[0], p[1])) > EPSILON){
        return false;
    }
    return true;
}


template <typename T>
Rhombus<T>::operator double() const {
    return fabs(Point<T>::distance(this->get_points()[0], this->get_points()[1]) - Point<T>::distance(this->get_points()[0], this->get_points()[1])) < EPSILON;
}

template <typename T>
bool Rhombus<T>::operator ==(const Figure<T> &other) const{
     return this->points == other.get_points();
}

template <typename T>
Rhombus<T> &Rhombus<T>::operator = (Figure<T> &other) {
    if(typeid(*this) != typeid(other)){
        throw std::range_error("can't assign different types of figures");
    }
    else {
        this->points = other.get_points();
        return *this;
    }
}