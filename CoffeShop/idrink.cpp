#include "idrink.h"

#include<iostream>

IDrink::IDrink(double price) : IProduct(price) {}

void IDrink::reciepe() {
   std::cout << "Boil water." << std::endl;
   recStepTwo();
   std::cout << "Pouring into cup." << std::endl;
   recStepFour();
}

