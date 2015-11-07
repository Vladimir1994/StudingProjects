#ifndef MyString_H
#define MyString_H

#include <stdlib.h>

class MyString {
public:
    MyString(const char * str = "");
    MyString(size_t n, char c);

    MyString(MyString const & obj);
    MyString & operator = (const MyString & str);

    ~MyString();

    size_t size() const;
    char const  & at(size_t idx) const;
    char & at(size_t idx);
    const char * c_str() const;
    int compare(MyString & str) const;
    void append(MyString & str);
    void swap(MyString & str);

private:
    size_t size_;
    char * str_;
};

#endif // MyString_H
