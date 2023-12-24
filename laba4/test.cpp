#include "point_src.hpp"
#include "array_src.hpp"
#include "hexagon.hpp"
#include "rhombus.hpp"
#include "pentagon.hpp"
#include "figure_src.hpp"
#include "array_fig.hpp"
#include <gtest/gtest.h>



TEST(test_point, test_init1) {
  Point<double> p;
  ASSERT_TRUE(p.get_x() == 0 && p.get_y() == 0);
}
TEST(test_point, test_init20) {
  Point<double> p;
  ASSERT_TRUE(p.get_x() == 0.0 && p.get_y() == 0.0);
}

TEST(test_point, test_init2) {
  Point<double> p(1.0, 1.0);
  ASSERT_TRUE(p.get_x() == 1.0 && p.get_y() == 1.0);
}
TEST(test_point, test_init21) {
  Point<double> p(1, 1);
  ASSERT_TRUE(p.get_x() == 1 && p.get_y() == 1);
}

TEST(test_point, test_init3) {
  Point<double> p(1.0, 1.0);
  Point<double> p1;
  p1 = p;
  ASSERT_TRUE(p1.get_x() == 1.0 && p1.get_y() == 1.0);
}

TEST(test_point, test_init4) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(p);
  ASSERT_TRUE(p1.get_x() == 1.0 && p1.get_y() == 1.0);
}

TEST(test_point, test_init5) {
  Point<double> p;
  Point<double> p1(p);
  ASSERT_TRUE(p1.get_x() == p.get_x() && p1.get_y() == p.get_y());
}

TEST(test_point, test_init6) {
  Point<double> p(2.0, 1.0);
  Point<double> p1(9, 9);
  p1 = p;
  ASSERT_TRUE(p1.get_x() == p.get_x() && p1.get_y() == p.get_y());
}

TEST(test_point, test_init7) {
  Point<double> p(2, 1);
  Point<double> p1(p);
  ASSERT_TRUE(p1.get_x() == 2 && p1.get_y() == 1);
}


TEST(test_point, test_eq1) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(2.0, 2.0);
  ASSERT_TRUE(p1 != p);
}

TEST(test_point, test_eq9) {
  Point<double> p(1, 1);
  Point<double> p1(2, 2);
  ASSERT_TRUE(p1 != p);
}

TEST(test_point, test_eq2) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(1.0, 1.0);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point, test_eq3) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(1.5, 1.5);
  ASSERT_TRUE(p1 != p);
}

TEST(test_point, test_eq4) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(1.0001, 1.0001);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point, test_eq5) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(p);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point, test_eq6) {
  Point<double> p(2.0, 1.0);
  Point<double> p1 = p;
  ASSERT_TRUE(p1 == p);
}

TEST(test_point, test_eq7) {
  Point<double> p(2.0, 1.0);
  Point<double> p1;
  ASSERT_TRUE(p1 != p);
}

TEST(test_point, test_eq8) {
  ASSERT_TRUE(Point<double>(2.2, 0) != Point<double>(2.1, 0));
}

TEST(test_point, get1) {
  Point<double> p(2.0, 1.0);
  ASSERT_TRUE(p.get_x() == 2.0 && p.get_y() == 1.0);
}

TEST(test_point, distance1) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(1.000, 1.000);
  ASSERT_TRUE(Point<double>::distance(p, p1) == 0);
}

TEST(test_point, distance2) {
  Point<double> p(1, 1);
  Point<double> p1(2, 1);
  ASSERT_TRUE(Point<double>::distance(p, p1) == 1);
}

TEST(test_point, distance3) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(p);
  ASSERT_TRUE(Point<double>::distance(p, p1) == 0);
}
TEST(test_point, distance4) {
  Point<double> p(1.0, 1.0);
  Point<double> p1 = p;
  ASSERT_TRUE(Point<double>::distance(p, p1) == 0);
}

