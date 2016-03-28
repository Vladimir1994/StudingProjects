#ifndef CONTEXT_H
#define CONTEXT_H

#include "functor.h"

class Context
{
public:
    virtual ~Context() {}
    virtual double useStrategy(const double &arg) = 0;
    virtual void setStrategy(Functor *f) = 0;

protected:
    Functor *func_;
};

#endif // CONTEXT_H
