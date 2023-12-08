#include "array.h"

FigureArray::FigureArray(){
    capacity = 2;
    _size = 0;
    array = new Figure*[capacity];
}

FigureArray::FigureArray(const std::initializer_list<Figure *> &list) {
    if(list.size() == 0){
        capacity = 2;
        _size = 0;
        array = new Figure *[capacity];
    } else {
        _size = list.size();
        capacity = 2 * list.size();
        array = new Figure *[capacity];
        size_t i = 0;
        for (Figure * f: list) {
            array[i] = f;
            i++;
        }
    }
}

FigureArray::FigureArray(const std::vector<Figure *> &vector) {
    if(vector.size() == 0){
        capacity = 2;
        _size = 0;
        array = new Figure *[capacity];
    } else {
        _size = vector.size();
        capacity = 2 * vector.size();
        array = new Figure *[capacity];
        size_t i = 0;
        for (Figure * f: vector) {
            array[i] = f;
            i++;
        }
    }
}

FigureArray::FigureArray(size_t n){
    _size = n;
    if (_size != 0){
        capacity = _size * 2;
    } else {
        capacity = 2;
    }
    array = new Figure*[capacity];
}

FigureArray::~FigureArray() {
    _size = 0;
    capacity = 0;
    if(array != nullptr){
         delete[] array;
    }
    array = nullptr;
}

void FigureArray::relloc(size_t new_capacity){
    Figure** temp = new Figure*[_size];
    memcpy(temp, array, _size * sizeof(Figure*));
    delete[] array;
    capacity = new_capacity;
    array = new Figure*[capacity];
    memcpy(array, temp, _size * sizeof(Figure*));
    delete[] temp;
}
void FigureArray::push_back(Figure *figure) {
    if (_size >= capacity) {
        this->relloc(capacity * 2);
    }
    array[_size] = figure;
    _size++;
} 

std::ostream &operator << (std::ostream& os, const FigureArray &f) {
    if (f._size == 0) {
        throw std::range_error("empty array");
    }
    for (size_t i = 0; i < f._size; ++i) {
        switch (f.array[i]->get_points().size()) {
            case 4: std::cout << "rhombus\n"; break;
            case 5: std::cout << "pentagon\n"; break;
            case 6: std::cout << "hexagon\n"; break;
        }
        std::cout << *(f.array[i]);
    }
    return os;
}

FigureArray::operator double(){
    if (_size == 0) {
        throw std::range_error("empty array");
    }
    double res = 0;
    for(int i = 0; i < _size; i++){
        res += double(*array[i]);
    }
    return res;
}

void FigureArray::pop_back() {
    if (_size == 0) {
        throw std::range_error("can't pop from empty array");
    } else {
        _size--;
        if (_size * 2 == capacity){
            this->relloc(capacity / 2);
        }
    }
}

void FigureArray::erase(size_t idx) {
    if (idx >= _size) {
        throw std::range_error("index error");
    }
    for (size_t i = idx; i < _size - 1; i++) {
        array[i] = array[i + 1];
    }
    _size--;
    if (_size * 2 == capacity){
        this->relloc(capacity / 2);
    }
}

Figure** FigureArray::get_arr() {
    return array;
}

size_t FigureArray::size() {
    return _size;
}

Figure* FigureArray::operator[](size_t index) {
    if (index >= _size) {
        throw std::logic_error("index error");
    }
    return array[index];
}