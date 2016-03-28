#include "set.h"

Set::Set() : size_(0), first_(0), last_(0)
{}

Set::Set(Set const &set)
{
    size_ = set.size_;
    if (size_ == 0) {
        first_ = 0;
        last_ = 0;
    } else {
        first_ = new item(set.first_->getValue());
        item *it_prev = first_;
        for (item *it = set.first_->getNext(); it != 0; it = it->getNext()) {
            item *it_new = new item(it->getValue(), it_prev);
            it_prev->setNext(it_new);
            it_prev = it_new;
            last_ = it_new;
        }
    }
}

Set::~Set()
{
    while (first_ != 0) {
        item *it = first_;
        first_ = first_->getNext();
        delete it;
    }
    last_ = 0;
}

size_t Set::size() const
{
    return size_;
}

bool Set::Insert(int value)
{
    item *it = first_;
    while (it != 0 && it->getValue() > value)
        it = it->getNext();
    if (it != 0 && it->getValue() == value) {
        return false;
    } else {
        item *itNew = new item(value);
        size_++;
        if (it == 0 && size_ == 1) {
            first_ = itNew;
            last_ = itNew;
        } else if (it == 0 && size_ != 1) {
            last_->setNext(itNew);
            itNew->setPrevious(last_);
            last_ = itNew;
        } else if(it == first_) {
            first_->setPrevious(itNew);
            itNew->setNext(first_);
            first_ = itNew;
        } else {
            item *it_prev = it->getPrevious();
            it_prev->setNext(itNew);
            itNew->setPrevious(it_prev);
            it->setPrevious(itNew);
            itNew->setNext(it);
        }
        return true;
    }
}

bool Set::Erase(int value)
{
    item *it = first_;
    while (it != 0 && it->getValue() != value)
        it = it->getNext();
    if (it == 0) {
        return false;
    } else {
        item *it_prev = it->getPrevious();
        item *it_next = it->getNext();
        size_--;
        if (it_prev == 0 && it_next == 0) {
            first_ = 0;
            last_ = 0;
            delete it;
        } else if (it_prev == 0 && it_next != 0) {
            it_next->setPrevious(0);
            first_ = it_next;
            delete it;
        } else if (it_prev != 0 && it_next == 0) {
            it_prev->setNext(0);
            last_ = it_prev;
            delete it;
        } else {
            it_prev->setNext(it_next);
            it_next->setPrevious(it_prev);
            delete it;
        }
        return true;
    }
}

bool Set::Contains(int value)
{
    item *it = first_;
    while (it != 0 && it->getValue() != value)
        it = it->getNext();
    if (it == 0)
        return false;
    else
        return true;
}

void Set::Union(Set const &set)
{
    item *it_1 = first_;
    item *it_2 = set.first_;
    while (it_1 != 0 && it_2 != 0) {
        if (it_1 ->getValue() > it_2->getValue()) {
            it_1 = it_1->getNext();
        } else if (it_1->getValue() < it_2->getValue()) {
            size_++;
            item *it_new = new item(it_2->getValue());
            if (it_1 == first_) {
                first_->setPrevious(it_new);
                it_new->setNext(first_);
                first_ = it_new;
            } else {
                item *it_prev = it_1->getPrevious();
                it_prev->setNext(it_new);
                it_new->setPrevious(it_prev);
                it_1->setPrevious(it_new);
                it_new->setNext(it_1);
            }
            it_2 = it_2->getNext();
        } else if (it_1->getValue() == it_2->getValue()) {
            it_1 = it_1->getNext();
            it_2 = it_2->getNext();
        }
    }
    while (it_2 != 0) {
        item *it_new = new item(it_2->getValue());
        size_++;
        if (it_1 == 0 && size_ == 1) {
            first_ = it_new;
            last_ = it_new;
        } else if (it_1 == 0 && size_ != 1) {
            last_->setNext(it_new);
            it_new->setPrevious(last_);
            last_ = it_new;
        }
        it_2 = it_2->getNext();
    }
}

