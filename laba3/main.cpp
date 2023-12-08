#include "include/point.h"
#include "include/point_vector.h"
#include "include/figure.h"
#include "include/hexagon.h"
#include "include/rhombus.h"
#include "include/pentagon.h"
#include "include/array.h"


int main(){
    Rhombus r = {Point(0, 0), Point(1, 1), Point(0, 2), Point(-1, 1)};
    Pentagon p = {Point(0, 0), Point(1, 1), Point(0.36, 2.26), Point(-1.04, 2.04), Point(-1.26, 0.64)};
    Hexagon h = {Point(0,0), Point(1, 0), Point(1.5, 0.87), Point(1, 1.73), Point(0, 1.73), Point(-0.5, 0.87)};
    FigureArray a = {&r, &p, &h};
    std::cout << a;
}