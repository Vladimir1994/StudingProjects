#include "copysyntaxtree.h"
#include "expression.h"
#include "variable.h"
#include "number.h"
#include "binaryoperation.h"
#include "functioncall.h"

#include <string>

Expression * CopySyntaxTree::transformNumber(Number const *number)
{
    Expression *number_ = new Number(number->value());
    return number_;
}

Expression * CopySyntaxTree::transformBinaryOperation(BinaryOperation const *binop){
    int op = binop->operation();
    Expression const *  expression_l = binop->left()->transform(this);
    Expression const *  expression_r = binop->right()->transform(this);
    Expression *binop_ = new BinaryOperation(expression_l, op, expression_r);
    return binop_;
}

Expression * CopySyntaxTree::transformFunctionCall(FunctionCall const *fcall)
{
    std::string name = fcall->name();
    Expression const *  expression = fcall->arg()->transform(this);
    Expression *fcall_m = new FunctionCall(name, expression);
    return fcall_m;
}

Expression * CopySyntaxTree::transformVariable(Variable const *var)
{
    Expression *var_ = new Variable(var->name());
    return var_;
}
CopySyntaxTree::~CopySyntaxTree() {}
