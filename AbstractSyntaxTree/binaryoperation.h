#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"
#include "scope.h"

struct BinaryOperation : Expression
{
    enum
    {
        PLUS = '+',
        MINUS = '-',
        DIV = '/',
        MUL = '*'
    };

    BinaryOperation(Expression const *left, int op, Expression const *right);
    ~BinaryOperation();

    Expression const *left() const;
    Expression const *right() const;

    int operation() const;
    double evaluate(Scope *sc) const;

    Expression * transform(Transformer *tr) const;

private:
    Expression const *left_;
    Expression const *right_;
    int op_;
};

#endif // BINARYOPERATION_H
