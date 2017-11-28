#ifndef HEADER_HPP
#define HEADER_HPP

#include "random.hpp"
#include <array>
#include <iostream>
#include <iomanip>

void randomIncrement(unsigned value, std::array<unsigned,10> &ar);

void printArray(std::array<unsigned,10> ar);

void printStat(std::array<unsigned,10> ar);


#endif // HEADER_HPP
