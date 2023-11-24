#include "include/point.h"


Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(double newX, double newY){
    x = newX;
    y = newY;
}

Point::Point(const Point &other){
    x = other.x;
    y = other.y;
}

Point::~Point() {}

Point &Point::operator = (const Point &other) {
    y = other.y;
    x = other.x;
    return *this;
}

Point &Point::operator = (Point &&other) {
    y = other.y;
    x = other.x;
    return *this;
}

bool Point::operator == (const Point &other) const {
    return distance(*this, other) < EPSILON ? true : false;
}

bool Point::operator != (const Point &other) const {
    return !(*this == other);
}


double Point::get_x() const {
    return x;
}

double Point::get_y() const {
    return y;
}

double Point::distance(const Point &left, const Point &right){
    return sqrt((pow(left.x - right.x, 2) + pow(left.y - right.y, 2)));
}

std::istream& operator >> (std::istream& is, Point& point) {
    is >> point.x; is >> point.y;
    return is;
}

std::ostream& operator << (std::ostream &os, const Point& point) {
    return os << "x = " << point.x << ", y = " << point.y << std::endl;
}

