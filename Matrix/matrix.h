#ifndef MATRIX_H
#define MATRIX_H

#include <fstream>

class Matrix
{
public:
    Matrix();
    ~Matrix();

    bool read(const char *inStr);
    bool add(const Matrix &m);
    bool multiply(const Matrix &m);
    void print() const;

private:
    int length_;
    int height_;
    double **matrix_;

private:
    void initMatrix(int length, int height, int val = 0);
};

#endif // MATRIX_H
