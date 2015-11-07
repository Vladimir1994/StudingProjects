#include "latte.h"

#include <iostream>

Latte::Latte(double price) : IDrink(price) {}

double Latte::price() {
    return price_;
}

void Latte::recStepTwo() {
    std::cout << "Dripping coffe through filter." << std::endl;
    std::cout << "Heat up some milk." << std::endl;
}

void Latte::recStepFour() {
    std::cout << "Add milk." << std::endl;
}
