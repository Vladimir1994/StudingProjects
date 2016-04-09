#include "node.h"

Node::Node(int key) :
    key_(key), height_(0), left_(0), right_(0)
{}

Node::~Node()
{
    if (right_)
        delete right_;
    if (left_)
        delete left_;
}

Node * Node::insert(int key)
{
    if (!this)
        return new Node(key);
    if (key < key_)
        left_ = left_->insert(key);
    else
        right_ = right_->insert(key);
    return this->balance();
}

const Node * Node::find(int key) const
{
    if (!this)
        return 0;

    if (key < key_)
        return left_->find(key);
    else if (key > key_)
        return right_->find(key);
    else
        return this;
}

Node * Node::remove(int key)
{
    if (!this)
        return 0;

    if (key < key_) {
        left_ = left_->remove(key);
    }
    else if (key > key_) {
        right_ = right_->remove(key);
    }
    else {
        Node *q = left_;
        Node *r = right_;
        delete this;
        if (!r)
            return q;
        Node *min = r->findMin();
        min->setRight(r->removeMin());
        min->setLeft(q);
        return min->balance();
    }
    return this->balance();
}

unsigned char Node::height()
{
    return this ? this->height_ : 0;
}

int Node::bFactor()
{
    return this->right()->height() - this->left()->height();
}

void Node::fixHeight()
{
    unsigned char heighttLeft = this->left()->height();
    unsigned char heightRight = this->right()->height();
    this->height_ = (heighttLeft > heightRight
                     ? heighttLeft : heightRight) + 1;
}

Node * Node::left()
{
    return left_;
}

Node * Node::right()
{
    return right_;
}

void Node::setLeft(Node *node)
{
    left_ = node;
}

void Node::setRight(Node *node)
{
    right_ = node;
}

Node * Node::rotateRight()
{
    Node *q = left_;
    left_ = q->right();
    q->setRight(this);
    this->fixHeight();
    q->fixHeight();
    return q;
}

Node * Node::rotateLeft()
{
    Node *p = right_;
    right_ = p->left();
    p->setLeft(this);
    this->fixHeight();
    p->fixHeight();
    return p;
}

Node * Node::balance()
{
    this->fixHeight();
    if (this->bFactor() == 2) {
        if (right_->bFactor() < 0)
            right_->rotateRight();
        return this->rotateLeft();
    }
    if (this->bFactor() == -2) {
        if (left_->bFactor() > 0)
            left_->rotateLeft();
        return this->rotateRight();
    }
    return this;
}

Node * Node::findMin()
{
    return left_ ? left_->findMin() : this;
}

Node * Node::removeMin()
{
    if (left_ == 0)
        return right_;
    left_ = left_->removeMin();
    return this->balance();
}
