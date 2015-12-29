#ifndef EXPRESSION_H
#define EXPRESSION_H

struct Scope;
struct Transformer;

struct Expression
{
    virtual double evaluate(Scope *sc) const = 0;
    virtual ~Expression() {}
    virtual Expression * transform(Transformer *tr) const = 0;
};

#endif // EXPRESSION_H
