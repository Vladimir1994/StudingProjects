#ifndef ABSTRACTFUNCTOR_H
#define ABSTRACTFUNCTOR_H

class AbstractFunctor
{
public:
    virtual double operator()(double val) = 0;
    virtual ~AbstractFunctor() {}
};

#endif // ABSTRACTFUNCTOR_H
