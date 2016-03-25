#include "sharedptr.h"
#include <algorithm>

SharedPtr::SharedPtr(Expression *ptr)
{
   st_ = new Storage(ptr);
}

SharedPtr::~SharedPtr()
{
    if (st_->get() != 0)
        st_->dec();

    if (st_->count() == 0) {
        delete st_;
        st_ = 0;
    }
}

SharedPtr::SharedPtr(const SharedPtr &ptr)
{
    st_ = ptr.st_;
    if (ptr.get() != 0)
        st_->inc();
}

Expression * SharedPtr::get() const
{
   return st_->get();
}

void SharedPtr::reset(Expression *ptr)
{
    if (this->st_->get() == ptr)
        return;
    if (st_->get() != 0)
        st_->dec();
    if (st_->count() == 0){
        delete st_;
        st_ = 0;
    }
    st_ = new Storage(ptr);
}

SharedPtr & SharedPtr::operator=(const SharedPtr &ptr)
{
    if (this->st_ != ptr.st_)
        SharedPtr(ptr).swap(*this);
    return *this;
}

Expression & SharedPtr::operator*() const
{
    return *(st_->get());
}

Expression * SharedPtr::operator->() const
{
   return st_->get();
}

void SharedPtr::swap(SharedPtr &ptr)
{
    std::swap(st_, ptr.st_);
}
