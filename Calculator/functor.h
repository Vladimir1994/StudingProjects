#ifndef ABSTRACTFUNCTOR_H
#define ABSTRACTFUNCTOR_H

class Functor
{
public:
    virtual double operator()(double val) = 0;
    virtual ~Functor() {}
};

#endif // ABSTRACTFUNCTOR_H
