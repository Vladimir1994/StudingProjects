#ifndef TRANSFORMER_H
#define TRANSFORMER_H

struct Expression;
struct Number;
struct BinaryOperation;
struct FunctionCall;
struct Variable;

struct Transformer
{
    virtual ~Transformer() {}
    virtual Expression *transformNumber(Number const *) = 0;
    virtual Expression *transformBinaryOperation(BinaryOperation const *) = 0;
    virtual Expression *transformFunctionCall(FunctionCall const *) = 0;
    virtual Expression *transformVariable(Variable const *) = 0;
};


#endif // TRANSFORMER_H
