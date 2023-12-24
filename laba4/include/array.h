#pragma once
#include <memory>
#include <cstring>

template <class T>
class Array {
    friend std::ostream &operator << (std::ostream& os, const Array<T> &arr) {
        if (arr.size() == 0) {
            throw std::range_error("can't print empty array");
        }
        os << '[';
        for (int i = 0; i < arr.size(); i++) {
            if (i != arr.size() - 1) {
                os << arr[i] << ", ";
            } else {
                os << arr[i] << ']';
            }
        }
        os << '\n';
        return os;
    }  
    
    protected:
        int _size;
        int capacity;
        std::unique_ptr<T[]> array;
        void relloc(size_t new_capacity);
    public:
        Array();
        Array(const std::initializer_list<T> &list);
        Array(const Array &other);
        Array(Array &&other) noexcept;
        ~Array() = default;

        T & operator[] (const size_t &index) const;
        size_t size() const;
        bool operator == (const Array<T> &other) const;
        bool operator != (const Array<T> &other) const;
        void push_back(const T &elem);
        void erase(const size_t &idnex);
        void pop_back();

        Array<T> &operator=(Array<T> &other);
        Array<T> &operator=(Array<T> &&other) noexcept;
};