#pragma once
#include "array.h"
#include "figure.h"
#include "hexagon.h"
#include "pentagon.h"
#include "Rhombus.h"

template <class T>
double get_area(const Array<Figure<T>*> &array) {
    double sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += double(*array[i]);
    }
    return sum;
}