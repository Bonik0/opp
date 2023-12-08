#include "googletest/googletest/include/gtest/gtest.h"
#include "include/point.h"
#include "include/point_vector.h"
#include "include/figure.h"
#include "include/hexagon.h"
#include "include/rhombus.h"
#include "include/pentagon.h"
#include "include/array.h"

TEST(test_point, test_init1) {
  Point p;
  ASSERT_TRUE(p.get_x() == 0 && p.get_y() == 0);
}

TEST(test_point, test_init2) {
  Point p(1.0, 1.0);
  ASSERT_TRUE(p.get_x() == 1.0 && p.get_y() == 1.0);
}

TEST(test_point, test_init3) {
  Point p(1.0, 1.0);
  Point p1;
  p1 = p;
  ASSERT_TRUE(p1.get_x() == 1.0 && p1.get_y() == 1.0);
}

TEST(test_point, test_init4) {
  Point p(1.0, 1.0);
  Point p1(p);
  ASSERT_TRUE(p1.get_x() == 1.0 && p1.get_y() == 1.0);
}

TEST(test_point, test_init5) {
  Point p;
  Point p1(p);
  ASSERT_TRUE(p1.get_x() == p.get_x() && p1.get_y() == p.get_y());
}

TEST(test_point, test_init6) {
  Point p(2.0, 1.0);
  Point p1(9, 9);
  p1 = p;
  ASSERT_TRUE(p1.get_x() == p.get_x() && p1.get_y() == p.get_y());
}

TEST(test_point, test_init7) {
  Point p(2.0, 1.0);
  Point p1(p);
  ASSERT_TRUE(p1.get_x() == p.get_x() && p1.get_y() == p.get_y());
}


TEST(test_point, test_eq1) {
  Point p(1.0, 1.0);
  Point p1(2.0, 2.0);
  ASSERT_TRUE(p1 != p);
}

TEST(test_point, test_eq2) {
  Point p(1.0, 1.0);
  Point p1(1.0, 1.0);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point, test_eq3) {
  Point p(1.0, 1.0);
  Point p1(1.5, 1.5);
  ASSERT_TRUE(p1 != p);
}

TEST(test_point, test_eq4) {
  Point p(1.0, 1.0);
  Point p1(1.0001, 1.0001);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point, test_eq5) {
  Point p(1.0, 1.0);
  Point p1(p);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point, test_eq6) {
  Point p(2.0, 1.0);
  Point p1 = p;
  ASSERT_TRUE(p1 == p);
}

TEST(test_point, test_eq7) {
  Point p(2.0, 1.0);
  Point p1;
  ASSERT_TRUE(p1 != p);
}

TEST(test_point, test_eq8) {
  ASSERT_TRUE(Point(2.2, 0) != Point(2.1, 0));
}

TEST(test_point, get1) {
  Point p(2.0, 1.0);
  ASSERT_TRUE(p.get_x() == 2.0 && p.get_y() == 1.0);
}

TEST(test_point, distance1) {
  Point p(1.0, 1.0);
  Point p1(1.000, 1.000);
  ASSERT_TRUE(Point::distance(p, p1) == 0);
}

TEST(test_point, distance2) {
  Point p(1.0, 1.0);
  Point p1(2.0, 1.0);
  ASSERT_TRUE(Point::distance(p, p1) == 1);
}

TEST(test_point, distance3) {
  Point p(1.0, 1.0);
  Point p1(p);
  ASSERT_TRUE(Point::distance(p, p1) == 0);
}
TEST(test_point, distance4) {
  Point p(1.0, 1.0);
  Point p1 = p;
  ASSERT_TRUE(Point::distance(p, p1) == 0);
}

TEST(test_point, distance5) {
  Point p(1.0, 1.0);
  Point p1(2.0, 2.0);
  ASSERT_TRUE(Point::distance(p, p1) == sqrt(2));
}

TEST(test_point, distance6) {
  Point p(1.0, 1.0);
  Point p1(2.0, 2.0);
  ASSERT_TRUE(Point::distance(p1, p) == sqrt(2));
}

