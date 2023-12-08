#include "rhombus.h"

Rhombus::Rhombus(){
    throw std::range_error("invalid points");
}


Rhombus::Rhombus(const std::initializer_list<Point> &list){
    points = Point_vector(list);
    if(!is_valid(points)){
        throw std::range_error("invalid points");
        points.~Point_vector();
    } 
}

Rhombus::Rhombus(const std::vector<Point> &vector) {
    points = Point_vector(vector);
    if(!is_valid(points)){
        throw std::range_error("invalid points");
        points.~Point_vector();
    } 
}

Rhombus::Rhombus(const Point_vector &other){
    if(!is_valid(other)){
        throw std::range_error("invalid points");
    } else {
        points = other;
    }
}

Rhombus::Rhombus(const Figure &other){
    if(!is_valid(other.get_points())){
        throw std::range_error("invalid points");
    } else {
        points = other.get_points();
    }
}

Rhombus &Rhombus::operator = (const Figure &other){
    if(!is_valid(other.get_points())){
        throw std::range_error("invalid points");
    } else {
        points = other.get_points();
    }
    return *this;
}

Rhombus::~Rhombus(){
    points.~Point_vector();
}

bool Rhombus::is_valid(const Point_vector &p) const{
    if(p.size() != 4){
        return false;
    }
    double l = Point::distance(p[0], p[1]);
    if(l < EPSILON){
        return false;
    }
    for (size_t i = 1; i < 3; i++) {
        if (fabs(Point::distance(p[i], p[i + 1]) - l) > EPSILON){
            return false;
        }
    }
     if (fabs(Point::distance(p[0], p[3]) - Point::distance(p[0], p[1])) > EPSILON){
        return false;
    }
    return true;
}

Rhombus::operator double() const {
    return (Point::distance(points[0], points[2]) * Point::distance(points[1], points[3])) / 2;
}

bool Rhombus::is_equal(const Figure &other) const {
    return fabs(Point::distance(other.get_points()[0], other.get_points()[1]) - Point::distance(points[0], points[1])) < EPSILON;
}


void Rhombus::print(std::ostream& os) const{
    for (size_t i = 0; i < 4; i++) {
        os << points[i];
    }
}

void Rhombus::input(std::istream &is) {
    Point_vector tmpV;
    Point tmp;
    for (size_t i = 0; i < 4; i++) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!is_valid(tmpV)) {
        throw std::range_error("invalid points");
    } else {
        points = tmpV;
    }
}