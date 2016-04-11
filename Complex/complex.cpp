#include "Complex.h"

#include <math.h>
#include <iostream>
#include <fstream>

using namespace std;

Complex::Complex(double my_real, double my_img) :
    real(my_real), img(my_img)
{}

const Complex & Complex::operator=(const Complex &c)
{
    real = c.real;
    img = c.img;
    return *this;
}

Complex & Complex::operator+=(const Complex &c)
{
    real = real + c.real;
    img = img + c.img;
    return *this;
}

Complex & Complex::operator-=(const Complex &c)
{
    real = real - c.real;
    img = img - c.img;
    return *this;
}

Complex & Complex::operator*=(const Complex &c)
{
    real = real * c.real - img * c.img;
    img = real * c.img + img * c.real;
    return *this;
}

Complex & Complex::operator/=(const Complex &c)
{
    real = (real * c.real + img * c.img)
            / (c.img * c.img + c.real * c.real);
    img = (img * c.real - real * c.img)
            / (c.img * c.img + c.real * c.real);
    return *this;
}

std::ostream & operator<<(std::ostream &out, const Complex &c)
{
    out << c.real << " + i*" << c.img;
    return out;
}

std::istream & operator>>(std::istream &in, Complex &c)
{
    in >> c.real >> c.img;
    return in;
}

Complex Complex::operator^(double n)
{
    Complex tmp;
    double abs = this->abs();
    double arg = this->arg();
    abs = pow(abs, n);
    arg = n * arg;
    tmp.real = abs * cos(arg);
    tmp.img = abs * sin(arg);
    return tmp;
}

double Complex::abs() const
{
    double abs = sqrt(real * real + img * img);
    return abs;
}

double Complex::arg() const
{
    double arg = atan(img / real);
    return arg;
}

Complex operator+(const Complex &c2, const Complex &c1)
{
    Complex c = c1;
    c += c2;
    return c;
}

Complex operator-(const Complex &c1, const Complex &c2)
{
    Complex c = c1;
    c -= c2;
    return c;
}

Complex operator*(const Complex &c1, const Complex &c2)
{
    Complex c = c1;
    c *= c2;
    return c;
}

Complex operator/(const Complex &c1, const Complex &c2)
{
    Complex c = c1;
    c /= c2;
    return c;
}
