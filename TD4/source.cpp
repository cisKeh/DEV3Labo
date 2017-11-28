#include "header.hpp"


void randomIncrement(unsigned value, std::array<unsigned,10> &ar){
    ar = {0,0,0,0,0,0,0,0,0,0};
    for (unsigned i=0; i< value; ++i)   ++ar.at(nvs::random_value<unsigned>(0,9));
}

void printArray(std::array<unsigned, 10> ar){
    std::cout << "[ ";
    for (unsigned i=0; i<10;++i) std::cout << " " << ar.at(i);
    std::cout << " ]" << std::endl;
}


void printStat(std::array<unsigned, 10> ar){
    double total = 0;
    for (unsigned i = 0; i < 10; ++i) total+= ar.at(i);
    for (unsigned i =0; i< 10; ++i)
        std::cout << "nombre de " << i << " : " << ar.at(i) << " (" << (ar.at(i))/total*100 << "%)"<< std::endl;
    std::cout << "total: " << total << " (" << total/total*100 << "%)" << std::endl;
}
