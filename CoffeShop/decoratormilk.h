#ifndef DECORATORMILK_H
#define DECORATORMILK_H

#include "idecorator.h"

class DecoratorMilk : public IDecorator {
public:
    DecoratorMilk(IProduct * product = 0, double price = 0.4);
    virtual double price();
};
#endif // DECORATORMILK_H
