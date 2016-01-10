#ifndef ITEM_H
#define ITEM_H

class item
{
public:
    item(int value = 0, item * previous = 0, item * next = 0);
    int get_value() const;
    item* get_previous() const;
    item* get_next() const;
    void set_previous(item*);
    void set_next(item*);

private:
    int value_;
    item *previous_;
    item *next_;

};

#endif // ITEM_H
