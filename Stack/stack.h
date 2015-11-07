#ifndef STACK_H
#define STACK_H

#include "item.h"

class Stack {
public:
    Stack();
    void push(int);
    int pop();
    void show();
    void max_to_top();
    ~Stack();

private:
    item *head_;

};

#endif // STACK_H
