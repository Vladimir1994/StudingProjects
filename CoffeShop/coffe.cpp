#include "coffe.h"

#include <iostream>

Coffe::Coffe(double price) : IDrink(price) {}

double Coffe::price() {
    return price_;
}

void Coffe::recStepTwo() {
    std::cout << "Make coffe." << std::endl;
}

void Coffe::recStepFour() {
    std::cout << "Add sugar." << std::endl;
}
