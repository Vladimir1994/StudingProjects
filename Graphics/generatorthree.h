#ifndef GENERATORTHREE_H
#define GENERATORTHREE_H

#include <math.h>
#include "generator.h"

class GeneratorThree : public Generator
{
public:
    double generate(double val)
    {
        return sin(2 * val);
    }
    ~GeneratorThree() {}
};

#endif // GENERATORTHREE_H
