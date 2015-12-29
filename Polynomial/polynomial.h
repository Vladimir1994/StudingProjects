#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cstdlib>
#include <map>
#include <list>
#include <string>

using namespace std;

class Polynomial
{
public:
    Polynomial(const string & poly = "");
    string getPoly() const;
    void setPoly(const string & poly);

    const Polynomial & operator = (const Polynomial & p);
    Polynomial & operator += (const Polynomial & p);
    Polynomial & operator -= (const Polynomial & p);
    Polynomial & operator *= (const Polynomial & p);

    Polynomial derivative() const;

    friend ostream & operator << (ostream &, Polynomial const & p);
    friend istream & operator >> (istream &, Polynomial & p);

private:
    map<unsigned int, int> polyMap_;

private:
    void ParsePoly(const string & polynomial);
    string PolyToString() const;
};

Polynomial operator + (Polynomial const & p1, Polynomial const & p2);

Polynomial operator - (Polynomial const & p1, Polynomial const & p2);

Polynomial operator * (Polynomial const & p1, Polynomial const & p2);

#endif // POLYNOMIAL_H
