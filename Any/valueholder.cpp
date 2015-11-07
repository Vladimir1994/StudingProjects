#include "valueholder.h"

template <typename T>
ValueHolder<T>::ValueHolder(T const & data) : data_(data) {}

template <typename T>
ICloneable * ValueHolder<T>::clone() const {
    ICloneable * p = new ValueHolder(this->data_);
    return p;
}
