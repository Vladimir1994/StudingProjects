#include "polynomial.h"

Polynomial::Polynomial(const string & poly) {
    if(!poly.empty())
        ParsePoly(poly);
}

string Polynomial::getPoly() const {
    if(!polyMap_.empty())
        return PolyToString();
    else
        return "";
}

void Polynomial::setPoly(const string & poly) {
    polyMap_.clear();
    if(!poly.empty())
        ParsePoly(poly);
}

const Polynomial & Polynomial::operator = (const Polynomial & p) {
    polyMap_ = p.polyMap_;
    return * this;
}

Polynomial & Polynomial::operator += (const Polynomial & p) {
    for(auto element: p.polyMap_) {
        if(polyMap_.find(element.first) != polyMap_.end()) {
            if(polyMap_.find(element.first)->second + element.second == 0)
                polyMap_.erase(element.first);
            else
                polyMap_.find(element.first)->second += element.second ;
        }
        else
            polyMap_.insert(element);
    }
    return * this;
}

Polynomial & Polynomial::operator -= (const Polynomial & p) {
    for(auto element: p.polyMap_) {
        if(polyMap_.find(element.first) != polyMap_.end()) {
            if(polyMap_.find(element.first)->second - element.second == 0)
                polyMap_.erase(element.first);
            else
                polyMap_.find(element.first)->second -= element.second ;
        }
        else
            polyMap_.emplace(element.first, -element.second);
    }
    return * this;
}

Polynomial & Polynomial::operator *= (const Polynomial & p) {
    map<unsigned int, int> mult;
    for(auto elementOne: polyMap_) {
        for(auto elementTwo: p.polyMap_) {
            int power = elementOne.first + elementTwo.first;
            int coeff = elementOne.second * elementTwo.second;
            if(mult.find(power) != mult.end()) {
                if(mult.find(power)->second + coeff == 0)
                    mult.erase(power);
                else
                    mult.find(power)->second += coeff;
            }
            else
                mult.emplace(power, coeff);
        }
    }
    this->polyMap_ = mult;
    return * this;
}

Polynomial Polynomial::derivative() const {
    Polynomial polyMapDerivative;

    for(auto element: polyMap_) {
        if(element.first > 0)
            polyMapDerivative.polyMap_.emplace(element.first - 1,
                element.second * element.first);
    }

    return polyMapDerivative;
}

ostream & operator <<(ostream & out, Polynomial const & p) {
    out << p.getPoly();
    return out;
}

istream & operator >> (istream & in, Polynomial & p) {
    string ps;
    in >> ps;
    p.setPoly(ps);
    return in;
}

void Polynomial::ParsePoly(const string & polynomial) {
    if(polynomial.empty())
        return;

    size_t foundPrev = 0;
    list<string> polyList;

    for(;;) {
        size_t foundCur = polynomial.find_first_of("+-", foundPrev + 1);

        if(foundCur == string::npos) {
            polyList.push_back(polynomial.substr(foundPrev,
                polynomial.length() - foundCur));
            break;
        }

        string polynomialElement = polynomial.substr(foundPrev,
            foundCur - foundPrev);

        if(!polynomialElement.empty())
            polyList.push_back(polynomialElement);

        foundPrev = foundCur;
    }

    int polyElemCoeff;
    int unsigned polyElemPower;

    for(auto polyElement: polyList) {
        size_t xSymbolIdx = polyElement.find('x');
        if(xSymbolIdx == string::npos) {
            polyElemCoeff = atoi(polyElement.c_str());
            polyElemPower = 0;
        }
        else {
            if(xSymbolIdx == 1 && polyElement[0] == '-') {
                polyElemCoeff = -1;
            }
            else if(xSymbolIdx == 0) {
                polyElemCoeff = 1;
            }
            else if(xSymbolIdx == 1 && polyElement[0] == '+') {
                polyElemCoeff = 1;
            }
            else {
                polyElemCoeff = atoi(polyElement.substr(0,
                    xSymbolIdx).c_str());
            }
            size_t powerSymbolIdx = polyElement.find('^');
            if(powerSymbolIdx == string::npos) {
                polyElemPower = 1;
            }
            else {
                polyElemPower = atoi(polyElement.substr(powerSymbolIdx + 1,
                    polyElement.length() - powerSymbolIdx).c_str());
            }
        }

        auto polyMap_Iter = polyMap_.find(polyElemPower);
        if(polyMap_Iter != polyMap_.end()) {
            polyMap_Iter->second += polyElemCoeff;
        }
        else {
            polyMap_.emplace(polyElemPower, polyElemCoeff);
        }
    }

    for(auto iter = polyMap_.begin(); iter != polyMap_.end()--; ++iter) {
        if(iter->second == 0) {
            polyMap_.erase(iter);
        }
    }
}

string Polynomial::PolyToString() const {
    string polynomial = "";

    for(auto iter = polyMap_.rbegin(); iter != polyMap_.rend()--; ++iter) {
        string polyElement;

        if(iter->first == 0) {
            string plus = "";
            if(iter->second > 0)
                plus = "+";
            polyElement = plus + to_string(iter->second);
        }
        else if(iter->first == 1) {
            polyElement = "x";
        }
        else if(iter->first > 1) {
            polyElement = "x^" + to_string(iter->first);
        }

        if(iter->first != 0) {
            if(iter->second == 1) {
                polyElement = "+" + polyElement;
            }
            else if(iter->second == -1) {
                polyElement = "-" + polyElement;
            }
            else  {
                string plus = "";
                if(iter->second > 0)
                    plus = "+";
                polyElement = plus + to_string(iter->second) + "*" + polyElement;;
            }
        }
        polynomial += polyElement;
    }

    if(polynomial[0] == '+')
        polynomial = polynomial.substr(1, polynomial.length() - 1);

    return polynomial;
}

Polynomial operator + (Polynomial const & p1, Polynomial const & p2) {
    Polynomial p = p1;
    p += p2;
    return p;
}

Polynomial operator - (Polynomial const & p1, Polynomial const & p2) {
    Polynomial p = p1;
    p -= p2;
    return p;
}

Polynomial operator * (Polynomial const & p1, Polynomial const & p2) {
    Polynomial p = p1;
    p *= p2;
    return p;
}
