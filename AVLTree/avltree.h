#ifndef AVLTREE_H
#define AVLTREE_H

struct Node;

class AVLTree
{
public:
    AVLTree(int firstKey = 0);
    ~AVLTree();
    bool contains(int key);
    bool remove(int key);
    bool insert(int key);

private:
    Node * root_;
};

#endif // AVLTREE_H
