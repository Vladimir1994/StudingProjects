#include "set.h"

Set::Set() : size_(0), first_(0), last_(0) {}

void Set::swap(Set & set) {
    std::swap(size_, set.size_);
    std::swap(first_, set.first_);
    std::swap(last_, set.last_);
}

Set::Set(Set const & set) {
    size_ = set.size_;
    if(size_ == 0) {
        first_ = 0;
        last_ = 0;
    }
    else {
        first_ = new item(set.first_->get_value());
        item *it_prev = first_;
        for(item *it = set.first_->get_next(); it != 0; it = it->get_next()) {
            item *it_new = new item(it->get_value(), it_prev);
            it_prev->set_next(it_new);
            it_prev = it_new;
            last_ = it_new;
        }
    }
}

size_t Set::size() const {
    return size_;
}

bool Set::Insert(const int &value) {
    item *it = first_;
    while(it != 0 && it->get_value() > value) {
        it = it->get_next();
    }
    if(it != 0 && it->get_value() == value) {
        return false;
    }
    else {
        item *it_new = new item(value);
        size_++;
        if(it == 0 && size_ == 1) {
            first_ = it_new;
            last_ = it_new;
        }
        else if(it == 0 && size_ != 1) {
            last_->set_next(it_new);
            it_new->set_previous(last_);
            last_ = it_new;
        }
        else if(it == first_) {
            first_->set_previous(it_new);
            it_new->set_next(first_);
            first_ = it_new;
        }
        else {
            item *it_prev = it->get_previous();
            it_prev->set_next(it_new);
            it_new->set_previous(it_prev);
            it->set_previous(it_new);
            it_new->set_next(it);
        }
        return true;
    }
}

bool Set::Erase(const int &value) {
    item *it = first_;
    while(it != 0 && it->get_value() != value) {
        it = it->get_next();
    }
    if(it == 0) {
        return false;
    }
    else {
        item *it_prev = it->get_previous();
        item *it_next = it->get_next(); 
        size_--;
        if(it_prev == 0 && it_next == 0){ 
            first_ = 0;
            last_ = 0;
            delete it;
        }
        else if(it_prev == 0 && it_next != 0) {
            it_next->set_previous(0);
            first_ = it_next;
            delete it;
        }
        else if(it_prev != 0 && it_next == 0) {
            it_prev->set_next(0);
            last_ = it_prev;
            delete it;
        }
        else {
            it_prev->set_next(it_next);
            it_next->set_previous(it_prev);
            delete it;
        }
        return true;
    }
}

bool Set::Contains(const int &value) {
    item *it = first_;
    while(it != 0 && it->get_value() != value) {
        it = it->get_next();
    }
    if(it == 0) {
        return false;
    }
    else {
        return true;
    }
}

void Set::Union(Set const & set) {
    item *it_1 = first_;
    item *it_2 = set.first_;
    while(it_1 != 0 && it_2 != 0) {
        if(it_1 ->get_value() > it_2->get_value()) {
            it_1 = it_1->get_next();
        }
        else if(it_1->get_value() < it_2->get_value()) {
            size_++;
            item *it_new = new item(it_2->get_value());
            if(it_1 == first_) {
                first_->set_previous(it_new);
                it_new->set_next(first_);
                first_ = it_new;
            }
            else {
                item *it_prev = it_1->get_previous();
                it_prev->set_next(it_new);
                it_new->set_previous(it_prev);
                it_1->set_previous(it_new);
                it_new->set_next(it_1);
            }
            it_2 = it_2->get_next();
        }
        else if(it_1->get_value() == it_2->get_value()) {
            it_1 = it_1->get_next();
            it_2 = it_2->get_next();
        }
    }
    while(it_2 != 0) {
        item *it_new = new item(it_2->get_value());
        size_++;
        if(it_1 == 0 && size_ == 1) {
            first_ = it_new;
            last_ = it_new;
        }
        else if(it_1 == 0 && size_ != 1) {
            last_->set_next(it_new);
            it_new->set_previous(last_);
            last_ = it_new;
        }
        it_2 = it_2->get_next();
    }
}

