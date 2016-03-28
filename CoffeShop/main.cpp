#include "coffe.h"
#include "latte.h"
#include "espresso.h"
#include "decoratorchocolate.h"
#include "decoratormilk.h"

#include <iostream>

int main()
{
    DecoratorChocolate EspressoWithChocolateandMilk(new DecoratorMilk(new Espresso()));
    std::cout << EspressoWithChocolateandMilk.price() << std::endl;

    DecoratorMilk CoffeWithMilk(new Coffe());
    std::cout << CoffeWithMilk.price() << std::endl;

    std::cout << std::endl;

    Coffe coffe;
    coffe.reciepe();

    std::cout << std::endl;

    Espresso espresso;
    espresso.reciepe();

    return 0;
}

