#ifndef SCOPE_H
#define SCOPE_H

#include <String>

struct Scope
{
    virtual ~Scope() { }
    virtual double variableValue(std::string const &name) const = 0;
};

#endif // SCOPE_H
