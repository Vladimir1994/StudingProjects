#ifndef VARIABLE_H
#define VARIABLE_H

#include "expression.h"
#include "scope.h"

struct Variable : Expression
{
    Variable(std::string const &name);
    std::string const &name() const;
    double evaluate(Scope *sc) const;
    Expression * transform(Transformer *tr) const;

private:
    std::string const name_;
};

#endif // VARIABLE_H
