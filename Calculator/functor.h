#ifndef FUNCTOR_H
#define FUNCTOR_H

class Functor
{
public:
    virtual double operator()(const double &val) = 0;
    virtual ~Functor() {}
};

#endif // FUNCTOR_H
