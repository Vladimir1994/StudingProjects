#ifndef SINFUNCTORTHREE_H
#define SINFUNCTORTHREE_H

#include <math.h>
#include "abstractfunctor.h"

class SinFunctorThree : public AbstractFunctor
{
public:
    double operator()(double val)
    {
        return sin(2*val);
    }
    ~SinFunctorThree() {}
};

#endif // SINFUNCTORTHREE_H
