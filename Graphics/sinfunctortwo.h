#ifndef SINFUNCTORTWO_H
#define SINFUNCTORTWO_H

#include <math.h>
#include "functor.h"

class SinFunctorTwo : public Functor
{
public:
    double operator()(const double & val)
    {
        return sin(val / 3);
    }
    ~SinFunctorTwo() {}
};

#endif // SINFUNCTORTWO_H
