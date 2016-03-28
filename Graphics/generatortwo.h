#ifndef GENERATORTWO_H
#define GENERATORTWO_H

#include "generator.h"

#include <math.h>

class GeneratorTwo : public Generator
{
public:
    double generate(double val)
    {
        return sin(val / 3);
    }
    ~GeneratorTwo() {}
};

#endif // GENERATORTWO_H
