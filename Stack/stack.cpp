#include "stack.h"

#include <iostream>

using namespace std;

Stack::Stack() : head_(0)
{}

void Stack::push(int value)
{
    if (head_ == 0) {
        item *it = new item(value);
        head_ = it;
    } else {
        item *it = new item(value);
        head_->setNext(it);
        it->setPrevious(head_);
        head_ = it;
    }
}

int Stack::pop()
{
    if (head_ == 0) {
        return 0;

    } else {
        item *it = head_->getPrevious();
        int value = head_->getValue();
        delete head_;
        head_ = it;
        head_->setNext(0);
        return value;
    }
}

void Stack::MaxToTop()
{
    item *it = head_;
    item *it_max = head_;
    while (it != 0) {
        if (it->getValue() > it_max->getValue())
            it_max = it;
        it = it->getPrevious();
    }
    if (it_max != head_) {
        item *it_prev = it_max->getPrevious();
        item *it_next = it_max->getNext();
        item *head_prev = head_->getPrevious();
        if (head_ == it_next) {
            if (it_prev != 0)
                it_prev->setNext(head_);
            head_->setPrevious(it_prev);
            it_max->setNext(0);
            it_max->setPrevious(head_);
            head_->setNext(it_max);
            head_ = it_max;
        } else {
            if (it_prev != 0)
                it_prev->setNext(head_);
            it_next->setPrevious(head_);
            head_->setNext(it_next);
            head_->setPrevious(it_prev);
            it_max->setNext(0);
            it_max->setPrevious(head_prev);
            head_prev->setNext(it_max);
            head_ = it_max;
        }
    }
}

void Stack::show()
{
    item *it = head_;
    while (it != 0) {
        cout << it->getValue() << ' ';
        it = it->getPrevious();
    }
}

Stack::~Stack()
{
    while (head_ != 0) {
        item *it = head_;
        head_ = head_->getPrevious();
        delete it;
    }
}
