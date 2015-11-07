#include "any.h"

Any::Any() : ptr_(0) { }

Any::Any(Any const & any)
{
    if(any.ptr_)
        ptr_ = any.ptr_->clone();
    else
        ptr_ = 0;
}

Any & Any::operator = (Any const & any)
{
    if(ptr_ != any.ptr_){
        delete ptr_;
        ptr_ = 0;
        if (any.ptr_)
        {
            ptr_ = any.ptr_->clone();
        }
    }
    return *this;
}

Any::~Any() {
    delete ptr_;
}
