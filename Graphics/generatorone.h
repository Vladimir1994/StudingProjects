#ifndef GENERATORONE_H
#define GENERATORONE_H

#include <math.h>
#include "generator.h"

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
