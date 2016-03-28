#ifndef EXPRESSION_H
#define EXPRESSION_H

class Scope;
class Transformer;

class Expression
{
public:
    virtual double evaluate(Scope *sc) const = 0;
    virtual ~Expression() {}
    virtual Expression * transform(Transformer *tr) const = 0;
};

#endif // EXPRESSION_H
