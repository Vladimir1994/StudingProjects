#include "rational.h"
#include "math.h"

Rational::Rational(int numerator, int denominator) {
    numerator_ = numerator;
    denominator_ = denominator;
    this->reduce();
}

void Rational::add(Rational const & rational){
    numerator_ = rational.numerator_*denominator_ + rational.denominator_*numerator_;
    denominator_ *= rational.denominator_;
    this->reduce();
}

void Rational::sub(Rational const & rational){
    numerator_ =  rational.denominator_*numerator_ - rational.numerator_*denominator_;
    denominator_ *= rational.denominator_;
    this->reduce();
}

void Rational::mul(Rational const & rational){
    numerator_ *= rational.numerator_;
    denominator_ *= rational.denominator_;
    this->reduce();
}

void Rational::div(Rational const & rational){
    numerator_ *= rational.denominator_*(rational.numerator_/abs(rational.numerator_));
    denominator_ *= abs(rational.numerator_);
    this->reduce();
}

void Rational::reduce(){
    int nod = gcd(numerator_,  denominator_);
    numerator_ /= abs(nod);
    denominator_ /= abs(nod);
}

void Rational::neg(){
    numerator_ = - numerator_;
}
void Rational::inv(){
    int tmp = numerator_;
    int sign;
    tmp > 0 ? sign = 1 : sign = -1;
    numerator_ = sign * denominator_;
    denominator_ = abs(numerator_);
}
double Rational::to_double() const{
    return (double)numerator_ / (double)denominator_;
}

Rational & Rational::operator += (Rational const & r) {
    this->add(r);
    return *this;
}

Rational & Rational::operator -= (Rational const & r) {
    this->sub(r);
    return *this;
}

Rational & Rational::operator *= (Rational const & r) {
    this->mul(r);
    return *this;
}

Rational & Rational::operator /= (Rational const & r) {
    this->div(r);
    return *this;
}

Rational Rational::operator -() {
    Rational r = *this;
    r.neg();
    return r;
}

Rational Rational::operator +() {
    return *this;
}

Rational::operator double() const {
    return  this->to_double();
}

std::ostream & operator <<(std::ostream & out, Rational const & r) {
    out << r.numerator_ << '/' << r.denominator_;
    return out;
}

std::istream & operator >> (std::istream & in, Rational & r) {
    in >> r.numerator_ >> r.denominator_;
    return in;
}

int Rational::gcd (int const & a, int const & b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

Rational operator + (Rational const & r1, Rational const & r2) {
    Rational r = r1;
    r.add(r2);
    return r;
}

Rational operator - (Rational const & r1, Rational const & r2) {
    Rational r = r1;
    r.sub(r2);
    return r;
}

Rational operator * (Rational const & r1, Rational const & r2) {
    Rational r = r1;
    r.mul(r2);
    return r;
}

Rational operator / (Rational const & r1, Rational const & r2) {
    Rational r = r1;
    r.div(r2);
    return r;
}

bool operator == (Rational const & r1, Rational const & r2) {
    return r1.to_double() == r2.to_double();
}

bool operator != (Rational const & r1, Rational const & r2) {
    return !(r1 == r2);
}

bool operator < (Rational const & r1, Rational const & r2) {
    return r1.to_double() < r2.to_double();
}

bool operator <= (Rational const & r1, Rational const & r2) {
    return !(r2 < r1);
}

bool operator > (Rational const & r1, Rational const & r2) {
    return r2 < r1;
}

bool operator >= (Rational const & r1, Rational const & r2) {
    return !(r1 < r2);
}

