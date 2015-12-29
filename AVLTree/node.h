#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int key);
    ~Node();
    Node * Insert(const int & key);
    Node * Find(const int & key);
    Node * Remove(const int & key);

private:
    unsigned char height();
    int bFactor();
    void FixHeight();

    Node * left();
    Node * right();
    void setLeft(Node * node);
    void setRight(Node * node);

    Node * RotateRight();
    Node * RotateLeft();
    Node * Balance();
    Node * FindMin();
    Node * RemoveMin();

private:
    int key_;
    unsigned char height_;
    Node * left_;
    Node * right_;    
};

#endif // NODE_H
