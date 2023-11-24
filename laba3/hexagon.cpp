#include "include/hexagon.h"

Hexagon::Hexagon(const std::vector<Point> & vpoints) {
    if (vpoints.size() != 6) {
        throw std::range_error("invalid number of coordinates");
    } else if (!valid(vpoints)){
        throw std::range_error("invalid points");
    } else {
        points = vpoints;
    }
}


Hexagon::Hexagon(const Hexagon &other) : Figure(other) {}

Hexagon::Hexagon(const Hexagon &&other) : Figure(other) {}

Hexagon &Hexagon::operator=(const Hexagon &other) {
    points = other.points;
    return *this;
}

Hexagon &Hexagon::operator=(const Hexagon &&other) {
    points = std::move(other.points);
    return *this;
}

bool Hexagon::valid(const std::vector<Point> &p) const{
    for (size_t i = 0; i < 6 - 2; ++i) {
        if (fabs(Point::distance(p[i], p[i + 1]) - Point::distance(p[i + 1], p[i + 2])) > EPSILON){
            return false;
        }
    }
    double l = Point::distance(p[0], p[1]);
    if (l < EPSILON) {
        return false;
    }
    for (size_t i = 0; i < 6 - 3; ++i) {
        if (fabs(Point::distance(p[i], p[i + 3]) - 2 * l) > EPSILON){ 
            return false;
        }
    }
    return true;
}

Hexagon::operator double() const {
    if (points.size() == 0) {
        throw std::range_error("empty");
    }
    return std::pow(Point::distance(points[0], points[1]), 2) * 3 * std::pow(3, 0.5) / 2;
}

bool Hexagon::is_equal(const Figure &other) const {
    if (points.size() == 0 || other.get_points().size() == 0) {
        throw std::range_error("empty");
    }
    return fabs(Point::distance(other.get_points()[0], other.get_points()[1]) - Point::distance(points[0], points[1])) < EPSILON;
}


void Hexagon::print(std::ostream& os) const{
    if (points.size() == 0) {
        throw std::logic_error("empty");
    }
    for (size_t i = 0; i < 6; i++) {
        os << points[i];
    }
}

void Hexagon::input(std::istream &is) {
    std::vector<Point> tmpV;
    Point tmp;
    for (size_t i = 0; i < 6; i++) {
        is >> tmp;
        tmpV.push_back(tmp);
    }
    if (!valid(tmpV)) {
        throw std::range_error("invalid points");
    } else {
        points = tmpV;
    }
}

