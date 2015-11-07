#ifndef DECORATORCHOCOLATE_H
#define DECORATORCHOCOLATE_H

#include "idecorator.h"

class DecoratorChocolate : public IDecorator {
public:
    DecoratorChocolate(IProduct * product = 0, double price = 0.8);
    virtual double price();
};

#endif // DECORATORCHOCOLATE_H
