#include <cstdlib>

#ifndef ITEM_H
#define	ITEM_H

class item
{
public:
    item(int value = 0, item *previous = 0, item *next = 0);
    int getValue() const;
    item * getPrevious() const;
    item * getNext() const;
    void setPrevious(item *previous);
    void setNext(item *next);

private:
    int value_;
    item *previous_;
    item *next_;
};

#endif	/* ITEM_H */

