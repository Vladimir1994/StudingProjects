#include "node.h"

Node::Node(int key) :  key_(key), height_(0), left_(0), right_(0) {}

Node::~Node() {
    if(right_)
        delete right_;
    if(left_)
        delete left_;
}

unsigned char Node::height() {
    return this ? this->height_ : 0;
}

int Node::bfactor() {
    return this->right()->height() - this->left()->height();
}

void Node::fixheight() {
    unsigned char heighttLeft = this->left()->height();
    unsigned char heightRight = this->right()->height();
    this->height_ = (heighttLeft > heightRight ? heighttLeft : heightRight) + 1;
}

Node * Node::left() {
    return left_;
}

Node * Node::right() {
    return right_;
}

void Node::setLeft(Node * node) {
    left_ = node;
}

void Node::setRight(Node * node) {
    right_ = node;
}

Node * Node::RotateRight() {
    Node * q = left_;
    left_ = q->right();
    q->setRight(this);
    this->fixheight();
    q->fixheight();
    return q;
}

Node * Node::RotateLeft() {
    Node * p = right_;
    right_ = p->left();
    p->setLeft(this);
    this->fixheight();
    p->fixheight();
    return p;
}

Node * Node::Balance() {
    this->fixheight();
    if(this->bfactor() == 2) {
        if(right_->bfactor() < 0)
            right_->RotateRight();
        return this->RotateLeft();
    }
    if(this->bfactor() == -2) {
        if(left_->bfactor() > 0)
            left_->RotateLeft();
        return this->RotateRight();
    }
    return this;
}

Node * Node::Findmin() {
    return left_ ? left_->Findmin() : this;
}

Node * Node::Removemin() {
    if(left_ == 0)
        return right_;
    left_ = left_->Removemin();
    return this->Balance();
}

Node * Node::Insert(int key) {
    if(!this)
        return new Node(key);
    if(key < key_)
        left_ = left_->Insert(key);
    else
        right_ = right_->Insert(key);
    return this->Balance();
}

Node * Node::Find(int key) {
    if(!this) return 0;

    if(key < key_)
        return left_->Find(key);
    else if(key > key_)
        return right_->Find(key);
    else
        return this;
}

Node * Node::Remove(int key) {
    if(!this) return 0;
    if(key < key_)
        left_ = left_->Remove(key);
    else if(key > key_)
        right_ = right_->Remove(key);
    else {
        Node * q = left_;
        Node * r = right_;
        delete this;
        if(!r)
            return q;
        Node * min = r->Findmin();
        min->setRight(r->Removemin());
        min->setLeft(q);
        return min->Balance();
    }
    return this->Balance();
}
