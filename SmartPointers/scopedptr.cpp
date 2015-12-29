#include "scopedptr.h"

ScopedPtr::ScopedPtr(Expression *ptr): ptr_(ptr) {}

ScopedPtr::~ScopedPtr() {
    if(ptr_ != 0)
        delete ptr_;
}

Expression * ScopedPtr::get() const {
   return ptr_;
}

Expression * ScopedPtr::release() {
   Expression* my_ptr = ptr_;
   ptr_ = 0;
   return my_ptr;
}

void ScopedPtr::reset(Expression *ptr){
    if(ptr_ != 0)
        delete ptr_;
        ptr_ = ptr;
}

Expression & ScopedPtr::operator*() const {
    return *ptr_;
}
Expression * ScopedPtr::operator->() const {
   return ptr_;
}
