#include "figure.h"
#include <cstring>

class FigureArray {
private:
    Figure **array;
    int _size;
    int capacity;
    void relloc();
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
    int size();
    Figure* operator[](size_t index);
    operator double();
    friend std::ostream &operator << (std::ostream& os, const FigureArray& f);
};