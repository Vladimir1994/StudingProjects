#include <string> 
#include <cstdlib>
#include <iostream>
#include "binaryheap.h"

int main(){
    std::string cmd;
    Binary_Heap heap;
    int len;
    std::cin >> len;
    while(true) {
        std::cin >> cmd;
        if (cmd == "Insert") {
            int value;
            std::cin >> value;
            heap.insert(value);
        }
        else if (cmd == "Extract") {
            int value;
            value = heap.extract();
            std::cout << value << std::endl;
        }
        else if (cmd == "Show") {
            std::cout << heap << std::endl;
        }
        else if (cmd == "Esc") {
            break;
        }
        else {
            std::cout << "Wrong input";
        }
    }
    return 0;
}