TEST(test_point, distance7) {
  Point p;
  Point p1(2.0, 6.0);
  ASSERT_TRUE(Point::distance(p1, p) == sqrt(40));
}

TEST(test_point, distance8) {
  Point p;
  Point p1(2.0, 6.0);
  ASSERT_TRUE(Point::distance(p, p1) == sqrt(40));
}

TEST(test_point, distance9) {
  Point p;
  Point p1(3.0, 4.0);
  ASSERT_TRUE(Point::distance(p, p1) == 5);
}

TEST(test_point, distance10) {
  Point p(1.0, 1.0);
  Point p1(5.0, 4.0);
  ASSERT_TRUE(Point::distance(p, p1) == 5);
}

TEST(test_point, distance11) {
  Point p(1.0, 1.0);
  Point p1(5.0, 4.0);
  ASSERT_TRUE(Point::distance(p, p1) == sqrt(pow(p.get_x() - p1.get_x(), 2) + pow(p.get_y() - p1.get_y(), 2)));
}

TEST(test_point_vector, init1) {
  Point_vector p;
  ASSERT_TRUE(p.size() == 0);
}

TEST(test_point_vector, init2) {
  Point_vector p(10);
  ASSERT_TRUE(p.size() == 10);
}

TEST(test_point_vector, init3) {
  Point_vector p(3);
  ASSERT_TRUE(p[0] == Point(0,0) && p[1] == Point() && p[2] == Point(0.0, 0.0) && p.size() == 3);
}

TEST(test_point_vector, init4) {
  Point_vector p(3, Point(1.0, 0.0));
  ASSERT_TRUE(p[0] == Point(1.0,0) && p[1] == Point(1.0, 0.0) && p[2] == Point(1.0, 0.0) && p.size() == 3);
}

TEST(test_point_vector, init5) {
  Point_vector p({Point(), Point(1, 1), Point(2, 2)});
  ASSERT_TRUE(p[0] == Point() && p[1] == Point(1.0, 1.0) && p[2] == Point(2.0, 2.0) && p.size() == 3);
}

TEST(test_point_vector, init6) {
  std::vector<Point> v = {Point(), Point(1, 1), Point(2, 2)};
  Point_vector p(v);
  ASSERT_TRUE(p[0] == Point() && p[1] == Point(1.0, 1.0) && p[2] == Point(2.0, 2.0) && p.size() == 3);
}

TEST(test_point_vector, init7) {
  Point_vector p = {Point(1.1, 1.1)};
  ASSERT_TRUE(p[0] == Point(1.1, 1.1) && p.size() == 1);
}

TEST(test_point_vector, init9) {
  Point_vector p = {Point(1.1, 1.1)};
  Point_vector p1(p);
  ASSERT_TRUE(p1[0] == Point(1.1, 1.1) && p1.size() == 1);
}

TEST(test_point_vector, init10) {
  Point_vector p = {Point(1.1, 1.1)};
  Point_vector p1(p);
  ASSERT_TRUE(p1[0] == Point(1.1, 1.1) && p1.size() == 1);
}

TEST(test_point_vector, init11) {
  Point_vector p = {};
  ASSERT_TRUE(p.size() == 0);
}


TEST(test_point_vector, init13) {
  std::vector<Point> v(0);
  Point_vector p(v);
  ASSERT_TRUE(p.size() == 0);
}


TEST(test_point_vector, eq1) {
  Point_vector p = {Point(1.1, 1.1)};
  Point_vector p1(1, Point(1.1, 1.1));
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, eq2) {
  Point_vector p = {Point(1.1, 1.1)};
  ASSERT_TRUE(p == p);
}

TEST(test_point_vector, eq3) {
  Point_vector p = {Point(1.1, 1.1), Point()};
  Point_vector p1 = p;
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, eq4) {
  Point_vector p = {Point(1.1, 1.1), Point()};
  Point_vector p1({Point(1.1, 1.1)});
  ASSERT_TRUE(p1 != p);
}

