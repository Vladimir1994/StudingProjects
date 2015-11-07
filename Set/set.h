#include "item.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

#ifndef SET_H
#define	SET_H

class Set {
    size_t size_;
    item *first_;
    item *last_;
    void swap(Set & set);
public:
    Set();
    Set(Set const &);
    size_t size() const;
    bool Insert(const int &);
    bool Erase(const int &);
    bool Contains(const int &);
    void Union(Set const &);
    void Intersection(Set const &);
    void Complement(Set const &);
    Set &operator += (Set const &);
    Set &operator -= (Set const &);
    Set &operator *= (Set const &);
    Set& operator = (const Set &set);
    friend std::ostream & operator << (std::ostream &, Set const &);
    ~Set();
};

Set operator + (Set const &, Set const &);
Set operator - (Set const &, Set const &);
Set operator * (Set const &, Set const &);

#endif	/* SET_H */

