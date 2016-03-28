#ifndef SCOPE_H
#define SCOPE_H

#include <string>

class Scope
{
public:
    virtual ~Scope() {}
    virtual double variableValue(std::string const &name) const = 0;
};

#endif // SCOPE_H
