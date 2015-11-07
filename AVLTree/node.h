#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int key);
    ~Node();
    Node * Insert(int key);
    Node * Find(int key);
    Node * Remove(int key);
    Node * RemoveAll();

private:
    unsigned char height();
    int bfactor();
    void fixheight();

    Node * left();
    Node * right();
    void setLeft(Node * node);
    void setRight(Node * node);

    Node * RotateRight();
    Node * RotateLeft();
    Node * Balance();
    Node * Findmin();
    Node * Removemin();

private:
    int key_;
    unsigned char height_;
    Node * left_;
    Node * right_;    
};

#endif // NODE_H
