#ifndef SINFUNCTORTHREE_H
#define SINFUNCTORTHREE_H

#include <math.h>
#include "functor.h"

class SinFunctorThree : public Functor
{
public:
    double operator()(const double &val)
    {
        return sin(2 * val);
    }
    ~SinFunctorThree() {}
};

#endif // SINFUNCTORTHREE_H
