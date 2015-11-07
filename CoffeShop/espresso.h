#ifndef ESPRESSO_H
#define ESPRESSO_H

#include "idrink.h"

class Espresso : public IDrink
{
public:
    Espresso(double price = 1.5);
    virtual double price();

protected:
    virtual void recStepTwo();
    virtual void recStepFour();
};

#endif // ESPRESSO_H
