#pragma once

#include "figure.h"
#include <cstring>

class FigureArray {
private:
    Figure **array;
    size_t _size;
    size_t capacity;
    void relloc(size_t mewcapacity);
public:
    FigureArray();
    FigureArray(const std::initializer_list<Figure *> &list);
    FigureArray(const std::vector<Figure *> &vector);
    FigureArray(size_t n);
    ~FigureArray();
    void push_back(Figure * figure);
    void pop_back();
    void erase(size_t index);
    Figure** get_arr();
    size_t size();
    Figure* operator[](size_t index);
    operator double();
    friend std::ostream &operator << (std::ostream& os, const FigureArray& f);
};