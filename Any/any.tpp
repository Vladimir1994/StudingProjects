template <class T>
Any::Any(const T &p) : ptr_(new ValueHolder<T>(p))
{}

template <class T>
Any & Any::operator=(T const &ptr)
{
    delete ptr_;
    ptr_ = 0;
    ptr_ = new ValueHolder<T>(ptr);
    return *this;
}

template <class T>
T * Any::cast()
{
    if (!ptr_)
        return 0;
    ValueHolder<T> * value_holder = dynamic_cast<ValueHolder<T> *>(ptr_);
    if (!value_holder)
        return 0;
    return &(value_holder->data_);
}
