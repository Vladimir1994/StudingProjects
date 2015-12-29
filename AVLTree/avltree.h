#ifndef AVLTREE_H
#define AVLTREE_H

struct Node;

class AVLTree
{
public:
    AVLTree(int firstKey = 0);
    ~AVLTree();

    bool contains(const int & key) const;
    bool remove(const int & key);
    bool insert(const int & key);

private:
    Node * root_;
};

#endif // AVLTREE_H
