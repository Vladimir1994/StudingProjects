#include "avltree.h"
#include "node.h"

AVLTree::AVLTree(int firstKey)
{
    root_ = new Node(firstKey);
}

AVLTree::~AVLTree()
{
    delete root_;
}

bool AVLTree::insert(int key)
{
    if(root_->Find(key))
        return false;
    else {
        root_->Insert(key);
        return true;
    }
}

bool AVLTree::remove(int key)
{
    if(root_->Find(key)) {
        root_->Remove(key);
        return true;
    }
    else {
        return false;
    }
}

bool AVLTree::contains(int key)
{
    if(root_->Find(key))
        return true;
    else
        return false;
}
