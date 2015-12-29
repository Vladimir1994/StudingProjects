#include "stringpointer.h"

StringPointer::StringPointer(std::string * Pointer): strPtr(Pointer),
    myStringAllocated(false) {}

StringPointer::~StringPointer() {
    if(strPtr && myStringAllocated)
        delete strPtr;
    strPtr = 0;
}

std::string * StringPointer::operator->() {
    if(!strPtr) {
        strPtr = new std::string("");
        myStringAllocated = true;
    }
    return strPtr;
}
StringPointer::operator std::string*() {
    if(!strPtr) {
        strPtr = new std::string("");
        myStringAllocated = true;
    }
    return strPtr;
}

