#pragma once


#include "array_src.h"
#include "figure_src.h"

template <class T>
double get_area(const Array<Figure<T> *> &array) {
    double sum = 0;
    for (int i = 0; i < array.size(); i++) {
        sum += double(*array[i]);
    }
    return sum;
}