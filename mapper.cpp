#include <iostream>
#include "functions.h"

//!
//! \brief main - entry point of average and dispersion calculation, map stage app
//!

int main()
{
    std::cout << "map stage of big data average/dispersion calculation" << std::endl;

    std::string line;
    static const int CalcParamPositionIndex {10};

    while (std::getline(std::cin, line))
        try {
            std::cout << splitAndTake(line, ',', CalcParamPositionIndex) << std::endl;
        } catch (std::exception &e) {
            std::cout << "unexpected input: " + std::string(e.what()) << std::endl;
        }

    return 0;
}
