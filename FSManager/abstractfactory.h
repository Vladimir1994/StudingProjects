#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

class Command;

class AbstractFactory
{
public:
    virtual Command * create() const = 0;
    virtual ~AbstractFactory() {}
};

#endif // ABSTRACTFACTORY_H