void Set::Intersection(Set const &set)
{
    item *it_1 = first_;
    item *it_2 = set.first_;
    while (it_1 != 0 && it_2 != 0) {
        if (it_1 ->getValue() != it_2->getValue()) {
            if (it_1->getValue() > it_2->getValue()) {
                item *it = it_1;
                it_1 = it_1->getNext();
                size_--;
                item *it_prev = it->getPrevious();
                item *it_next = it->getNext();
                if (it_prev == 0 && it_next == 0) {
                    first_ = 0;
                    last_ = 0;
                    delete it;
                } else if (it_prev == 0 && it_next != 0) {
                    it_next->setPrevious(0);
                    first_ = it_next;
                    delete it;
                } else if (it_prev != 0 && it_next == 0) {
                    it_prev->setNext(0);
                    last_ = it_prev;
                    delete it;
                } else {
                    it_prev->setNext(it_next);
                    it_next->setPrevious(it_prev);
                    delete it;
                }
            } else {     
                it_2 = it_2->getNext();
            }
        } else {
            it_1 = it_1->getNext();
            it_2 = it_2->getNext();
        }
    }
    while (it_1 != 0) {
        item *it = it_1;
        size_--;
        item *it_prev = it->getPrevious();
        item *it_next = it->getNext();
        if (it_prev == 0 && it_next == 0){
            first_ = 0;
            last_ = 0;
            delete it;
        } else if (it_prev == 0 && it_next != 0) {
            it_next->setPrevious(0);
            first_ = it_next;
            delete it;
        } else if (it_prev != 0 && it_next == 0) {
            it_prev->setNext(0);
            last_ = it_prev;
            delete it;
        } else {
            it_prev->setNext(it_next);
            it_next->setPrevious(it_prev);
            delete it;
        }
        it_1 = it_1->getNext();
    }
}

void Set::Complement(Set const &set)
{
    item *it_1 = first_;
    item *it_2 = set.first_;
    while (it_1 != 0 && it_2 != 0) {
        if (it_1 ->getValue() != it_2->getValue()) {
            if (it_1 ->getValue() > it_2->getValue())
                it_1 = it_1->getNext();
            else
                it_2 = it_2->getNext();
        } else {
            item *it = it_1;
            it_1 = it_1->getNext();
            size_--;
            item *it_prev = it->getPrevious();
            item *it_next = it->getNext();
            if (it_prev == 0 && it_next == 0) {
                first_ = 0;
                last_ = 0;
                delete it;
            } else if (it_prev == 0 && it_next != 0) {
                it_next->setPrevious(0);
                first_ = it_next;
                delete it;
            } else if (it_prev != 0 && it_next == 0) {
                it_prev->setNext(0);
                last_ = it_prev;
                delete it;
            } else {
                it_prev->setNext(it_next);
                it_next->setPrevious(it_prev);
                delete it;
            }
            it_2 = it_2->getNext();
        }
    }
}

Set & Set::operator=(const Set &set)
{
    if(this->first_ != set.first_)
        Set(set).swap(*this);
    return *this;
}

Set & Set::operator+=(Set const &set)
{
    this->Union(set);
    return *this;
}

Set &Set::operator-=(Set const &set)
{
    this->Complement(set);
    return *this;
}

Set &Set::operator*=(Set const &set)
{
    this->Intersection(set);
    return *this;
}

std::ostream & operator<<(std::ostream &out, Set const &set)
{
    for (item *it = set.first_; it != 0; it = it->getNext()) {
        int tmp = it->getValue();
        out << tmp << ' ';
    }
    return out;
}

void Set::swap(Set &set)
{
    std::swap(size_, set.size_);
    std::swap(first_, set.first_);
    std::swap(last_, set.last_);
}

Set operator+(Set const &setFirst, Set const &setSecond)
{
    Set set(setFirst);
    set.Union(setSecond);
    return set;
}

Set operator-(Set const &setFirst, Set const &setSecond)
{
    Set set(setFirst);
    set.Complement(setSecond);
    return set;
}

Set operator*(Set const &setFirst, Set const &setSecond)
{
    Set set(setFirst);
    set.Intersection(setSecond);
    return set;
}

