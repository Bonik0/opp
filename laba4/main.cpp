#include "src/figure_src.h"
#include "src/array_src.h"
#include "src/hexagon.h"
#include "src/rhombus.h"
#include "src/pentagon.h"
#include "src/array_figure.h"


int main(){

    Rhombus<double> r = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0, 2), Point<double>(-1, 1)};
    Pentagon<double> p = {Point<double>(0, 0), Point<double>(1, 1), Point<double>(0.36, 2.26), Point<double>(-1.04, 2.04), Point<double>(-1.26, 0.64)};
    Hexagon<double> h = {Point<double>(0,0), Point<double>(1, 0), Point<double>(1.5, 0.87), Point<double>(1, 1.73), Point<double>(0, 1.73), Point<double>(-0.5, 0.87)};
    Array<Figure<double>*> s = {&r, &p, &h};
    std::cout << get_area(s) << "\n";
    std::cout << r << p << h;
}