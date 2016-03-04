#ifndef GENERATOR_H
#define GENERATOR_H

class Generator
{
public:
    virtual double generate(double val) = 0;
    virtual ~Generator() {}
};

#endif // GENERATOR_H
