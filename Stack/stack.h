#ifndef STACK_H
#define STACK_H

#include "item.h"

class Stack
{
public:
    Stack();
    void push(int value);
    int pop();
    void show();
    void MaxToTop();
    ~Stack();

private:
    item *head_;
};

#endif // STACK_H
