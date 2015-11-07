#include "espresso.h"

#include <iostream>

Espresso::Espresso(double price) : IDrink(price) {}

double Espresso::price() {
    return price_;
}

void Espresso::recStepTwo() {
    std::cout << "Make espresso." << std::endl;
}

void Espresso::recStepFour() {}
