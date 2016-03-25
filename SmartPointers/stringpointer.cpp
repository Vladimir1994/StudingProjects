#include "stringpointer.h"

StringPointer::StringPointer(std::string *pointer): strPtr_(pointer),
    myStringAllocated_(false)
{}

StringPointer::~StringPointer()
{
    if (strPtr_ && myStringAllocated_)
        delete strPtr_;
    strPtr_ = 0;
}

std::string * StringPointer::operator->()
{
    if (!strPtr_) {
        strPtr_ = new std::string("");
        myStringAllocated_ = true;
    }
    return strPtr_;
}
StringPointer::operator std::string*()
{
    if (!strPtr_) {
        strPtr_ = new std::string("");
        myStringAllocated_ = true;
    }
    return strPtr_;
}

