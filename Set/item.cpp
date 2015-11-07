#include "item.h"

item::item(int value, item *previous, item *next) :
    value_(value), previous_(previous), next_(next) {}

int item::get_value() const {
    return value_;
}

item* item::get_previous() const {
    return previous_;
}

item* item::get_next() const {
    return next_;
}

void item::set_previous(item* previous) {
    previous_ = previous;
}

void item::set_next(item* next) {
    next_ = next;
}
