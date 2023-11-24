#include "include/figure.h"

Figure::Figure() {}

Figure::Figure(const Figure &other){
    points = other.points;
}

Figure::Figure(const Figure &&other) noexcept{
    points = std::move(other.points);
}

bool operator == (const Figure& left, const Figure& right) {
    if (typeid(left) != typeid(right)) {
        return false;
    }
    return left.is_equal(right);
}

std::ostream& operator << (std::ostream& os, const Figure& f) {
    f.print(os);
    return os;
}

std::istream& operator >> (std::istream& is, Figure& f) {
    f.input(is);
    return is;
}

std::vector<Point> Figure::get_points() const{
    return points;
}

Point Figure::get_center() const{
    double sum_x = 0, sum_y = 0;
    for (size_t i = 0; i < points.size(); i++) {
        sum_x += points[i].get_x();
        sum_y += points[i].get_y();
    }
    return Point(sum_x / points.size(), sum_y / points.size());
}
