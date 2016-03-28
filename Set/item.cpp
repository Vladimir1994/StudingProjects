#include "item.h"

item::item(int value, item *previous, item *next) :
    value_(value), previous_(previous), next_(next)
{}

int item::getValue() const
{
    return value_;
}

item * item::getPrevious() const
{
    return previous_;
}

item * item::getNext() const
{
    return next_;
}

void item::setPrevious(item *previous)
{
    previous_ = previous;
}

void item::setNext(item *next)
{
    next_ = next;
}
