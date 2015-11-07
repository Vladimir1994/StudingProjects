#include "mystring.h"
#include "string.h"
#include "algorithm"
#include <cstring>


MyString::MyString(const char *str) {
    size_ = strlen(str);
    str_ = new char[size_];
    std::strcpy(str_, str);
}

MyString::MyString(size_t n, char c) {
    size_ = n;
    str_ = new char[size_ + 1];
    for(unsigned int i = 0; i < n; i++) {
        str_[i] = c;
    }
    str_[n] = '\0';
}

MyString::MyString(MyString const &obj) {
    size_ = obj.size();
    str_ = new char[size_ + 1];
    std::strcpy(str_, obj.str_);
    this->str_[size_ + 1] = '\0';
}

MyString & MyString::operator = (const MyString &str) {
    if(this->str_ != str.str_)
        MyString(str).swap(*this);
    return *this;
}

MyString::~MyString() {
    delete [] str_;
}

size_t MyString::size() const {
    return size_;
}

char const & MyString::at(size_t idx) const {
        return str_[idx];
}

char & MyString::at(size_t idx){
        return str_[idx];
}

const char * MyString::c_str() const {
    const char *str = str_;
    return str;
}

int MyString::compare(MyString &str) const {
    return std::strcmp(this->c_str(), str.c_str());
}

void MyString::append(MyString &str) {
    char *tmp = new char[size_+1];
    std::strcpy(tmp, str_);
    delete [] str_;
    str_ = new char[size_ + str.size() + 1];
    strcpy(str_, tmp);
    strcpy(str_ + size_, str.str_);
    this->size_ = str.size() + size_;;
    this->str_[size_ + 1] = '\0';
    delete [] tmp;
}

void MyString::swap(MyString & str) {
    std::swap(size_, str.size_);
    std::swap(str_, str.str_);
}

