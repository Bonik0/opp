#include "pentagon.h"

Pentagon::Pentagon(){
    throw std::range_error("invalid points");
}


Pentagon::Pentagon(const std::initializer_list<Point> &list){
    points = Point_vector(list);
    if(!is_valid(points)){
        throw std::range_error("invalid points");
        points.~Point_vector();
    } 
}

Pentagon::Pentagon(const std::vector<Point> &vector) {
    points = Point_vector(vector);
    if(!is_valid(points)){
        throw std::range_error("invalid points");
        points.~Point_vector();
    } 
}

Pentagon::Pentagon(const Point_vector &other){
    if(!is_valid(other)){
        throw std::range_error("invalid points");
    } else {
        points = other;
    }
}

Pentagon::Pentagon(const Figure &other){
    if(!is_valid(other.get_points())){
        throw std::range_error("invalid points");
    } else {
        points = other.get_points();
    }
}

Pentagon &Pentagon::operator = (const Figure &other){
    if(!is_valid(other.get_points())){
        throw std::range_error("invalid points");
    } else {
        points = other.get_points();
    }
    return *this;
}

Pentagon::~Pentagon(){
    points.~Point_vector();
}

bool Pentagon::is_valid(const Point_vector &p) const{
    if(p.size() != 5){
        return false;
    }
    double l = Point::distance(p[0], p[1]);
    if(l < EPSILON){
        return false;
    }
    for (size_t i = 1; i < 4; i++) {
        if (fabs(Point::distance(p[i], p[i + 1]) - l) > EPSILON){
            return false;
        }
    }
    if (fabs(Point::distance(p[0], p[4]) - l) > EPSILON){
        return false;
    }
    for(size_t i = 0; i < 3; i++){
        if (fabs(Point::distance(p[i], p[i + 2]) / l) - (1.0 + sqrt(5.0)) / 2.0 > EPSILON){
            return false;
        }
    }
    return true;
}

Pentagon::operator double() const {
    return std::pow(Point::distance(points[0], points[1]), 2) * ((sqrt(5.0) * sqrt(5.0 + 2.0 * sqrt(5.0)))/ 4.0);
}

bool Pentagon::is_equal(const Figure &other) const {
    return fabs(Point::distance(other.get_points()[0], other.get_points()[1]) - Point::distance(points[0], points[1])) < EPSILON;
}


void Pentagon::print(std::ostream& os) const{
    for (size_t i = 0; i < 5; i++) {
        os << points[i];
    }
}

void Pentagon::input(std::istream &is) {
    Point_vector tmpV;
    Point tmp;
    for (size_t i = 0; i < 5; i++) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!is_valid(tmpV)) {
        throw std::range_error("invalid points");
    } else {
        points = tmpV;
    }
}