TEST(test_point_vector, eq5) {
  Point_vector p = {Point(1.1, 1.1), Point()};
  std::vector<Point> v = {Point(1.1, 1.1), Point()};
  Point_vector p1(v);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, eq6) {
  Point_vector p = {Point(1.1, 1.1), Point()};
  Point_vector p1(2, Point(1.1, 1.1));
  ASSERT_TRUE(p1 != p);
}

TEST(test_point_vector, eq7) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1(3, Point(1.1, 1.1));
  ASSERT_TRUE(p1 != p);
}

TEST(test_point_vector, eq8) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1(p);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, push_back1) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1(p);
  p1.push_back(Point());
  ASSERT_TRUE(p1 != p && p1[2] == Point() && p1[0] == p[0] && p1[1] == p[1]);
}

TEST(test_point_vector, push_back2) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1;
  p1.push_back(Point(Point(1.1, 1.1)));
  p1.push_back(Point(Point(1.1, 1.1)));
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, push_back3) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1 = p;
  p1.push_back(Point(Point(1.1, 1.1)));
  p1.push_back(Point(Point(1.1, 1.1)));
  ASSERT_TRUE(p1 != p);
}

TEST(test_point_vector, pop_back1) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1;
  p.pop_back();
  p.pop_back();
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, pop_back2) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  p.pop_back();
  p.pop_back();
  ASSERT_THROW(p.pop_back(), std::range_error);
}

TEST(test_point_vector, pop_back3) {
  Point_vector p;
  ASSERT_THROW(p.pop_back(), std::range_error);
}
TEST(test_point_vector, pop_back4) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  p.pop_back();
  p.pop_back();
  ASSERT_THROW(p.pop_back(), std::range_error);
}

TEST(test_point_vector, pop_back5) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1 = p;
  p.pop_back();
  p.pop_back();
  ASSERT_TRUE(p1 != p && p1[0] == Point(1.1, 1.1) && p1[1] == Point(1.1, 1.1) && p.size() == 0);
}

TEST(test_point_vector, erace1) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1 = p;
  p.erase(0);
  p1.erase(1);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, erace2) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  ASSERT_THROW(p.erase(3), std::range_error);
}

TEST(test_point_vector, erace3) {
  Point_vector p;
  ASSERT_THROW(p.erase(0), std::range_error);
}

TEST(test_point_vector, erace4) {
  Point_vector p = {Point(1.1, 1.1), Point(1.1, 1.1)};
  Point_vector p1 = p;
  p.erase(0);
  p1.erase(0);
  ASSERT_TRUE(p1 == p);
}
TEST(test_point_vector, erace5) {
  Point_vector p = {Point(1.1, 1.1), Point(), Point(2, 2)};
  p.erase(1);
  ASSERT_TRUE(p.size() == 2 && p[0] == Point(1.1, 1.1) && p[1] == Point(2, 2));
}
TEST(test_point_vector, size1) {
  Point_vector p = {Point(1.1, 1.1), Point(), Point(2, 2)};
  Point_vector p1(10, Point(1, 1));
  p1.pop_back();
  p.erase(2);
  ASSERT_TRUE(p.size() == 2 && p1.size() == 9);
}

TEST(test_point_vector, operator_get) {
  Point_vector p = {Point(1.1, 1.1), Point(), Point(2, 2)};
  ASSERT_TRUE(p[1] == Point(0.0,0.0) && p[0] == Point(1.1, 1.1) && p[2] == Point(2, 2));
}

TEST(test_point_vector, operator_get1) {
  Point_vector p = {Point(1.1, 1.1), Point(), Point(2, 2)};
  ASSERT_THROW(p[3], std::logic_error);
}

TEST(test_point_vector, operator_get2) {
  Point_vector p = {Point(1.1, 1.1), Point(), Point(2, 2)};
  ASSERT_THROW(p[4], std::logic_error);
}

TEST(test_point_vector, operator_get3) {
  Point_vector p;
  ASSERT_THROW(p[0], std::logic_error);
}
TEST(test_point_vector, denay1) {
  Point_vector p;
  p.~Point_vector();
  ASSERT_TRUE(p.size() == 0);
}

