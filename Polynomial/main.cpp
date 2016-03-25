#include "polynomial.h"

#include <iostream>

using namespace std;

int main()
{  
    try {
        cout << "Enter first poly." << endl;
        string ps;
        Polynomial p1;
        cin >> ps;
        p1.setPoly(ps);
        cout << "Enter second poly." << endl;
        Polynomial p2;
        cin >> ps;
        p2.setPoly(ps);
        cout << "Sum: " + (p1 + p2).getPoly() << endl;

    }
    catch(WrongFormatException &e) {
        cout << "Wrong format." << endl;
        return -1;
    }

    return 0;
}