void Set::Intersection(Set const & set) {
    item *it_1 = first_;
    item *it_2 = set.first_;
    while(it_1 != 0 && it_2 != 0) {
        if(it_1 ->get_value() != it_2->get_value()) {       
            if(it_1->get_value() > it_2->get_value()) {
                item *it = it_1;
                it_1 = it_1->get_next();
                size_--;
                item *it_prev = it->get_previous();
                item *it_next = it->get_next();
                if(it_prev == 0 && it_next == 0){
                    first_ = 0;
                    last_ = 0;
                    delete it;
                }
                else if(it_prev == 0 && it_next != 0) {
                    it_next->set_previous(0);
                    first_ = it_next;
                    delete it;
                }
                else if(it_prev != 0 && it_next == 0) {
                    it_prev->set_next(0);
                    last_ = it_prev;
                    delete it;
                }
                else {
                    it_prev->set_next(it_next);
                    it_next->set_previous(it_prev);
                    delete it;
                }
            }
            else {     
                it_2 = it_2->get_next();
            }
        }
        else {
            it_1 = it_1->get_next();
            it_2 = it_2->get_next();
        }
    }
    while(it_1 != 0) {
        item *it = it_1;
        size_--;
        item *it_prev = it->get_previous();
        item *it_next = it->get_next();
        if(it_prev == 0 && it_next == 0){
            first_ = 0;
            last_ = 0;
            delete it;
        }
        else if(it_prev == 0 && it_next != 0) {
            it_next->set_previous(0);
            first_ = it_next;
            delete it;
        }
        else if(it_prev != 0 && it_next == 0) {
            it_prev->set_next(0);
            last_ = it_prev;
            delete it;
        }
        else {
            it_prev->set_next(it_next);
            it_next->set_previous(it_prev);
            delete it;
        }
        it_1 = it_1->get_next();
    }
}

void Set::Complement(Set const & set) {
    item *it_1 = first_;
    item *it_2 = set.first_;
    while(it_1 != 0 && it_2 != 0) {
        if(it_1 ->get_value() != it_2->get_value()) {       
            if(it_1 ->get_value() > it_2->get_value()) {
                it_1 = it_1->get_next();
            }
            else {     
                it_2 = it_2->get_next();
            }
        }
        else {
            item *it = it_1;
            it_1 = it_1->get_next();
            size_--;
            item *it_prev = it->get_previous();
            item *it_next = it->get_next();
            if(it_prev == 0 && it_next == 0){
                first_ = 0;
                last_ = 0;
                delete it;
            }
            else if(it_prev == 0 && it_next != 0) {
                it_next->set_previous(0);
                first_ = it_next;
                delete it;
            }
            else if(it_prev != 0 && it_next == 0) {
                it_prev->set_next(0);
                last_ = it_prev;
                delete it;
            }
            else {
                it_prev->set_next(it_next);
                it_next->set_previous(it_prev);
                delete it;
            }
            it_2 = it_2->get_next();
        }
    }
}

Set& Set::operator = (const Set &set){
    if(this->first_ != set.first_)
        Set(set).swap(*this);
    return *this;
}

Set &Set::operator += (Set const & set){
        this->Union(set);
        return *this;
}

Set &Set::operator -= (Set const & set){
    this->Complement(set);
    return *this;
}

Set &Set::operator *= (Set const & set){
    this->Intersection(set);
    return *this;
}

std::ostream & operator << (std::ostream & out, Set const & set) {
    for(item *it = set.first_; it != 0; it = it->get_next()) {
        int tmp = it->get_value();
        out << tmp << ' ';
    }
    return out;
}

Set::~Set() {
    while(first_ != 0) {
        item *it = first_;
        first_ = first_->get_next();
        delete it;
    }
    last_ = 0;
}

Set operator + (Set const & set_1, Set const & set_2){
    Set set(set_1); 
    set.Union(set_2);
    return set;
}

Set operator - (Set const & set_1, Set const & set_2){
    Set set(set_1); 
    set.Complement(set_2);
    return set;
}

Set operator * (Set const & set_1, Set const & set_2){
    Set set(set_1); 
    set.Intersection(set_2);
    return set;
}
