#include <iostream>
#include <conio.h>
#include "stack.h"

using namespace std;

int main() {
    Stack S;
    S.push(5);
    S.show();
    cout << endl;
    S.push(4);
    S.show();
    cout << endl;
    S.MaxToTop();
    S.show();
    cout << endl;
    int val = S.pop();
    cout << val << endl;
    S.show();
    cout << endl;
    _getch();
    return 0;
}

