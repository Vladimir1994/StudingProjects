#ifndef SCOPEDPTR_H
#define SCOPEDPTR_H

#include "expression.h"

class ScopedPtr
{
public:
    explicit ScopedPtr(Expression *ptr = 0);
    ~ScopedPtr();
    Expression * get() const;
    Expression * release();
    void reset(Expression *ptr = 0);
    Expression & operator*() const;
    Expression * operator->() const;

private:
    ScopedPtr(const ScopedPtr &);
    ScopedPtr & operator = (const ScopedPtr &);

    Expression *ptr_;
};

#endif // SCOPEDPTR_H
