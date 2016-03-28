#ifndef TRANSFORMER_H
#define TRANSFORMER_H

class Expression;
class Number;
class BinaryOperation;
class FunctionCall;
class Variable;

class Transformer
{
public:
    virtual ~Transformer() {}
    virtual Expression *transformNumber(Number const *) = 0;
    virtual Expression *transformBinaryOperation(BinaryOperation const *) = 0;
    virtual Expression *transformFunctionCall(FunctionCall const *) = 0;
    virtual Expression *transformVariable(Variable const *) = 0;
};


#endif // TRANSFORMER_H
