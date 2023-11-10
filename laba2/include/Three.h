#pragma once

#include <iostream>
#include <exception>

class Three {
    public:

        Three();
        Three(const size_t &size, unsigned char c = '0');
        Three(const std::initializer_list<unsigned char> &list);
        Three(const std::string &list);
        Three(const Three &other);
        Three(Three &&other) noexcept;
        virtual ~Three() noexcept;

        bool operator <(const Three &other) const;
        bool operator <=(const Three &other) const;
        bool operator >=(const Three &other) const;
        bool operator >(const Three &other) const;
        bool operator == (const Three& other) const;
        bool operator !=(const Three &other) const;

        Three operator +(const Three &other) const;
        Three operator -(const Three &other) const;
        Three &operator +=(const Three &other);
        Three &operator -=(const Three &other);

        Three& operator=(const Three &other);
        void ResizeCopy(int n);
        void RemoveZeros();

        friend std::ostream& operator << (std::ostream &os, const Three &el);
        friend std::istream& operator >> (std::istream &stream, Three &el);

    private: 
        size_t _size;
        unsigned char *_array;
};