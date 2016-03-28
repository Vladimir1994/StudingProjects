#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
public:
    Array(size_t size, const T &value = T());
    Array();
    Array & operator=(const Array &A);
    Array(const Array &A);
    ~Array();

    size_t size() const;
    T & operator[](size_t idx) const;

private:
    size_t size_;
    T *arr;
};

template <typename T, class comparator>
T minimum(Array<T> &A, comparator c);

template <typename T>
void flatten(const T &obj, std::ostream &out);

template <typename T>
void flatten(const Array<T> &array, std::ostream &out);

#include "array.tpp"

#endif // ARRAY_H
