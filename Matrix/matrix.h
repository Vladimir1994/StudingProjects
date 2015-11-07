#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

class Matrix
{
public:
    Matrix();
    ~Matrix();

    bool read(const char *);
    bool add(const Matrix &);
    bool multiply(const Matrix &);
    void print() const;

private:
    int length_;
    int height_;
    double ** matrix_;
private:
    void initMatrix(const int & length, const int & height, const int & val = 0);
};

#endif // MATRIX_H
