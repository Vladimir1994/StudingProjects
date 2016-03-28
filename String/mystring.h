#ifndef MyString_H
#define MyString_H

#include <stdlib.h>

class MyString
{
public:
    MyString(const char *str = "");
    MyString(size_t n, char c);

    MyString(const MyString &str);
    MyString & operator=(const MyString &str);

    MyString(MyString &&str);
    MyString & operator=(MyString &&str);

    ~MyString();

    size_t size() const;
    char const  & at(size_t idx) const;
    char & at(size_t idx);
    const char * c_str() const;
    int compare(const MyString &str) const;
    void append(const MyString &str);
    void swap(MyString &str);

private:
    size_t size_;
    char *str_;
};

#endif // MyString_H
