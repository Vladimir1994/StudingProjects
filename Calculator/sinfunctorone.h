#ifndef CUBICFUNCTOR_H
#define CUBICFUNCTOR_H

#include <math.h>
#include "functor.h"

class SinFunctorOne : public Functor
{
public:
    double operator()(double val)
    {
        return sin(val);
    }
    ~SinFunctorOne() {}
};

#endif // CUBICFUNCTOR_H
