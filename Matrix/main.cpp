#include <iostream>
#include <string>
#include "matrix.h"

using namespace std;

int main(int argc, char ** argv)
{
    std::string command;
    Matrix res_matrix;

    if(argc <= 1) {
        std::cerr << "No input data" << std::endl;
        return -1;
    }

    if(!res_matrix.read(argv[1])) {
        std::cerr << "Can not read from file " << argv[1] << std::endl;
        return -1;
    }

    for(int i = 2; i < argc; i+=2) {
        command = argv[i];

        Matrix next_matrix;
        if(!next_matrix.read(argv[i + 1])) {
            std::cerr << "Can not read from file " << argv[i + 1] << std::endl;
            return -1;
        }

        if(command == "--add"){
            if(!res_matrix.add(next_matrix)) {
                std::cerr << "Matrix dimension error " << argv[i + 1] << std::endl;
                return -1;
            }
        }
        else if(command == "--mult") {
            if(!res_matrix.multiply(next_matrix)) {
                std::cerr << "Matrix dimension error " << argv[i + 1] << std::endl;
                return -1;
            }
        }
        else {
            std::cerr << "Wrong command " << command << std::endl;
        }
    }

    res_matrix.print();

    return 0;
}

