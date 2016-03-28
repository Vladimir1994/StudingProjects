#include "item.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

#ifndef SET_H
#define	SET_H

class Set
{
public:
    Set();
    Set(Set const &set);
    ~Set();

    size_t size() const;

    bool Insert(int value);
    bool Erase(int value);
    bool Contains(int value);
    void Union(Set const &set);
    void Intersection(Set const &set);
    void Complement(Set const &set);

    Set &operator+=(Set const &set);
    Set &operator-=(Set const &set);
    Set &operator*=(Set const &set);
    Set &operator=(const Set &set);

    friend std::ostream & operator<<(std::ostream &out, Set const &set);

private:
    size_t size_;
    item *first_;
    item *last_;

private:
    void swap(Set &set);
};

Set operator + (Set const &setFirst, Set const &setSecond);
Set operator - (Set const &setFirst, Set const &setSecond);
Set operator * (Set const &setFirst, Set const &setSecond);

#endif	/* SET_H */