TEST(test_hexagon, init1) {
  Hexagon p({Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)});
  ASSERT_TRUE(p.get_center() == Point(0.5, 0.866667));
}

TEST(test_hexagon, init2) {
  std::vector v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p(v);
  ASSERT_TRUE(p.get_center() == Point(0.5, 0.866667));
}

TEST(test_hexagon, init3) {
  Point_vector v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p(v);
  ASSERT_TRUE(p.get_center() == Point(0.5, 0.866667));
}

TEST(test_hexagon, init4) {
  Point_vector v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p(v);
  ASSERT_TRUE(p.get_center() == Point(0.5, 0.866667));
}

TEST(test_hexagon, init5) {
  Hexagon v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p(v);
  ASSERT_TRUE(p.get_center() == Point(0.5, 0.866667) && v == p);
}

TEST(test_hexagon, init6) {
  Hexagon v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p = v;
  ASSERT_TRUE(p.get_center() == Point(0.5, 0.866667) && v == p);
}


TEST(test_hexagon, init7) {
  ASSERT_THROW(Hexagon v, std::range_error);
}

TEST(test_hexagon, init8) {
  std::vector vec = {Point(0,0), Point(1, 0), Point(0, 1.73), Point(-0.5, 0.87)};
  ASSERT_THROW(Hexagon v(vec), std::range_error);
}

TEST(test_hexagon, init9) {
  std::vector vec = {Point(0,0), Point(1, 0), Point(1.4, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  ASSERT_THROW(Hexagon v(vec), std::range_error);
}

TEST(test_hexagon, init10) {
    ASSERT_NO_THROW(Hexagon t({Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)}));
}

TEST(test_hexagon, get_points) {
  Point_vector v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p(v);
  ASSERT_TRUE(p.get_points() == v);
}

TEST(test_hexagon, get_center) {
  Point_vector v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p(v);
  Hexagon p1(p);
  ASSERT_TRUE(p.get_center() == p1.get_center() && p1.get_center() == Point(0.5, 0.866667));
}

TEST(test_hexagon, operator_double) {
  Point_vector v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p(v);
  ASSERT_TRUE((double) p - 2.59808 < EPSILON);
}

TEST(test_hexagon, operator_double1) {
  Point_vector v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p(v);
  ASSERT_TRUE((double) p - 3 * std::pow(3, 0.5) / 2 < EPSILON);
}

TEST(test_hexagon, eq1) {
  Hexagon v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p = v;
  ASSERT_TRUE(v == p && v.get_center() == p.get_center() && (double) v == (double) p);
}
TEST(test_hexagon, eq2) {
  Hexagon v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p = {Point(0,0), Point(2, 0), Point(3, 1.73), Point(2, 3.46), Point(0, 3.46), Point(-1, 1.73)};
  ASSERT_TRUE(v != p && 2 * ((double) v) - (double) p < EPSILON);
}
TEST(test_hexagon, eq3) {
  Hexagon v = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  Hexagon p = v;
  ASSERT_TRUE(v == p);
}


TEST(test_rhombus, init1) {
  ASSERT_NO_THROW(Rhombus p({Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)}));
}

TEST(test_rhombus, init2) {
  std::vector v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p(v);
  ASSERT_TRUE(p.get_center() == Point(0, 1));
}

TEST(test_rhombus, init3) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p(v);
  ASSERT_TRUE(p.get_center() == Point(0, 1));
}

TEST(test_rhombus, init4) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p(v);
  ASSERT_TRUE(p.get_center() == Point(0, 1));
}

TEST(test_rhombus, init5) {
  Rhombus v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p(v);
  ASSERT_TRUE(p.get_center() ==  Point(0, 1) && v == p);
}

TEST(test_rhombus, init6) {
  Rhombus v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p = v;
  ASSERT_TRUE(p.get_center() == Point(0, 1) && v == p);
}


TEST(test_rhombus, init7) {
  ASSERT_THROW(Rhombus v, std::range_error);
}

