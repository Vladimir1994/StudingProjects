#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"
#include "scope.h"
#include "transformer.h"

struct Number : Expression
{
    Number(double value);
    double value() const;
    double evaluate(Scope *sc) const;
    Expression * transform(Transformer *tr) const;

private:
    double value_;
};

#endif // NUMBER_H
