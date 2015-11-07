#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack() : head_(0) {}

void Stack::push(int val) {
    if(head_ == 0)
    {
        item *it = new item(val);
        head_ = it;
    }
    else
    {
        item *it = new item(val);
        head_->set_next(it);
        it->set_previous(head_);
        head_ = it;
    }
}

int Stack::pop()
{
    if(head_ == 0)
    {
        return 0;

    }
    else
    {
        item *it = head_ ->get_previous();
        int val = head_->get_value();
        delete head_;
        head_ = it;
        head_->set_next(0);
        return val;
    }
}

void Stack::max_to_top()
{
    item *it = head_;
    item *it_max = head_;
    while(it != 0)
    {
        if(it->get_value() > it_max->get_value())
            it_max = it;
        it = it->get_previous();
    }
    if(it_max != head_)
    {
        item *it_prev = it_max->get_previous();
        item *it_next = it_max->get_next();
        item *head_prev = head_->get_previous();
        if(head_ == it_next)
        {
            if(it_prev != 0)
                it_prev->set_next(head_);
            head_->set_previous(it_prev);
            it_max->set_next(0);
            it_max->set_previous(head_);
            head_->set_next(it_max);
            head_ = it_max;
        }
        else
        {
            if(it_prev != 0)
                it_prev->set_next(head_);
            it_next->set_previous(head_);
            head_->set_next(it_next);
            head_->set_previous(it_prev);
            it_max->set_next(0);
            it_max->set_previous(head_prev);
            head_prev->set_next(it_max);
            head_ = it_max;
        }
    }
}

void Stack::show() {
    item *it = head_;
    while(it != 0)
    {
        cout << it->get_value() << ' ';
        it = it->get_previous();
    }
}

Stack::~Stack()
{
    while(head_ != 0)
    {
        item *it = head_;
        head_ = head_->get_previous();
        delete it;
    }
}
