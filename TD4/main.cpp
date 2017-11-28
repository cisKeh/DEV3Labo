#include <iostream>
#include "header.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    /*EXO 4.9*/
    std::array<unsigned,10> ar {0,0,0,0,0,0,0,0,0,0};

    std::cout << std::setw(7) << 1 << " incrementations: ";
    ++ar.at(nvs::random_value<unsigned>(0,9));
    printArray(ar);

    randomIncrement(10, ar);
    std::cout << std::setw(7) << 10 << " incrementations: ";
    printArray(ar);
    printStat(ar);

    randomIncrement(100, ar);
    std::cout << std::setw(7) << 100 << " incrementations: ";
    printArray(ar);
    printStat(ar);

    randomIncrement(10000, ar);
    std::cout << std::setw(7) << 10000 << " incrementations: ";
    printArray(ar);
    printStat(ar);

    randomIncrement(1000000, ar);
    std::cout << std::setw(7) << 1000000 << " incrementations: ";
    printArray(ar);
    printStat(ar);

    return 0;
}
