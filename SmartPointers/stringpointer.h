#ifndef STRINGPOINTER_H
#define STRINGPOINTER_H
#include <string>

class StringPointer
{
public:
    StringPointer(std::string *pointer = 0);
    ~StringPointer();
    std::string * operator->();
    operator std::string*();

private:
    std::string *strPtr_;
    bool myStringAllocated_;
};

#endif // STRINGPOINTER_H
