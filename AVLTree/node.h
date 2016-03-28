#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int key);
    ~Node();
    Node * Insert(int key);
    const Node * Find(int key) const;
    Node * Remove(int key);

private:
    int key_;
    unsigned char height_;
    Node *left_;
    Node *right_;

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
};

#endif // NODE_H
