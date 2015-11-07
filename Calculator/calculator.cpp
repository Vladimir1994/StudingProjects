#include "calculator.h"

double Calculator::useStrategy(double arg) {
    return (*func_)(arg);
}

void Calculator::setStrategy(Functor * f) {
    func_ = f;
}
