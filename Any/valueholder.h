#ifndef VALUEHOLDER_H
#define VALUEHOLDER_H

#include "icloneable.h"

template <typename T>
class ValueHolder : ICloneable {
public:
    ValueHolder(T const & data);
    ICloneable * clone() const;

private:
    T data_;
};

#endif // VALUEHOLDER_H
