#ifndef ANY_H
#define ANY_H

#include "icloneable.h"
#include "valueholder.h"

class Any
{
public:
    Any();

    template <class T>
    Any(const T & p);

    Any(Any const & any);

    ~Any();

    Any & operator = (Any const & any);
    template <class T>
    Any & operator = (T const & ptr);

    template <class T>
    T * cast();

private:
    ICloneable * ptr_;
};

template <class T>
Any::Any(const T & p) : ptr_(new ValueHolder<T>(p)) { }

template <class T>
Any & Any::operator = (T const & ptr)
{
    delete ptr_;
    ptr_ = 0;
    ptr_ = new ValueHolder<T>(ptr);
    return *this;
}

template <class T>
T * Any::cast()
{
    if(!ptr_)
        return 0;
    ValueHolder<T> * value_holder = dynamic_cast<ValueHolder<T>*>(ptr_);
    if (!value_holder)
        return 0;
    return &(value_holder->data_);
}

#endif // ANY_H