TEST(test_rhombus, init8) {
  std::vector vec = {Point(0,0), Point(1, 0), Point(0, 1.73), Point(-0.5, 0.87)};
  ASSERT_THROW(Rhombus v(vec), std::range_error);
}

TEST(test_rhombus, init9) {
  std::vector vec = {Point(0,0), Point(1, 0), Point(1.4, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  ASSERT_THROW(Rhombus v(vec), std::range_error);
}
TEST(test_rhombus, init10) {
  std::vector vec = {Point(0,0), Point(1, 0), Point(1.9, 0), Point(-1, 1)};
  ASSERT_THROW(Rhombus v(vec), std::range_error);
}


TEST(test_rhombus, get_points) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p(v);
  ASSERT_TRUE(p.get_points() == v);
}

TEST(test_rhombus, get_center) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p(v);
  Rhombus p1(p);
  ASSERT_TRUE(p.get_center() == p1.get_center() && p1.get_center() == Point(0, 1));
}

TEST(test_rhombus, operator_double) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p(v);
  ASSERT_TRUE((double) p - 2 < EPSILON);
}

TEST(test_rhombus, operator_double1) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p(v);
  ASSERT_TRUE((double) p - (Point::distance(v[0], v[2]) * Point::distance(v[1], v[3])) / 2 < EPSILON);
}

TEST(test_rhombus, eq1) {
  Rhombus v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p = v;
  ASSERT_TRUE(v == p && v.get_center() == p.get_center() && (double) v == (double) p);
}
TEST(test_rhombus, eq2) {
  Rhombus v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p = {Point(0,0), Point(2, 2), Point(0, 4), Point(-2, 2)};
  ASSERT_TRUE(v != p && 2 * ((double) v) - (double) p < EPSILON);
}
TEST(test_rhombus, eq3) {
  Rhombus v = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Rhombus p = v;
  ASSERT_TRUE(v == p);
}



TEST(test_pentagon, init1) {
  ASSERT_NO_THROW(Pentagon p({Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)}));
}

TEST(test_pentagon, init2) {
  std::vector v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  ASSERT_NO_THROW(Pentagon p(v));
}

TEST(test_pentagon, init3) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  ASSERT_NO_THROW(Pentagon p(v));
}

TEST(test_pentagon, init4) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p(v);
  std::cout << p.get_center();
  ASSERT_TRUE(p.get_center() == Point(-0.188, 1.188));
}

TEST(test_pentagon, init5) {
  Pentagon v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p(v);
  ASSERT_TRUE(p.get_center() == Point(-0.188, 1.188) && v == p);
}

TEST(test_pentagon, init6) {
  Pentagon v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p = v;
  ASSERT_TRUE(p.get_center() == Point(-0.188, 1.188) && v == p);
}


TEST(test_pentagon, init7) {
  ASSERT_THROW(Pentagon v, std::range_error);
}

TEST(test_pentagon, init8) {
  std::vector vec = {Point(0,0), Point(1, 0), Point(0, 1.73), Point(-0.5, 0.87)};
  ASSERT_THROW(Pentagon v(vec), std::range_error);
}

TEST(test_pentagon, init9) {
  std::vector vec = {Point(0,0), Point(1, 0), Point(1.4, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  ASSERT_THROW(Pentagon v(vec), std::range_error);
}
TEST(test_pentagon, init10) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0.36, 2.3), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  ASSERT_THROW(Pentagon p(v), std::range_error);
}

TEST(test_pentagon, get_points) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p(v);
  ASSERT_TRUE(p.get_points() == v);
}

TEST(test_pentagon, get_center) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p(v);
  Pentagon p1(p);
  ASSERT_TRUE(p.get_center() == p1.get_center() && p1.get_center() == Point(-0.188, 1.188));
}

TEST(test_pentagon, operator_double) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p(v);
  std::cout << (double) p;
  ASSERT_TRUE((double) p - 3.44095 < EPSILON);
}

TEST(test_pentagon, operator_double1) {
  Point_vector v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p(v);
  ASSERT_TRUE((double) p - std::pow(Point::distance(v[0], v[1]), 2) * ((sqrt(5.0) * sqrt(5.0 + 2.0 * sqrt(5.0)))/ 4.0) < EPSILON);
}

