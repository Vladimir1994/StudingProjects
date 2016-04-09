#ifndef NODE_H
#define NODE_H

class Node
{
public:
    Node(int key);
    ~Node();
    Node * insert(int key);
    const Node * find(int key) const;
    Node * remove(int key);

private:
    int key_;
    unsigned char height_;
    Node *left_;
    Node *right_;

private:
    unsigned char height();
    int bFactor();
    void fixHeight();

    Node * left();
    Node * right();
    void setLeft(Node *node);
    void setRight(Node *node);

    Node * rotateRight();
    Node * rotateLeft();
    Node * balance();
    Node * findMin();
    Node * removeMin();
};

#endif // NODE_H
