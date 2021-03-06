#ifndef FOLDCONSTANTS_H
#define FOLDCONSTANTS_H

#include "transformer.h"

class FoldConstants : public Transformer
{
public:
    Expression *transformNumber(Number const *number);
    Expression *transformBinaryOperation(BinaryOperation const *binop);
    Expression *transformFunctionCall(FunctionCall const *fcall);
    Expression *transformVariable(Variable const *var);

    ~FoldConstants();
};

#endif // FOLDCONSTANTS_H
