#include "hexagon.h"

Hexagon::Hexagon(){
    throw std::range_error("invalid points");
}


Hexagon::Hexagon(const std::initializer_list<Point> &list){
    points = Point_vector(list);
    if(!is_valid(points)){
        throw std::range_error("invalid points");
        points.~Point_vector();
    } 
}

Hexagon::Hexagon(const std::vector<Point> &vector) {
    points = Point_vector(vector);
    if(!is_valid(points)){
        throw std::range_error("invalid points");
        points.~Point_vector();
    } 
}

Hexagon::Hexagon(const Point_vector &other){
    if(!is_valid(other)){
        throw std::range_error("invalid points");
    } else {
        points = other;
    }
}

Hexagon::Hexagon(const Figure &other){
    if(!is_valid(other.get_points())){
        throw std::range_error("invalid points");
    } else {
        points = other.get_points();
    }
}

Hexagon &Hexagon::operator = (const Figure &other){
    if(!is_valid(other.get_points())){
        throw std::range_error("invalid points");
    } else {
        points = other.get_points();
    }
    return *this;
}

Hexagon::~Hexagon(){
    points.~Point_vector();
}

bool Hexagon::is_valid(const Point_vector &p) const{
    if(p.size() != 6){
        return false;
    }
    for (size_t i = 0; i < 6 - 2; i++) {
        if (fabs(Point::distance(p[i], p[i + 1]) - Point::distance(p[i + 1], p[i + 2])) > EPSILON){
            return false;
        }
    }
    if (fabs(Point::distance(p[0], p[5]) - Point::distance(p[0], p[1])) > EPSILON){
        return false;
    }
    double l = Point::distance(p[0], p[1]);
    if (l < EPSILON) {
        return false;
    }
    for (size_t i = 0; i < 6 - 3; i++) {
        if (fabs(Point::distance(p[i], p[i + 3]) - 2 * l) > EPSILON){ 
            return false;
        }
    }
    return true;
}

Hexagon::operator double() const {
    return std::pow(Point::distance(points[0], points[1]), 2) * 3 * std::pow(3, 0.5) / 2;
}

bool Hexagon::is_equal(const Figure &other) const {
    return fabs(Point::distance(other.get_points()[0], other.get_points()[1]) - Point::distance(points[0], points[1])) < EPSILON;
}


void Hexagon::print(std::ostream& os) const{
    for (size_t i = 0; i < 6; i++) {
        os << points[i];
    }
}

void Hexagon::input(std::istream &is) {
    Point_vector tmpV;
    Point tmp;
    for (size_t i = 0; i < 6; i++) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!is_valid(tmpV)) {
        throw std::range_error("invalid points");
    } else {
        points = tmpV;
    }
}

