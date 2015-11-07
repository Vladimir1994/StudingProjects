#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

template <typename T>
class Array
{
public:
    Array(size_t size, const T& value = T());
    Array();
    Array& operator = (const Array &A);
    Array(const Array & A);
    ~Array();

    size_t size() const;
    T& operator[](size_t idx) const;

private:
    size_t size_;
    T *arr;
};

template <typename T, class comparator>
T minimum(Array<T> &A, comparator c);

template <typename T>
void flatten(const T& obj, std::ostream& out);

template <typename T>
void flatten(const Array<T>& array, std::ostream& out);

template <typename T>
Array<T>::Array(size_t size, const T & value) {
    size_ = size;
    arr = (T*)new char[size*sizeof(T)];
    for(int i = 0; i < size_; i++)
    {
        T * arr_ = arr + i;
        arr_ = new (arr + i) T(value);
    }
}

template <typename T>
Array<T>::Array() {
    size_ = 0;
    arr = (T*) new char[size_*sizeof(T)];
}

template <typename T>
Array<T>::Array(const Array & A) {
    size_ = A.size();
    if(A.arr != 0){
        arr = (T*)new char[A.size()*sizeof(T)];
        for(int i = 0; i < size_; i++)
        {
            T * arr_ = arr + i;
            arr_ = new (arr + i) T(A.arr[i]);
        }
    }
    else
        arr = 0;
}

template <typename T>
Array<T>::~Array() {
    for(int i = 0; i < size_; i++){
        arr[i].~T();
    }
    delete [] (char*)arr;
    arr = 0;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array & A) {
    if(this->arr != A.arr)
    {
        if(this->arr != 0)
        {
            for(int i = 0; i < size_; i++){
                arr[i].~T();
            }
            delete [] (char*) arr;
        }
        if(A.arr != 0)
        {
            size_ = A.size_;
            arr = (T*)new char[A.size()*sizeof(T)];
            for(int i = 0; i < size_; i++)
            {
                T * arr_ = arr + i;
                arr_ = new (arr + i) T(A.arr[i]);
            }
        }
        else
        {
            size_ = 0;
            arr = (T*) new char[size_*sizeof(T)];
        }
    }
    return *this;
}

template <typename T>
size_t Array<T>::size() const {
    return size_;
}

template <typename T>
T & Array<T>::operator [](size_t idx) const {
    return arr[idx];
}

template <typename T, class comparator>
T minimum(Array<T> &A, comparator c)
{
    T min = A[0];
    for(int i = 0; i < A.size(); i++)
    {
        if(c(A[i], min))
            min = A[i];
    }
    return min;
}

template <typename T>
void flatten(const T& obj, std::ostream& out)
{
    out << obj << " ";
}

template <typename T>
void flatten(const Array<T> & array, std::ostream& out)
{
    for(size_t i = 0; i < array.size(); i++)
    {
        flatten(array[i], out);
    }
}

#endif // ARRAY_H
