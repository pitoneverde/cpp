#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array {
private:
    T* _arr;
    size_t _size;

public:
    // default init
    Array() : _arr(new T[0]), _size(0) {}
    // value init
    Array(unsigned int n) : _arr(new T[n]()), _size(n) {}
    Array(Array<T> const& arr) : _arr(new T[arr._size]), _size(arr._size) {
        for (size_t i = 0; i < arr._size; ++i)
            _arr[i] = arr[i];
    }

    size_t size() const {return _size;}

    Array<T>& operator=(Array<T> const& other) {
        if (this != &other) {
            delete[] _arr;
            _size = other._size;
            _arr = new T[_size];
            for (size_t i = 0; i < other._size; ++i)
            _arr[i] = other._arr[i];
        }
        return *this;
    }
    
    // overloaded for const-correctness
    T const& operator[](size_t idx) const {
        if (idx >= _size)
            throw std::exception();
        return _arr[idx];
    }
    T& operator[](size_t idx) {
        if (idx >= _size)
            throw std::exception();
        return _arr[idx];
    }

    ~Array() {
        delete[] _arr;
    }
};

#endif