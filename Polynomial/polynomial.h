#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <map>
#include <list>

#include <string>
#include <exception>
#include <cstdlib>

using namespace std;

class WrongFormatException : public exception {};

class Polynomial
{
public:
    Polynomial(const string &poly = "", const string &varSymbol = "x");
    string getPoly() const;
    void setPoly(const string &poly);

    const Polynomial & operator=(const Polynomial &p);
    Polynomial & operator+=(const Polynomial &p);
    Polynomial & operator-=(const Polynomial &p);
    Polynomial & operator*=(const Polynomial &p);

    Polynomial derivative() const;

    friend ostream & operator<<(ostream &out, Polynomial const &p);
    friend istream & operator>>(istream &in, Polynomial &p);

private:
    map<unsigned int, int> polyMap_;
    string varSymbol_;

private:
    void ParsePoly(const string &polynomial);
    string PolyToString() const;
    bool isStringPolyElement(const string &ps);

};

Polynomial operator+(Polynomial const &p1, Polynomial const &p2);

Polynomial operator-(Polynomial const &p1, Polynomial const &p2);

Polynomial operator*(Polynomial const &p1, Polynomial const &p2);

#endif // POLYNOMIAL_H
