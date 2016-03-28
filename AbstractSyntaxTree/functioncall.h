#ifndef FUNCTIONCALL_H
#define FUNCTIONCALL_H

#include "expression.h"

#include <string>

class FunctionCall : public Expression
{
public:
    FunctionCall(std::string const &name, Expression const *arg);
    std::string const & name() const;
    Expression const *arg() const;
    double evaluate(Scope *sc) const;

    ~FunctionCall();

    Expression * transform(Transformer *tr) const;

private:
    std::string const name_;
    Expression const *arg_;

};

#endif // FUNCTIONCALL_H
