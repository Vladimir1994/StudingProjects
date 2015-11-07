#include "foldconstants.h"
#include "expression.h"
#include "variable.h"
#include "number.h"
#include "binaryoperation.h"
#include "functioncall.h"

Expression * FoldConstants::transformNumber(Number const *number)
{
    return new Number(number->value());
}

Expression * FoldConstants::transformBinaryOperation(BinaryOperation const *binop)
{
    Scope *sc;
    Expression * p_l  =  binop->left()->transform(this);
    Expression * p_r  =  binop->right()->transform(this);
    int op = binop->operation();
    Expression * expression = new BinaryOperation(p_l, op, p_r);

    Number *p_l_1  =  dynamic_cast<Number*>(p_l);
    Number *p_r_1  =  dynamic_cast<Number*>(p_r);

    if((p_l_1) && (p_r_1))
    {
        Expression * f = new Number(expression->evaluate(sc));
        delete expression;
        return f;
    }
    return expression;
}

Expression * FoldConstants::transformFunctionCall(FunctionCall const *fcall)
{
    Scope *sc;
    Expression const * p = fcall->arg()->transform(this);
    if (dynamic_cast<const Number*>(p))
    {
        delete p;
        return new Number(fcall->evaluate(sc));
    }
    else
    {
        delete p;
        return new FunctionCall(fcall->name(), fcall->arg()->transform(this));
    }
}

Expression * FoldConstants::transformVariable(Variable const *var)
{
    return new Variable(var->name());
}

FoldConstants::~FoldConstants(){}
