#include "avltree.h"
#include "node.h"

AVLTree::AVLTree(int firstKey) {
    root_ = new Node(firstKey);
}

AVLTree::~AVLTree() {
    delete root_;
}

bool AVLTree::contains(int key) const {
    if(root_->find(key))
        return true;
    else
        return false;
}

bool AVLTree::insert(int key) {
    if(root_->find(key))
        return false;
    else {
        root_->insert(key);
        return true;
    }
}

bool AVLTree::remove(int key) {
    if(root_->find(key)) {
        root_->remove(key);
        return true;
    }
    else
        return false;
}

