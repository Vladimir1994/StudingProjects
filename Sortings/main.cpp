#include <iostream>
#include <vector>

#include "sortings.h"

using namespace std;

int main()
{
    vector<int> v_1 = {11, 2, 11, 3, 10};
    vector<int> v_2 = {11, 2, 11, 3, 10};
    vector<int> v_3 = {11, 2, 11, 3, 10};

    heapsort(v_1, 0, 4);
    mergesort(v_2, 0, 4);
    qsort(v_3, 0, 4);

    for(unsigned int i = 0; i < v_1.size(); i++) {
        cout << v_1[i] << " ";
    }

    cout << endl;

    for(unsigned int i = 0; i < v_2.size(); i++) {
        cout << v_2[i] << " ";
    }

    cout << endl;

    for(unsigned int i = 0; i < v_3.size(); i++) {
        cout << v_3[i] << " ";
    }

    cout << endl;

    return 0;
}
