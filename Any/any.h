#ifndef ANY_H
#define ANY_H

#include "icloneable.h"
#include "valueholder.h"

class Any
{
public:
    Any();

    template <class T>
    Any(const T &p);

    Any(Any const &any);

    ~Any();

    Any & operator=(Any const &any);

    template <class T>
    Any & operator=(T const &ptr);

    template <class T>
    T * cast();

private:
    ICloneable *ptr_;
};

#include "any.tpp"

#endif // ANY_H
