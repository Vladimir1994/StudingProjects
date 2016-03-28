#include "binaryoperation.h"
#include <cassert>
#include "transformer.h"

BinaryOperation::BinaryOperation(Expression const *left, int op, Expression const *right)
    : left_(left), right_(right), op_(op)
{
    assert(left_ && right_);
}

BinaryOperation::~BinaryOperation()
{
    delete left_;
    delete right_;
}

Expression const * BinaryOperation::left() const
{
    return left_;
}

Expression const * BinaryOperation::right() const
{
    return right_;
}

int BinaryOperation::operation() const
{
    return op_;
}

double BinaryOperation::evaluate(Scope *sc) const
{
    double left = left_->evaluate(sc);
    double right = right_->evaluate(sc);
    switch (op_) {
        case PLUS: return left + right;
        case MINUS: return left - right;
        case DIV: return left / right;
        case MUL: return left * right;
    }
    assert(0);
    return 0.0;
}

Expression * BinaryOperation::transform(Transformer *tr) const
{
    return tr->transformBinaryOperation(this);
}
