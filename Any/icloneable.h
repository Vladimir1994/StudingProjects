#ifndef ICLONABLE_H
#define ICLONABLE_H

struct ICloneable
{
    virtual ICloneable * clone() const = 0;
    virtual ~ICloneable() {}
};

#endif // ICLONABLE_H