TEST(test_point, distance5) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(2.0, 2.0);
  ASSERT_TRUE(Point<double>::distance(p, p1) == sqrt(2));
}

TEST(test_point, distance6) {
  Point<double> p(1, 1);
  Point<double> p1(2, 2);
  ASSERT_TRUE(Point<double>::distance(p1, p) == sqrt(2));
}

TEST(test_point, distance7) {
  Point<double> p;
  Point<double> p1(2, 6);
  ASSERT_TRUE(Point<double>::distance(p1, p) == sqrt(40));
}

TEST(test_point, distance8) {
  Point<double> p;
  Point<double> p1(2, 6);
  ASSERT_TRUE(Point<double>::distance(p, p1) == sqrt(40));
}

TEST(test_point, distance9) {
  Point<double> p;
  Point<double> p1(3.0, 4.0);
  ASSERT_TRUE(Point<double>::distance(p, p1) == 5.0);
}

TEST(test_point, distance10) {
  Point<double> p(1, 1);
  Point<double> p1(5, 4);
  ASSERT_TRUE(Point<double>::distance(p, p1) == 5);
}

TEST(test_point, distance11) {
  Point<double> p(1.0, 1.0);
  Point<double> p1(5.0, 4.0);
  ASSERT_TRUE(Point<double>::distance(p, p1) == sqrt(pow(p.get_x() - p1.get_x(), 2) + pow(p.get_y() - p1.get_y(), 2)));
}

TEST(test_Array, init1) {
  Array<double> p;
  ASSERT_TRUE(p.size() == 0);
}

TEST(test_Array, init2) {
  Array<double> p(Array<double>{1, 2, 3});
  ASSERT_TRUE(p[0] == 1 && p[1] == 2 && p[2] == 3 && p.size() == 3);
}

TEST(test_Array, init3) {
  Array<double> p({1, 2, 3});
  ASSERT_TRUE(p[0] == 1 && p[1] == 2 && p[2] == 3 && p.size() == 3);
}


TEST(test_Array, init6) {
  Array<Point<double>> p({Point<double>(), Point<double>(1, 1), Point<double>(2, 2)});
  ASSERT_TRUE(p[0] == Point<double>() && p[1] == Point<double>(1.0, 1.0) && p[2] == Point<double>(2.0, 2.0) && p.size() == 3);
}

TEST(test_Array, init7) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1)};
  ASSERT_TRUE(p[0] == Point<double>(1.1, 1.1) && p.size() == 1);
}

TEST(test_Array, init9) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1)};
  Array<Point<double>> p1(p);
  ASSERT_TRUE(p1[0] == Point<double>(1.1, 1.1) && p1.size() == 1);
}

TEST(test_Array, init10) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1)};
  Array<Point<double>> p1(p);
  ASSERT_TRUE(p1[0] == Point<double>(1.1, 1.1) && p1.size() == 1);
}

TEST(test_Array, init11) {
  Array<double> p = {};
  ASSERT_TRUE(p.size() == 0);
}


TEST(test_Array, init13) {
  Array<Point<double>> p({Point<double>(1.1, 1.1)});
  Array<Point<double>> p1 = p;
  ASSERT_TRUE(p1[0] == Point<double>(1.1, 1.1) && p1.size() == 1 && p1 == p);
}

TEST(test_Array, init14) {
  Array<Point<double>> p({Point<double>(1.1, 1.1)}), p1;
  p1 = std::move(p);
  ASSERT_TRUE(p1[0] == Point<double>(1.1, 1.1) && p1.size() == 1);
}
TEST(test_Array, init15) {
  Array<Point<double>> p({Point<double>(1.1, 1.1)});
  Array<Point<double>> p1(std::move(p));
  ASSERT_TRUE(p1[0] == Point<double>(1.1, 1.1) && p1.size() == 1);
}

TEST(test_point_vector, eq1) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1)};
  Array<Point<double>> p1(p);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, eq2) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1)};
  ASSERT_TRUE(p == p);
}

