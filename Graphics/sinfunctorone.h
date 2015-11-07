#ifndef CUBICFUNCTOR_H
#define CUBICFUNCTOR_H

#include <math.h>
#include "abstractfunctor.h"

class SinFunctorOne : public AbstractFunctor
{
public:
    double operator()(double val)
    {
        return sin(val);
    }
    ~SinFunctorOne() {}
};

#endif // CUBICFUNCTOR_H
