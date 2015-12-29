#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include "expression.h"
#include "storage.h"

struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0);
    ~SharedPtr();
    SharedPtr(const SharedPtr & ptr);

    Expression* get() const;
    void reset(Expression *ptr = 0);

    SharedPtr& operator = (const SharedPtr & ptr);
    Expression& operator*() const;
    Expression* operator->() const;

private:
    Storage *st_;

private:
    void swap(SharedPtr & ptr);
};

#endif // SHAREDPTR_H