TEST(test_point_vector, eq3) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>()};
  Array<Point<double>> p1 = p;
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, eq4) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>()};
  Array<Point<double>> p1({Point<double>(1.1, 1.1)});
  ASSERT_TRUE(p1 != p);
}


TEST(test_point_vector, eq5) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  Array<Point<double>> p1(p);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, eq6) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  Array<Point<double>> p1 = {Point<double>(1.1, 1.2), Point<double>(1.1, 1.1)};
  ASSERT_TRUE(p1 != p);
}

TEST(test_point_vector, push_back1) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  Array<Point<double>> p1(p);
  p1.push_back(Point<double>());
  ASSERT_TRUE(p1 != p && p1[2] == Point<double>() && p1[0] == p[0] && p1[1] == p[1]);
}


TEST(test_point_vector, push_back3) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  Array<Point<double>> p1 = p;
  p1.push_back(Point<double>(1.1, 1.1));
  p1.push_back(Point<double>(1.1, 1.1));
  ASSERT_TRUE(p1 != p);
}

TEST(test_point_vector, pop_back1) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  Array<Point<double>> p1;
  p.pop_back();
  p.pop_back();
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, pop_back2) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  p.pop_back();
  p.pop_back();
  ASSERT_THROW(p.pop_back(), std::range_error);
}

TEST(test_point_vector, pop_back3) {
  Array<Point<double>> p;
  ASSERT_THROW(p.pop_back(), std::range_error);
}

TEST(test_point_vector, pop_back4) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  p.pop_back();
  p.pop_back();
  ASSERT_THROW(p.pop_back(), std::range_error);
}

TEST(test_point_vector, pop_back5) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  Array<Point<double>> p1 = p;
  p.pop_back();
  p.pop_back();
  ASSERT_TRUE(p1 != p && p1[0] == Point<double>(1.1, 1.1) && p1[1] == Point<double>(1.1, 1.1) && p.size() == 0);
}

TEST(test_point_vector, erace1) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1),  Point<double>(1.1, 1.1)};
  Array<Point<double>> p1 = p;
  p.erase(0);
  p1.erase(1);
  ASSERT_TRUE(p1 == p);
}

TEST(test_point_vector, erace2) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  ASSERT_THROW(p.erase(3), std::range_error);
}

TEST(test_point_vector, erace3) {
  Array<Point<double>> p;
  ASSERT_THROW(p.erase(0), std::range_error);
}

TEST(test_point_vector, erace4) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(1.1, 1.1)};
  Array<Point<double>> p1 = p;
  p.erase(0);
  p1.erase(0);
  ASSERT_TRUE(p1 == p);
}
TEST(test_point_vector, erace5) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(), Point<double>(2, 2)};
  p.erase(1);
  ASSERT_TRUE(p.size() == 2 && p[0] == Point<double>(1.1, 1.1) && p[1] == Point<double>(2, 2));
}

TEST(test_point_vector, operator_get) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(), Point<double>(2, 2)};
  ASSERT_TRUE(p[1] == Point<double>(0.0,0.0) && p[0] == Point<double>(1.1, 1.1) && p[2] == Point<double>(2, 2));
}

TEST(test_point_vector, operator_get1) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(), Point<double>(2, 2)};
  ASSERT_THROW(p[3], std::range_error);
}

TEST(test_point_vector, operator_get2) {
  Array<Point<double>> p = {Point<double>(1.1, 1.1), Point<double>(), Point<double>(2, 2)};
  ASSERT_THROW(p[4], std::range_error);
}

TEST(test_point_vector, operator_get3) {
  Array<Point<double>> p;
  ASSERT_THROW(p[0], std::range_error);
}

TEST(test_hexagon, init1) {
  Hexagon<double> p({Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)});
  ASSERT_TRUE(p.get_center() == Point<double>(0.5, 0.866667));
}

