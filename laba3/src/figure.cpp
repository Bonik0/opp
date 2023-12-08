#include "figure.h"

Figure::Figure() {}


Figure::Figure(const std::initializer_list<Point> &list){
    points = Point_vector(list);
}

Figure::Figure(const std::vector<Point> &vector){
    points = Point_vector(vector);
}

Figure::Figure(const Point_vector &other){
    points = other;
}

Figure::Figure(const Figure &other){
    points = other.points;
}


Figure::~Figure(){
    points.~Point_vector();
}

std::ostream& operator << (std::ostream& os, const Figure& f){
    f.print(os);
    return os;
}

std::istream& operator >> (std::istream& is, Figure& f){
    f.input(is);
    return is;
}

Point_vector Figure::get_points() const{
    return points;
}

Point Figure::get_center() const{
    double sum_x = 0, sum_y = 0;
    for (size_t i = 0; i < points.size(); i++){
        sum_x += points[i].get_x();
        sum_y += points[i].get_y();
    }
    return Point(sum_x / points.size(), sum_y / points.size());
}

bool operator == (const Figure& left, const Figure& right) {
    if (typeid(left) != typeid(right)) {
        return false;
    }
    return left.is_equal(right);
}
bool operator != (const Figure& left, const Figure& right) {
    return !(left == right);
}