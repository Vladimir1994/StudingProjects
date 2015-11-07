#include <iostream>
#include "avltree.h"

int main()
{
    AVLTree tree;
    std::cout << tree.insert(5);
    std::cout << tree.contains(5);
    std::cout << tree.remove(5);
    std::cout << tree.remove(3);
    std::cout << tree.contains(3);
    return 0;
}

