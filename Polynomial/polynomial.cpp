#include "polynomial.h"
#include "string.h"
#include "cstdlib"

Polynomial::Polynomial(const string & poly, const string & varSymbol)
    throw(WrongFormatException): varSymbol_(varSymbol) {
    if(!poly.empty())
        ParsePoly(poly);
}

string Polynomial::getPoly() const {
    if(!polyMap_.empty())
        return PolyToString();
    else
        return "0";
}

void Polynomial::setPoly(const string & poly) throw(WrongFormatException) {
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

void Polynomial::ParsePoly(const string & polynomial) throw(WrongFormatException) {
    if(polynomial.empty())
        return;

    size_t foundPrev = 0;
    list<string> polyList;

    for(;;) {
        size_t foundCur = polynomial.find_first_of("+-", foundPrev + 1);

        string polynomialElement = "";

        if(foundCur == string::npos) {
            polynomialElement = polynomial.substr(foundPrev,
                polynomial.length() - foundCur);
            if(!polynomialElement.empty() && isStringPolyElement(polynomialElement)) {
                polyList.push_back(polynomialElement);
                break;
            }
            else
                throw WrongFormatException();
        }

        polynomialElement = polynomial.substr(foundPrev,
            foundCur - foundPrev);

        if(!polynomialElement.empty() && isStringPolyElement(polynomialElement))
            polyList.push_back(polynomialElement);
        else
            throw WrongFormatException();

        foundPrev = foundCur;
    }

    int polyElemCoeff;
    int unsigned polyElemPower;

    for(auto polyElement: polyList) {
        size_t varSymbolIdx = polyElement.find(varSymbol_.c_str());
        if(varSymbolIdx == string::npos) {
            polyElemCoeff = atoi(polyElement.c_str());
            polyElemPower = 0;
        }
        else {
            if(varSymbolIdx == 1 && polyElement[0] == '-') {
                polyElemCoeff = -1;
            }
            else if(varSymbolIdx == 0) {
                polyElemCoeff = 1;
            }
            else if(varSymbolIdx == 1 && polyElement[0] == '+') {
                polyElemCoeff = 1;
            }
            else {
                polyElemCoeff = atoi(polyElement.substr(0,
                    varSymbolIdx).c_str());
            }

            if(varSymbolIdx == polyElement.length() - 1) {
                polyElemPower = 1;
            }
            else {
                size_t powerSymbolIdx = 0;
                if(polyElement.at(varSymbolIdx + 1) == '^')
                    powerSymbolIdx = varSymbolIdx + 2;
                else
                    powerSymbolIdx = varSymbolIdx + 1;

                polyElemPower = atoi(polyElement.substr(powerSymbolIdx,
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
            polyElement = varSymbol_;
        }
        else if(iter->first > 1) {
            polyElement = varSymbol_ + "^" + to_string(iter->first);
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

bool Polynomial::isStringPolyElement(const string & ps) {
    unsigned int varSympolIdx = ps.find(varSymbol_);
    if(varSympolIdx == string::npos) {
        for(size_t i = 0; i < ps.length(); i++) {
            if(i == 0 && (ps[i] == '+' || ps[i] == '-' || isdigit(ps[i])))
                continue;
            else if(i != ps.length() - 1 && i != 0 && isdigit(ps[i]))
                continue;
            else if(i == ps.length() - 1 && (ps[i] == '*' || isdigit(ps[i])))
                continue;
            else
                return false;
        }
    }
    else {
        string coeffStr = ps.substr(0, varSympolIdx);
        string powerStr = ps.substr(varSympolIdx + varSymbol_.length(),
            ps.length() - varSympolIdx - varSymbol_.length());

        for(size_t i = 0; i < coeffStr.length(); i++) {
            if(i == 0 && (coeffStr[i] == '+' || coeffStr[i] == '-' || isdigit(coeffStr[i])))
                continue;
            else if(i != coeffStr.length() - 1 && i != 0 && isdigit(coeffStr[i]))
                continue;
            else if(i == coeffStr.length() - 1 && (coeffStr[i] == '*' || isdigit(coeffStr[i])))
                continue;
            else
                return false;
        }
        for(size_t i = 0; i < powerStr.length(); i++) {
            if(i == 0 && (powerStr[i] == '^' || isdigit(powerStr[i])))
                continue;
            else if(i != 0 && isdigit(powerStr[i]))
                continue;
            else
                return false;
        }
    }
    return true;
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
