#include "number.h"

Number::Number(double value)
    : value_(value)
{}

double Number::value() const
{
    return value_;
}

double Number::evaluate(Scope *sc) const
{
    return value_;
}

Expression * Number::transform(Transformer *tr) const
{
    return tr->transformNumber(this);
}
