#ifndef FACTORY_H
#define FACTORY_H

#include "abstractfactory.h"

template <typename T>
class Factory : public AbstractFactory
{
public:
    virtual Command * create() const { return new T(); }
};

#endif // FACTORY_H
