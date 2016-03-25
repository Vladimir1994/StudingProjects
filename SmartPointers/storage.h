#ifndef STORAGE
#define STORAGE

#include "expression.h"

class Storage
{
public:
    Storage(Expression *ptr);
    ~Storage();
    void inc();
    void dec();
    int count();
    Expression * get() const;

private:
    int counter_;
    Expression *ptr_;
};

#endif // STORAGE