TEST(test_pentagon, eq1) {
  Pentagon v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p = v;
  ASSERT_TRUE(v == p && v.get_center() == p.get_center() && (double) v == (double) p);
}
TEST(test_pentagon, eq2) {
  Pentagon v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p = {Point(0,0), Point(2, 2), Point(0.72, 4.52), Point(-2.08, 4.08), Point(-2.52, 1.28)};
  ASSERT_TRUE(v != p && 2 * ((double) v) - (double) p < EPSILON);
}
TEST(test_pentagon, eq3) {
  Pentagon v = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Pentagon p = v;
  ASSERT_TRUE(v == p);
}


TEST(test_array, init1) {
  FigureArray p;
  ASSERT_TRUE(p.size() == 0);
}

TEST(test_array, init2) {
  FigureArray p(10);
  ASSERT_TRUE(p.size() == 10);
}


TEST(test_array, init3) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a({&r, &p, &h});
  ASSERT_TRUE(*a[0] == r && *a[1] == p && *a[2] == h && a.size() == 3);
}

TEST(test_array, init6) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  std::vector<Figure*> v = {&r, &p, &h};
  FigureArray a(v);
  ASSERT_TRUE(*a[0] == r && *a[1] == p && *a[2] == h && a.size() == 3);
}

TEST(test_array, init7) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r, &p, &h};
  ASSERT_TRUE(*a[0] == r && *a[1] == p && *a[2] == h && a.size() == 3);
}

TEST(test_array, init11) {
  FigureArray p = {};
  ASSERT_TRUE(p.size() == 0);
}


TEST(test_array, init13) {
  std::vector<Figure *> v(0);
  FigureArray p(v);
  ASSERT_TRUE(p.size() == 0);
}


TEST(test_array, push_back1) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r, &p};
  a.push_back(&h);
  ASSERT_TRUE(*a[0] == r && *a[1] == p && *a[2] == h && a.size() == 3);
}

TEST(test_array, push_back2) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r};
  a.push_back(&p);
  a.push_back(&h);
  ASSERT_TRUE(*a[0] == r && *a[1] == p && *a[2] == h && a.size() == 3);
}


TEST(test_array, pop_back1) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r, &p, &h};
  a.pop_back();
  a.pop_back();
  a.pop_back();
  ASSERT_THROW(a.pop_back(), std::range_error);
}

TEST(test_array, pop_back2) {
  FigureArray p;
  ASSERT_THROW(p.pop_back(), std::range_error);
}
TEST(test_array, pop_back3) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r, &p, &h};
  a.pop_back();
  a.pop_back();
  ASSERT_TRUE(*a[0] == r && a.size() == 1);
}


TEST(test_array, erace1) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r, &p, &h};
  a.erase(0);
  a.erase(1);
  ASSERT_TRUE(*a[0] == p && a.size() == 1);
}


TEST(test_array, erace2) {
  FigureArray p;
  ASSERT_THROW(p.erase(0), std::range_error);
}


TEST(test_array, operator_get1) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r, &p, &h};
  ASSERT_THROW(a[3], std::logic_error);
}

TEST(test_array, operator_get2) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r, &p, &h};
  ASSERT_THROW(a[4], std::logic_error);
}

TEST(test_array, operator_get3) {
  FigureArray p;
  ASSERT_THROW(p[0], std::logic_error);
}
TEST(test_array, denay1) {
  FigureArray p;
  p.~FigureArray();
  ASSERT_TRUE(p.size() == 0);
}

TEST(test_array, oper_double) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
  Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
  FigureArray a = {&r, &p, &h};
  ASSERT_TRUE((double) a == (double) r + (double) h + (double) p);
}

TEST(test_array, oper_double1) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  FigureArray a = {&r};
  ASSERT_TRUE((double) a == 2.0);
}

TEST(test_array, oper_double2) {
  Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
  FigureArray a = {&r};
  a.pop_back();
  ASSERT_THROW((double) a, std::range_error);
}
int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}