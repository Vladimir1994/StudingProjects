#include "rational.h"

#include <math.h>

Rational::Rational(int numerator, int denominator)
{
    numerator_ = numerator;
    denominator_ = denominator;
    this->reduce();
}

void Rational::add(const Rational &r)
{
    numerator_ = r.numerator_ * denominator_
        + r.denominator_ * numerator_;
    denominator_ *= r.denominator_;
    this->reduce();
}

void Rational::sub(const Rational &r)
{
    numerator_ =  r.denominator_*numerator_
        - r.numerator_ * denominator_;
    denominator_ *= r.denominator_;
    this->reduce();
}

void Rational::mul(const Rational &r)
{
    numerator_ *= r.numerator_;
    denominator_ *= r.denominator_;
    this->reduce();
}

void Rational::div(const Rational &r)
{
    numerator_ *= r.denominator_ *
        (r.numerator_ / abs(r.numerator_));
    denominator_ *= abs(r.numerator_);
    this->reduce();
}

void Rational::reduce()
{
    int nod = gcd(numerator_, denominator_);
    numerator_ /= abs(nod);
    denominator_ /= abs(nod);
}

void Rational::neg()
{
    numerator_ = -numerator_;
}

void Rational::inv()
{
    int tmp = numerator_;
    int sign;
    tmp > 0 ? sign = 1 : sign = -1;
    numerator_ = sign * denominator_;
    denominator_ = abs(numerator_);
}

double Rational::to_double() const
{
    return (double)numerator_ / (double)denominator_;
}

Rational &Rational::operator+=(const Rational &r)
{
    this->add(r);
    return *this;
}

Rational &Rational::operator-=(const Rational &r)
{
    this->sub(r);
    return *this;
}

Rational &Rational::operator*=(const Rational &r)
{
    this->mul(r);
    return *this;
}

Rational &Rational::operator/=(const Rational &r)
{
    this->div(r);
    return *this;
}

Rational Rational::operator-()
{
    Rational r = *this;
    r.neg();
    return r;
}

Rational Rational::operator+()
{
    return *this;
}

Rational::operator double() const
{
    return this->to_double();
}

std::ostream &operator<<(std::ostream &out, const Rational &r)
{
    out << r.numerator_ << '/' << r.denominator_;
    return out;
}

std::istream &operator>>(std::istream &in, Rational &r)
{
    in >> r.numerator_ >> r.denominator_;
    return in;
}

int Rational::gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

Rational operator+(const Rational &r1, const Rational &r2)
{
    Rational r = r1;
    r.add(r2);
    return r;
}

Rational operator-(const Rational &r1, const Rational &r2)
{
    Rational r = r1;
    r.sub(r2);
    return r;
}

Rational operator*(const Rational &r1, const Rational &r2)
{
    Rational r = r1;
    r.mul(r2);
    return r;
}

Rational operator/(const Rational &r1, const Rational &r2)
{
    Rational r = r1;
    r.div(r2);
    return r;
}

bool operator==(const Rational &r1, const Rational &r2)
{
    return r1.to_double() == r2.to_double();
}

bool operator!=(const Rational &r1, const Rational &r2)
{
    return !(r1 == r2);
}

bool operator<(const Rational &r1, const Rational &r2)
{
    return r1.to_double() < r2.to_double();
}

bool operator<=(const Rational &r1, const Rational &r2)
{
    return !(r2 < r1);
}

bool operator>(const Rational &r1, const Rational &r2)
{
    return r2 < r1;
}

bool operator>=(const Rational &r1, const Rational &r2)
{
    return !(r1 < r2);
}

