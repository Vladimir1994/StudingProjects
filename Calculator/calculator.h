#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "context.h"

class Calculator: public Context
{
public:
    ~Calculator() {}
    virtual double useStrategy(double arg) override;
    virtual void setStrategy(Functor * f) override;
};

#endif // CALCULATOR_H
