#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

struct Rational{
    Rational(int numerator = 0, int denominator = 1);

    void add(Rational const & rational);
    void sub(Rational const & rational);
    void mul(Rational const & rational);
    void div(Rational const & rational);

    void reduce();

    void neg();
    void inv();
    double to_double() const;

    Rational & operator += (Rational const & r);
    Rational & operator -= (Rational const & r);
    Rational & operator *= (Rational const & r);
    Rational & operator /= (Rational const & r);
    Rational operator -();
    Rational operator +();

    operator double() const;

    friend std::ostream & operator << (std::ostream &, Rational const &);
    friend std::istream& operator >> (std::istream &, Rational &);

private:
    int gcd (int const & a, int const & b);

private:
    int numerator_;
    unsigned denominator_;
};

Rational operator + (Rational const & r1, Rational const & r2);

Rational operator - (Rational const & r1, Rational const & r2);

Rational operator * (Rational const & r1, Rational const & r2);

Rational operator / (Rational const & r1, Rational const & r2);

bool operator == (Rational const & r1, Rational const & r2);

bool operator != (Rational const & r1, Rational const & r2);

bool operator < (Rational const & r1, Rational const & r2);

bool operator <= (Rational const & r1, Rational const & r2);

bool operator > (Rational const & r1, Rational const & r2);

bool operator >= (Rational const & r1, Rational const & r2);

#endif // RATIONAL_H
