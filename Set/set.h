#include "item.h"
#include <cstdlib>
#include <iostream>
#include <algorithm>

#ifndef SET_H
#define	SET_H

class Set {   
public:
    Set();
    Set(Set const &);
    size_t size() const;
    bool Insert(int);
    bool Erase(int);
    bool Contains(int);
    void Union(Set const &);
    void Intersection(Set const &);
    void Complement(Set const &);
    Set &operator += (Set const &);
    Set &operator -= (Set const &);
    Set &operator *= (Set const &);
    Set& operator = (const Set &set);
    friend std::ostream & operator << (std::ostream &, Set const &);
    ~Set();

private:
    size_t size_;
    item * first_;
    item * last_;

private:
    void swap(Set & set);

};

Set operator + (Set const &, Set const &);
Set operator - (Set const &, Set const &);
Set operator * (Set const &, Set const &);

#endif	/* SET_H */

