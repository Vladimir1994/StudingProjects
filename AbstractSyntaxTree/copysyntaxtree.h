#ifndef COPYSYNTAXTREE_H
#define COPYSYNTAXTREE_H

#include "transformer.h"

class CopySyntaxTree : public Transformer
{
public:
    Expression *transformNumber(Number const *number);
    Expression *transformBinaryOperation(BinaryOperation const *binop);
    Expression *transformFunctionCall(FunctionCall const *fcall);
    Expression *transformVariable(Variable const *var);

    ~CopySyntaxTree();
};

#endif // COPYSYNTAXTREE_H
