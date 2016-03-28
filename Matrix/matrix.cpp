#include "matrix.h"
#include <iostream>

Matrix::Matrix():length_(0), height_(0), matrix_(0)
{}

Matrix::~Matrix()
{
    if (matrix_) {
        delete [] matrix_[0];
        delete [] matrix_;
    }
    length_ = 0;
    height_ = 0;
}

bool Matrix::read(const char *inStr)
{
    if (matrix_) {
        delete [] matrix_[0];
        delete [] matrix_;
    }

    std::filebuf mfile;

    int length;
    int height;

    if (mfile.open (inStr, std::ios::in)) {
        std::istream is(&mfile);
        is >> length;
        is >> height;

        initMatrix(length, height);

        for (int i = 0; i < height_; i++) {
            for (int j = 0; j < length_; j++)
                is >> matrix_[i][j];
        }

        mfile.close();
        return true;
    } else {
        return false;
    }
}

bool Matrix::add(const Matrix &m)
{
    if (m.length_ != this->length_ || m.height_ != this->height_)
        return false;

    for (int i = 0; i < height_; i++) {
        for (int j = 0; j < length_; j++)
            matrix_[i][j] += m.matrix_[i][j];
    }
    return true;
}

bool Matrix::multiply(const Matrix &m)
{
    if (this->length_ != m.height_)
        return false;

    Matrix result;
    result.initMatrix(this->height_, m.length_ );

    for (int i = 0; i < this->height_; i++) {
        for (int j = 0; j < m.length_; j++) {
            for (int k = 0; k < this->length_; k++)
                result.matrix_[i][j] += matrix_[i][k] * m.matrix_[k][j];
        }
    }

    this->~Matrix();
    this->initMatrix(result.length_, result.height_);

    for (int i = 0; i < result.height_; i++) {
        for (int j = 0; j < result.length_; j++)
            matrix_[i][j] += result.matrix_[i][j];
    }

    return true;
}

void Matrix::print() const
{
    for (int i = 0; i < length_; i++) {
        for (int j = 0; j < height_; j++)
            std::cout << matrix_[i][j] << " ";
        std::cout << std::endl;
    }
}

void Matrix::initMatrix(int length, int height, int val)
{
    length_ = length;
    height_ = height;

    matrix_ = new double * [height_];
    matrix_[0] = new double [height_ * length_];

    for (int i = 1; i < height_; i++)
        matrix_[i] = matrix_[i - 1] + length_;

    for (int i = 0; i < height_; i++) {
        for(int j = 0; j < length_; j++)
            matrix_[i][j] = val;
    }
}
