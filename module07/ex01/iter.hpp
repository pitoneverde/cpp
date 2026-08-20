#ifndef ITER_HPP
#define ITER_HPP

// if elemns not const, neither is the array
template<typename T>
void iter(T* arr, const size_t len, void (*func)(T&)) {
    for (size_t i = 0; i < len; ++i)
        func(arr[i]);
}

// if elems are const, arr is const too
template<typename T>
void iter(const T* arr, const size_t len, void (*func)(T const&)) {
    for (size_t i = 0; i < len; ++i)
        func(arr[i]);
}

#endif