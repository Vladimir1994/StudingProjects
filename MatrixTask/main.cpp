#include "matrix.hpp"

#include <string>
#include <fstream>

int main()
{
    std::ofstream ofs("result.txt", std::ofstream::out);
    if (!ofs.is_open()) {
        std::cerr << "The output file could not be opened." << std::endl;
        return -1;
    }

    std::cout << "Enter matrix of integers dimension." << std::endl;
    size_t mIntRows = 0;
    size_t mIntCols = 0;
    std::cin >> mIntRows >> mIntCols;

    std::cout << "Enter uniform distribution limits to "
                 "generate matrix of integers." << std::endl;
    int aInt = 0;
    int bInt = 0;
    std::cin >> aInt >> bInt;

    std::cout << "Enter accuracy for matrix of integers." << std::endl;
    double accuracyInt;
    std::cin >> accuracyInt;

    Matrix<int> mInt(mIntRows, mIntCols);
    mInt.fillRandom(aInt, bInt);

    ofs << "Matrix of integers:" << std::endl << mInt << std::endl;

    SubscriptList maxSubscriptsInt = mInt.argMax();
    SubscriptList minSubscriptsInt = mInt.argMin();

    SubscriptList closeToMaxSubscriptsInt
        = mInt.getCloseToValue(mInt(maxSubscriptsInt.front()), accuracyInt);

    ofs << "Subscripts of elements on main and secondary diagonals, "
           "which are closer to maximum than accuracy:" << std::endl
        << closeToMaxSubscriptsInt << std::endl;

    SubscriptList closeToMinSubscriptsInt
        = mInt.getCloseToValue(mInt(minSubscriptsInt.front()), accuracyInt);

    ofs << "Subscripts of elements on main and secondary diagonals, "
           "which are closer to minimums than accuracy:" << std::endl
        << closeToMinSubscriptsInt << std::endl;

    ArrayDouble2D distancesToMaxInt
        = euclidianDistance(maxSubscriptsInt, closeToMaxSubscriptsInt);

    ofs << "Distances from elements on main and secondary diagonals, "
           "which are closer to maximum than accuracy, to maximums:"
        << std::endl << distancesToMaxInt << std::endl;

    ArrayDouble2D distancesToMinInt
        = euclidianDistance(minSubscriptsInt, closeToMinSubscriptsInt);

    ofs << "Distances from elements on main and secondary diagonals, "
           "which are closer to minimums than accuracy, to maximums:"
        << std::endl << distancesToMinInt << std::endl;

    mInt.rotateFortyFive();

    ofs << "Rotated matrix:" << std::endl << mInt << std::endl;;

    //-------------------------------------------------------------------------

    std::cout << "Enter matrix of double dimension." << std::endl;
    size_t mDoubleRows = 0;
    size_t mDoubleCols = 0;
    std::cin >> mDoubleRows >> mDoubleCols;

    std::cout << "Enter uniform distribution limits to "
                 "generate matrix of double." << std::endl;
    double aDouble = 0;
    double bDouble = 0;
    std::cin >> aDouble >> bDouble;

    std::cout << "Enter accuracy for matrix of double." << std::endl;
    double accuracyDouble;
    std::cin >> accuracyDouble;

    Matrix<double> mDouble(mDoubleRows, mDoubleCols);
    mDouble.fillRandom(aDouble, bDouble);

    ofs << "Matrix of double:" << std::endl << mDouble << std::endl;

    SubscriptList maxSubscriptsDouble = mDouble.argMax();
    SubscriptList minSubscriptsDouble = mDouble.argMin();

    SubscriptList closeToMaxSubscriptsDouble =
        mDouble.getCloseToValue(mDouble(maxSubscriptsDouble.front()),
                                accuracyDouble);

    ofs << "Subscripts of elements on main and secondary diagonals, "
           "which are closer to maximum than accuracy:" << std::endl
        << closeToMaxSubscriptsDouble << std::endl;

    SubscriptList closeToMinSubscriptsDouble
        = mDouble.getCloseToValue(mDouble(minSubscriptsDouble.front()),
                                          accuracyDouble);

    ofs << "Subscripts of elements on main and secondary diagonals, "
           "which are closer to minimums than accuracy:" << std::endl
        << closeToMinSubscriptsDouble << std::endl;


    ArrayDouble2D distancesToMaxDouble
        = euclidianDistance(maxSubscriptsDouble,
                            closeToMaxSubscriptsDouble);

    ofs << "Distances from elements on main and secondary diagonals, "
           "which are closer to maximum than accuracy to maximums:"
        << std::endl << distancesToMaxDouble << std::endl;

    ArrayDouble2D distancesToMinDouble
        = euclidianDistance(minSubscriptsDouble, closeToMinSubscriptsDouble);

    ofs << "Distances from elements on main and secondary diagonals, "
           "which are closer to minimums than accuracy to maximums:"
        << std::endl << distancesToMinDouble << std::endl;

    mDouble.rotateFortyFive();

    ofs << "Rotated matrix:" << std::endl;
    ofs << mDouble;

    ofs.close();

    return 0;
}

