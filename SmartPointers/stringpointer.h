#ifndef STRINGPOINTER_H
#define STRINGPOINTER_H
#include <string>

class StringPointer {
public:
    StringPointer(std::string * Pointer = 0);
    ~StringPointer();
    std::string *operator->();
    operator std::string*();

private:
    std::string * strPtr;
    bool myStringAllocated;
};

#endif // STRINGPOINTER_H
