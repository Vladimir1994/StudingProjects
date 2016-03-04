#ifndef GENERATORTWO_H
#define GENERATORTWO_H

#include <math.h>
#include "generator.h"

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