TEST(test_hexagon, init3) {
  Array<Point<double>> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(0.5, 0.866667));
}

TEST(test_hexagon, init4) {
  Array<Point<double>> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(0.5, 0.866667));
}

TEST(test_hexagon, init5) {
  Hexagon<double> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(0.5, 0.866667) && v == p);
}

TEST(test_hexagon, init6) {
  Hexagon<double> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p = v;
  ASSERT_TRUE(p.get_center() == Point<double>(0.5, 0.866667) && v == p);
}



TEST(test_hexagon, init8) {
  Array<Point<double>> v = {Point<double>(1,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  ASSERT_THROW(Hexagon<double> p(v), std::range_error);
}


TEST(test_hexagon, init10) {
    ASSERT_NO_THROW(Hexagon<double> t({Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)}));
}

TEST(test_hexagon, get_points) {
  Array<Point<double>> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p(v);
  ASSERT_TRUE(p.get_points() == v);
}

TEST(test_hexagon, get_center) {
  Array<Point<double>> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p(v);
  Hexagon<double> p1(p);
  ASSERT_TRUE(p.get_center() == p1.get_center() && p1.get_center() == Point<double>(0.5, 0.866667));
}

TEST(test_hexagon, operator_double) {
  Array<Point<double>> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p(v);
  ASSERT_TRUE((double) p - 2.59808 < EPSILON);
}

TEST(test_hexagon, operator_double1) {
  Array<Point<double>> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p(v);
  ASSERT_TRUE((double) p - 3 * std::pow(3, 0.5) / 2 < EPSILON);
}

TEST(test_hexagon, eq1) {
  Hexagon<double> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p(v);
  ASSERT_TRUE(v.get_center() == p.get_center() && (double) v == (double) p);
}
TEST(test_hexagon, eq2) {
  Hexagon<double> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  Hexagon<double> p = {Point<double>(0,0), Point<double>(2, 0), Point<double>(3, 1.73), Point<double>(2, 3.46), Point<double>(0, 3.46), Point<double>(-1, 1.73)};
  ASSERT_TRUE(v != p && 2 * ((double) v) - (double) p < EPSILON);
}
TEST(test_hexagon, eq3) {
   Hexagon<double> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
   Hexagon<double> p = v;
  ASSERT_TRUE(v == p);
}

TEST(test_hexagon, eq4) {
   Hexagon<double> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
   Pentagon<double> p = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
   ASSERT_THROW(p = v, std::range_error);
}
TEST(test_hexagon, eq5) {
   Hexagon<double> v = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
   Rhombus<double> p = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
   ASSERT_THROW(p = v, std::range_error);
}

TEST(test_pentagon, init1) {
  Pentagon<double> p({Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)});
  ASSERT_TRUE(p.get_center() == Point<double>(-0.188, 1.188));
}

TEST(test_pentagon, init3) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(-0.188, 1.188));
}

TEST(test_pentagon, init4) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(-0.188, 1.188));
}

TEST(test_pentagon, init5) {
  Pentagon<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(-0.188, 1.188) && v == p);
}

TEST(test_pentagon, init6) {
  Pentagon<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p = v;
  ASSERT_TRUE(p.get_center() == Point<double>(-0.188, 1.188) && v == p);
}



TEST(test_pentagon, init8) {
  Array<Point<double>> v = {Point<double>(1,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  ASSERT_THROW(Pentagon<double> p(v), std::range_error);
}


TEST(test_pentagon, init10) {
    ASSERT_NO_THROW(Pentagon<double> t({Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)}));
}

TEST(test_pentagon, get_points) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p(v);
  ASSERT_TRUE(p.get_points() == v);
}

TEST(test_pentagon, get_center) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p(v);
  Pentagon<double> p1(p);
  ASSERT_TRUE(p.get_center() == p1.get_center() && p1.get_center() == Point<double>(-0.188, 1.188));
}

