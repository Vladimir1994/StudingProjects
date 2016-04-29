#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

struct Rational{
    Rational(int numerator = 0, int denominator = 1);

    void add(const Rational &r);
    void sub(const Rational &r);
    void mul(const Rational &r);
    void div(const Rational &r);

    void reduce();

    void neg();
    void inv();
    double to_double() const;

    Rational &operator+=(const Rational &r);
    Rational &operator-=(const Rational &r);
    Rational &operator*=(const Rational &r);
    Rational &operator/=(const Rational &r);
    Rational operator-();
    Rational operator+();

    operator double() const;

    friend std::ostream &operator << (std::ostream &out, const Rational &r);
    friend std::istream &operator >> (std::istream &in, Rational &r);

private:
    int gcd (int a, int b);

private:
    int numerator_;
    unsigned denominator_;
};

Rational operator+(const Rational &r1, const Rational &r2);

Rational operator-(const Rational &r1, const Rational &r2);

Rational operator*(const Rational &r1, const Rational &r2);

Rational operator/(const Rational &r1, const Rational &r2);

bool operator==(const Rational &r1, const Rational &r2);

bool operator!=(const Rational &r1, const Rational &r2);

bool operator<(const Rational &r1, const Rational &r2);

bool operator<=(const Rational &r1, const Rational &r2);

bool operator>(const Rational &r1, const Rational &r2);

bool operator>=(const Rational &r1, const Rational &r2);

#endif // RATIONAL_H
