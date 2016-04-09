#ifndef Complex_H
#define	Complex_H

#include<iostream>

class Complex
{
public:
    Complex(double my_real = 0, double my_img = 0);

    const Complex & operator=(const Complex &c);
    Complex & operator+=(const Complex &c);
    Complex & operator-=(const Complex &c);
    Complex & operator*=(const Complex &c);
    Complex & operator/=(const Complex &c);
    Complex operator^(double n);

    friend std::ostream & operator << (std::ostream &out, const Complex &c);
    friend std::istream & operator >> (std::istream &out, Complex &c);

    double abs() const;
    double arg() const;

private:
    double real;
    double img;
};

Complex operator+(const Complex &c1, const Complex &c2);

Complex operator-(const Complex &c1, const Complex &c2);

Complex operator*(const Complex &c1, const Complex &c2);

Complex operator/(const Complex &c1, const Complex &c2);

#endif	/* Complex_H */

