#include "Three.h"

Three::Three(){
    _size = 1;
    _array = new unsigned char[1];
    _array[0] = '0';
}

Three::Three(const size_t &size, unsigned char c){
    if (c > '2' || c < '0'){
        throw std::underflow_error("invalid symbol");
    }
    _size = size;
    _array = new unsigned char[_size];

    for (size_t i = 0; i < size; i++){
        _array[i] = c;
    }
    this->RemoveZeros();
}

Three::Three(const std::initializer_list<unsigned char> &list){
    _size = list.size();
    _array = new unsigned char[_size];

    size_t n = list.size() - 1;
    for (const unsigned char &c : list) { 
        if (c > '2' || c < '0'){
            throw std::underflow_error("invalid symbol");
        }
        _array[n] = c;
        n--;
    }
    this->RemoveZeros();
}

Three::Three(const std::string &list){
    _size  = list.size();
    _array = new unsigned char[_size];
    for(size_t i = 0; i < _size; i++) {
        if (list[i] > '2' || list[i] < '0'){
            throw std::underflow_error("invalid symbol");
        }
        _array[_size - i - 1] = list[i];
    }
    this->RemoveZeros();
}

Three::Three(const Three &other){
    _size  = other._size;
    _array = new unsigned char[_size];
    for(size_t i = 0; i < _size; i++){
        _array[i] = other._array[i];
    }
}

Three::Three(Three &&other) noexcept{
    _size = other._size;
    _array = other._array;
    other._size = 0;
    other._array = nullptr;
}

Three::~Three() noexcept{
    if (_array != nullptr){
        delete[] _array;
        _array = nullptr;
    }
    _size = 0;
}

void Three::RemoveZeros(){
    if (_array == nullptr) {
        return;
    }
    int flag = -1;
    for (size_t i = 0; i < _size; i++) {
        if (_array[_size - i - 1] != '0') {
            flag = i;
            break;
        }
    }
    if (flag == -1) {
        this->~Three();
        Three s;
        *this = s;
        return;
    }
    if (flag == 0){
        return;
    }
     _size -= flag;
    unsigned char * new_array = new unsigned char[_size];

    for (size_t i = 0; i < _size; i++) {
        new_array[i] = _array[i];
    }
    _array = new_array;
}

Three &Three::operator=(const Three &other){
    _size = other._size;
    _array = new unsigned char[_size];
    for(size_t i = 0; i < _size; i++){
        _array[i] = other._array[i];
    }
    return *this;
}


bool Three::operator==(const Three &other) const{
    if (other._size != _size){
        return false;
    }
    for (size_t i = 0; i < _size; ++i){
        if (_array[i] != other._array[i]){
            return false;
        }
    }
    return true;
}

bool Three::operator!=(const Three &other) const{
    return !(*this == other);
}

bool Three::operator>(const Three &other) const{
    if (_size != other._size){
        return _size > other._size;
    }
    for (size_t i = _size - 1; i > -1; i--){
        if(_array[i] != other._array[i]){
            return _array[i] > other._array[i];
        }
    }
    return false;
}

bool Three::operator>=(const Three &other) const{
    return (*this > other || *this == other);
}

bool Three::operator<(const Three &other) const{
    return !(*this >= other);
}

bool Three::operator<=(const Three &other) const{
    return !(*this > other);
}

Three Three::operator+(const Three &second) const{
    Three first = *this;
    Three result(std::max(first._size, second._size) + 1, '1');
    result._array[result._size - 1] = '0';
    int carry = 0;
    for (size_t i = 0; i < result._size - 1; i++){
        int sum = carry;
        if (i < first._size) {
            sum += first._array[i] - '0';
        }
        if (i < second._size) {
            sum += second._array[i] - '0';
        }
        result._array[i] = sum % 3 + '0';
        carry = sum / 3;
    }
    if (carry > 0){
        result._array[result._size - 1] = carry + '0';
    }
    result.RemoveZeros();
    return result;    
}

Three Three::operator-(const Three& second) const {
    Three first = *this;
    int carry = 0;
    if (first < second) {
        throw std::invalid_argument("Result can't be negative");
    }
    Three result(first._size, '1');
    result._array[result._size - 1] = '0';
    for (size_t i = 0; i < result._size; i++) {
        int first_num = 0 - carry;
        carry = 0;
        int second_num = 0;
        first_num += first._array[i] - '0';
        if (i < second._size){
            second_num = second._array[i] - '0';
        }
        if (first_num < second_num) {
            first_num += 3;
            carry = 1;
        }
        result._array[i] = (first_num - second_num) + '0';
    }
    result.RemoveZeros();
    return result;        
}

std::ostream &operator<<(std::ostream &os, const Three &elem){
    for (int i = elem._size - 1; i > -1; i--){
        os << elem._array[i];
    }
    return os;
}

std::istream &operator>>(std::istream &is, Three &elem){
    std::string str;
    is >> str;
    elem = Three(str);
    return is;
}

Three &Three::operator+=(const Three & other) {
    *(this)  = *(this) + other;
    return *(this);
}
    
Three &Three::operator-=(const Three & other) {
    *(this) = *(this) - other;
    return *(this);
}