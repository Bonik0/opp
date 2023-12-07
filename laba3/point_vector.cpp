#include "include/point_vector.h"
#include "point.cpp"
Point_vector::Point_vector(){
    capacity = 2;
    _size = 0;
    array = new Point[capacity];
}

Point_vector::Point_vector(const std::initializer_list<Point> &list) {
    if(list.size() == 0){
        Point_vector();
    } else {
        _size = list.size();
        capacity = 2 * list.size();
        array = new Point[capacity];
        size_t i = 0;
        for (Point f: list) {
            array[i] = f;
            i++;
        }
    }
}

Point_vector::Point_vector(const std::vector<Point> &vector) {
    if(vector.size() == 0){
        Point_vector();
    } else {
        _size = vector.size();
        capacity = 2 * vector.size();
        array = new Point[capacity];
        size_t i = 0;
        for (Point f: vector) {
            array[i] = f;
            i++;
        }
    }
}

Point_vector::Point_vector(size_t n){
    _size = n;
    if (_size != 0){
        capacity = _size * 2;
    } else {
        capacity = 2;
    }
    array = new Point[capacity];
}

Point_vector::Point_vector(size_t n, const Point point){
    _size = n;
    if (_size != 0){
        capacity = _size * 2;
    } else {
        capacity = 2;
    }
    array = new Point[capacity];
    for(size_t i = 0; i < _size; i++){
        array[i] = point;
    }
}
Point_vector::Point_vector(const Point_vector &other){
    _size = other.size();
    capacity = _size * 2;
    if(capacity == 0){
        capacity = 2;
    } 
    array = new Point[capacity];
    memcpy(array, other.get_arrey(), _size * sizeof(Point));
}

Point_vector::~Point_vector() {
    _size = 0;
    capacity = 0;
    delete[] array;
    array = nullptr;
}

Point_vector &Point_vector::operator = (const Point_vector &other){
    _size = other.size();
    capacity = _size * 2;
    if(capacity == 0){
        capacity = 2;
    } 
    array = new Point[capacity];
    memcpy(array, other.get_arrey(), _size * sizeof(Point));
    return *this;
}

bool Point_vector::operator == (const Point_vector &other) const{
    if(_size != other.size()){
        return false;
    }
    for(size_t i = 0; i < _size; i++){
        if(array[i] != other[i]){
            return false;
        }
    }
    return true;
}


bool Point_vector::operator != (const Point_vector &other) const{
    return !(*this == other);
}


void Point_vector::relloc(size_t new_capacity){
    Point* temp = new Point[_size];
    memcpy(temp, array, _size * sizeof(Point));
    delete[] array;
    capacity = new_capacity;
    array = new Point[capacity];
    memcpy(array, temp, _size * sizeof(Point));
    delete[] temp;
}

void Point_vector::push_back(const Point point) {
    if (_size >= capacity) {
        this->relloc(2 * capacity);
    }
    array[_size] = point;
    _size++;
} 

std::ostream &operator << (std::ostream& os, const Point_vector &vector) {
    if (vector._size == 0) {
        throw std::range_error("empty array");
    }
    for (size_t i = 0; i < vector._size; i++) {
        std::cout << (vector.array[i]);
    }
    return os;
}


void Point_vector::pop_back() {
    if (_size == 0) {
        throw std::range_error("can't pop from empty array");
    } else {
        _size--;
        if (_size * 2 == capacity){
            this->relloc(capacity / 2);
        }
    }
}

void Point_vector::erase(size_t idx) {
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

Point* Point_vector::get_arrey() const {
    return array;
}

size_t Point_vector::size() const{
    return _size;
}

Point Point_vector::operator[](size_t index) const{
    if (index >= _size) {
        throw std::logic_error("index error");
    }
    return array[index];
}