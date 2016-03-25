#include "storage.h"

Storage::Storage(Expression *ptr): ptr_(ptr)
{
    if (ptr != 0)
        counter_ = 1;
    else
        counter_ = 0;
}

Storage::~Storage()
{
    if (ptr_ != 0)
        delete ptr_;
}

void Storage::inc()
{
    counter_++;
}

void Storage::dec()
{
    counter_--;
}

int Storage::count()
{
    return counter_;
}

Expression* Storage::get() const
{
   return ptr_;
}
