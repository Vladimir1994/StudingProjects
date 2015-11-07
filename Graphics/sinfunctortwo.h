#ifndef SINFUNCTORTWO_H
#define SINFUNCTORTWO_H

#include <math.h>
#include "abstractfunctor.h"

class SinFunctorTwo : public AbstractFunctor
{
public:
    double operator()(double val)
    {
        return sin(val/3);
    }
    ~SinFunctorTwo() {}
};

#endif // SINFUNCTORTWO_H
