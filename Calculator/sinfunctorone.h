#ifndef SINFUNCTORONE_H
#define SINFUNCTORONE_H

#include <math.h>
#include "functor.h"

class SinFunctorOne : public Functor
{
public:
    double operator()(const double & val)
    {
        return sin(val);
    }
    ~SinFunctorOne() {}
};

#endif // SINFUNCTORONE_H
