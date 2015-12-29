#ifndef CONTEXT_H
#define CONTEXT_H

#include "functor.h"

class Context
{
protected:
    Functor * func_;

public:
    virtual ~Context() {}
    virtual double useStrategy(const double & arg) = 0;
    virtual void setStrategy(Functor * f) = 0;
};

#endif // CONTEXT_H