TEST(test_pentagon, operator_double) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p(v);
  ASSERT_TRUE((double) p - 3.44095 < EPSILON);
}

TEST(test_pentagon, operator_double1) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p(v);
  ASSERT_TRUE((double)p - std::pow(Point<double>::distance(v[0], v[1]), 2) * ((sqrt(5.0) * sqrt(5.0 + 2.0 * sqrt(5.0)))/ 4.0) < EPSILON);
}

TEST(test_pentagon, eq1) {
  Pentagon<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p(v);
  ASSERT_TRUE(v.get_center() == p.get_center() && (double) v == (double) p);
}
TEST(test_pentagon, eq2) {
  Pentagon<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Pentagon<double> p = {Point<double>(0,0), Point<double>(2, 2), Point<double>(0.72, 4.52), Point<double>(-2.08, 4.08), Point<double>(-2.52, 1.28)};
  ASSERT_TRUE(v != p && 2 * ((double) v) - (double) p < EPSILON);
}
TEST(test_pentagon, eq3) {
   Pentagon<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
   Pentagon<double> p = v;
  ASSERT_TRUE(v == p);
}

TEST(test_pentagon, eq4) {
   Pentagon<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
   Hexagon<double> h = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
   ASSERT_THROW(h = v, std::range_error);
}
TEST(test_pentagon, eq5) {
   Pentagon<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
   Rhombus<double> p = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
   ASSERT_THROW(p = v, std::range_error);
}


TEST(yest_rhombus, init1) {
  Rhombus<double> p({Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)});
  ASSERT_TRUE(p.get_center() == Point<double>(0, 1));
}

TEST(yest_rhombus, init3) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(0, 1));
}

TEST(yest_rhombus, init4) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(0, 1));
}

TEST(yest_rhombus, init5) {
  Rhombus<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p(v);
  ASSERT_TRUE(p.get_center() == Point<double>(0, 1) && v == p);
}

TEST(yest_rhombus, init6) {
  Rhombus<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p = v;
  ASSERT_TRUE(p.get_center() == Point<double>(0, 1) && v == p);
}



TEST(yest_rhombus, init8) {
  Array<Point<double>> v = {Point<double>(1,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  ASSERT_THROW(Rhombus<double> p(v), std::range_error);
}


TEST(yest_rhombus, init10) {
    ASSERT_NO_THROW(Rhombus<double> t({Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)}));
}

TEST(yest_rhombus, get_points) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p(v);
  ASSERT_TRUE(p.get_points() == v);
}

TEST(yest_rhombus, get_center) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p(v);
  Rhombus<double> p1(p);
  ASSERT_TRUE(p.get_center() == p1.get_center() && p1.get_center() == Point<double>(0, 1));
}

TEST(yest_rhombus, operator_double) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p(v);
  ASSERT_TRUE((double) p - 2.59808 < EPSILON);
}

TEST(yest_rhombus, operator_double1) {
  Array<Point<double>> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p(v);
  ASSERT_TRUE((double) p - 3 * std::pow(3, 0.5) / 2 < EPSILON);
}

TEST(yest_rhombus, eq1) {
  Rhombus<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Rhombus<double> p(v);
  ASSERT_TRUE(v.get_center() == p.get_center() && (double) v == (double) p);
}

TEST(yest_rhombus, eq3) {
   Rhombus<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
   Rhombus<double> p = v;
  ASSERT_TRUE(v == p);
}

TEST(yest_rhombus, eq4) {
   Rhombus<double> v = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
   Pentagon<double> p = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
   ASSERT_THROW(p = v, std::range_error);
}

TEST(test_array, eq) {
  Rhombus<double> r = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Pentagon<double> p = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Hexagon<double> h = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  ASSERT_TRUE(r != p && p != h);
}

TEST(test_array, eq1) {
  Rhombus<double> r = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
  Pentagon<double> p = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
  Hexagon<double> h = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
  ASSERT_TRUE(r != h && p != r);
}



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}