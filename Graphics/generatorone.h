#ifndef GENERATORONE_H
#define GENERATORONE_H

#include "generator.h"

#include <math.h>

class GeneratorOne : public Generator
{
public:
    double generate(double val)
    {
        return sin(val);
    }
    ~GeneratorOne() {}
};

#endif // GENERATORONE_H
