#ifndef SET_H
#define	SET_H

#include "item.h"

#include <algorithm>

#include <cstdlib>
#include <iostream>

class Set
{
public:
    Set();
    Set(Set const &set);
    ~Set();

    size_t size() const;

    bool insert(int value);
    bool erase(int value);
    bool contains(int value);
    void merge(Set const &set);
    void intersection(Set const &set);
    void complement(Set const &set);

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

Set operator+(Set const &setFirst, Set const &setSecond);
Set operator-(Set const &setFirst, Set const &setSecond);
Set operator*(Set const &setFirst, Set const &setSecond);

#endif	/* SET_H */

