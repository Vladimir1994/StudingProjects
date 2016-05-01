#include <algorithm>
#include <random>
#include <type_traits>
#include <chrono>

#include <cmath>

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols, T initValue) :
    rows_(rows), cols_(cols), matrixData_(std::vector<T>(rows * cols, initValue))
{
    static_assert(std::is_same<T, double>::value
                  || std::is_same<T, int>::value,
                  "Only int or double may be used with Matrix template.");
}

template <typename T>
Matrix<T>::~Matrix()
{}

template <typename T>
void Matrix<T>::fillRandom(T minVal, T maxVal)
{
    std::mt19937 mt(std::chrono::high_resolution_clock::
                    now().time_since_epoch().count());

    if (std::is_same<T, double>::value) {
        std::uniform_real_distribution<double> distrib(minVal, maxVal);
        for(auto &val: matrixData_)
            val = distrib(mt);
    } else if (std::is_same<T, int>::value) {
        std::uniform_int_distribution<int> distrib(minVal, maxVal);
        for(auto &val: matrixData_)
            val = distrib(mt);
    }
}

template <typename T>
T & Matrix<T>::operator()(size_t row, size_t col)
{
    return matrixData_[subscriptToIndex(row, col)];
}

template <typename T>
T Matrix<T>::operator()(size_t row, size_t col) const
{
    return matrixData_[subscriptToIndex(row, col)];
}

template <typename T>
T & Matrix<T>::operator()(const Subscript &sub)
{
    return matrixData_[subscriptToIndex(sub)];
}

template <typename T>
T Matrix<T>::operator()(const Subscript &sub) const
{
    return matrixData_[subscriptToIndex(sub)];
}

template <typename T>
std::ostream & operator<<(std::ostream &out, const Matrix<T> &m)
{
    for (size_t i = 0; i < m.rows_; i++) {
        for (size_t j = 0; j < m.cols_; j++)
            out << m(i, j) << " ";
        out << std::endl;
    }
    return out;
}

template <typename T>
bool operator==(const Matrix<T> &m1, const Matrix<T> &m2)
{
    if (m1.matrixData_ == m2.matrixData_
            && m1.cols_ == m2.cols_ && m1.rows_ == m2.rows_) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
size_t Matrix<T>::rows() const
{
    return rows_;
}

template <typename T>
size_t Matrix<T>::cols() const
{
    return cols_;
}

template <typename T>
SubscriptList Matrix<T>::argMax() const
{
    return find(&std::max_element<typename std::vector<T>::const_iterator>);
}

template <typename T>
SubscriptList Matrix<T>::argMin() const
{
    return find(&std::min_element<typename std::vector<T>::const_iterator>);
}

template <typename T>
SubscriptList Matrix<T>::getCloseToValue(T value, double accuracy) const
{
    SubscriptList closeElementsSubscripts;
    
    for (size_t i = 0; i < std::min(rows_, cols_); i++) {

        if (fabs(matrixData_[subscriptToIndex(i, i)] - value)
                <= accuracy) {

            std::pair<size_t, size_t> p(i, i);
            closeElementsSubscripts.push_back(p);
        }

        if ((fabs(matrixData_[subscriptToIndex(i, cols_ - i - 1)] - value)
                <= accuracy) && (i != cols_ - i - 1)) {

            std::pair<size_t, size_t> p(i, cols_ - i  - 1);
            closeElementsSubscripts.push_back(p);
        }

    }

    return closeElementsSubscripts;
}

template <typename T>
void Matrix<T>::rotateFortyFive()
{
    constexpr double sqrt2Div2 = sqrt(2) / 2;

    size_t rotRows = round(sqrt2Div2 * rows_ + sqrt2Div2 * cols_);
    size_t rotCols = round(sqrt2Div2 * rows_ + sqrt2Div2 * cols_);

    int midRow = ceil(rows_ / 2);
    int midCol = ceil(cols_ / 2);

    int rotMidRow = ceil(rotRows / 2);
    int rotMidCol = ceil(rotCols / 2);

    std::vector<T> rotatedMatrix(rotRows * rotCols, 0);

    for (size_t i = 0; i < rotatedMatrix.size(); i++) {
        int rotRow = i / rotCols;
        int rotCol = i - rotCols * rotRow;

        int straightRow = round((rotRow - rotMidRow) * sqrt2Div2
            + (rotCol - rotMidCol) * sqrt2Div2) + midRow;

        int straightCol = round(-(rotRow - rotMidRow) * sqrt2Div2
            + (rotCol - rotMidCol) * sqrt2Div2) + midCol;

        if (straightRow >= 0 && straightRow < rows_
                && straightCol >= 0 && straightCol < cols_) {
            rotatedMatrix[i] = matrixData_[
                subscriptToIndex(straightRow, straightCol)];
        }
    }

    rows_ = rotRows;
    cols_ = rotCols;
    matrixData_ = rotatedMatrix;
}

template <typename T>
size_t Matrix<T>::subscriptToIndex(size_t row, size_t col) const
{
    return row * cols_ + col;
}

template <typename T>
size_t Matrix<T>::subscriptToIndex(const Subscript &sub) const
{
    return sub.first * cols_ + sub.second;
}

template <typename T>
Subscript Matrix<T>::indexToSubscript(size_t index) const
{
    std::pair<size_t, size_t> subscript;
    subscript.first = index / cols_;
    subscript.second = index - cols_ * subscript.first;
    return subscript;
}

template <typename T>
template <typename funcType>
SubscriptList Matrix<T>::find(funcType func) const
{
    auto elementIter = func(matrixData_.begin(), matrixData_.end());

    T element = *elementIter;
    SubscriptList subcripts;

    auto endIter = matrixData_.cend();
    auto beginIter = matrixData_.cbegin();
    while (elementIter != endIter) {
        subcripts.push_back(
            indexToSubscript(std::distance(beginIter,
                                           elementIter)));
        elementIter = std::find(elementIter + 1,
                                endIter,
                                element);
    }

    return subcripts;
}

ArrayDouble2D euclidianDistance(const SubscriptList &subListOne,
                                const SubscriptList &subListTwo)
{
    ArrayDouble2D distances;
    distances.resize(subListOne.size());

    for (auto &v: distances)
        v.resize(subListTwo.size());

    size_t i = 0;
    size_t j = 0;
    for (const auto &subOne: subListOne) {
        for (const auto &subTwo: subListTwo) {
            distances[i][j] = sqrt(pow(static_cast<double>(subOne.first)
                                     - static_cast<double>(subTwo.first), 2)
                                 + pow(static_cast<double>(subOne.second)
                                     - static_cast<double>(subTwo.second), 2));
            j++;
        }
        i++;
        j = 0;
    }

    return distances;
}

std::ostream & operator<<(std::ostream &out, const SubscriptList &sl)
{
    for (const auto &s: sl) {
        out << s.first << ", " << s.second << std::endl;
    }
    return out;
}

std::ostream & operator<<(std::ostream &out, const ArrayDouble2D &arr)
{
    for (size_t i = 0; i < arr.size(); i++) {
        for (size_t j = 0; j < arr[0].size(); j++)
            out << arr[i][j] << " ";
        out << std::endl;
    }
    return out;
}
