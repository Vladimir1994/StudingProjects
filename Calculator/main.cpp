#include "calculator.h"
#include "sinfunctorone.h"
#include "sinfunctortwo.h"
#include "sinfunctorthree.h"

#include <iostream>

int main()
{
    Functor *f_1 = new SinFunctorOne();
    Functor *f_2 = new SinFunctorTwo();
    Functor *f_3 = new SinFunctorThree();

    Calculator calc;

    calc.setStrategy(f_1);
    std::cout << calc.useStrategy(10) << std::endl;

    calc.setStrategy(f_2);
    std::cout << calc.useStrategy(10) << std::endl;

    calc.setStrategy(f_3);
    std::cout << calc.useStrategy(10) << std::endl;

    return 0;
}

