#include "avltree.h"
#include "node.h"

AVLTree::AVLTree(int firstKey) {
    root_ = new Node(firstKey);
}

AVLTree::~AVLTree() {
    delete root_;
}

bool AVLTree::contains(const int & key) const {
    if(root_->Find(key))
        return true;
    else
        return false;
}


bool AVLTree::insert(const int & key) {
    if(root_->Find(key))
        return false;
    else {
        root_->Insert(key);
        return true;
    }
}

bool AVLTree::remove(const int &key) {
    if(root_->Find(key)) {
        root_->Remove(key);
        return true;
    }
    else
        return false;
}

