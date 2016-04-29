#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <list>
#include <vector>

#include <utility>
#include <iostream>

#include <cstdlib>

typedef std::pair<size_t, size_t> Subscript;
typedef std::list<Subscript> SubscriptList;

template <typename T>
class Matrix;

template <typename T>
std::ostream & operator<<(std::ostream &out, const Matrix<T> &m);
template <typename T>
bool operator==(const Matrix<T> &m1, const Matrix<T> &m2);

template <typename T>
class Matrix
{
public:
    Matrix(size_t rows = 0, size_t cols = 0, T initValue = 0);
    ~Matrix();

    /*
     * fills matrix with uniform distributed values
     */
    void fillRandom(T minVal, T maxVal);

    /*
     * elements access oparators
     */
    T & operator()(size_t row, size_t col);
    T operator()(size_t row, size_t col) const;
    T & operator()(const Subscript &sub);
    T operator()(const Subscript &sub) const;

    friend std::ostream & operator<< <>(std::ostream &out, const Matrix<T> &m);
    friend bool operator== <>(const Matrix<T> &m1, const Matrix<T> &m2);

    size_t rows() const;
    size_t cols() const;

    /*
     * returns subscripts of maximum and minimum elements
     */
    SubscriptList argMax() const;
    SubscriptList argMin() const;

    /*
     * returns subscripts of elements on main and secondary diagonals,
     * which are closer to value than accuracy
     */
    SubscriptList getCloseToValue(T value, double accuracy) const;

    /*
     * rotates matrix 45 degrees using neares neighbour interpolation
     */
    void rotateFortyFive();

private:
    size_t rows_;
    size_t cols_;
    std::vector<T> matrixData_;

private:
    size_t subscriptToIndex(size_t row, size_t col) const;
    size_t subscriptToIndex(const Subscript &sub) const;
    Subscript indexToSubscript(size_t index) const;

    /*
     * returns subscripts of elements computed with func
     */
    template<typename funcType>
    SubscriptList find(funcType func) const;
};

typedef std::vector<std::vector<double>> ArrayDouble2D;

ArrayDouble2D euclidianDistance(const SubscriptList &subListOne,
                                const SubscriptList &subListTwo);

std::ostream & operator<<(std::ostream &out, const SubscriptList &sl);
std::ostream & operator<<(std::ostream &out, const ArrayDouble2D &arr);

#include "matrix.tpp"

#endif // MATRIX_HPP
