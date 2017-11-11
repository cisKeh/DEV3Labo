#ifndef TD2_H
#define TD2_H

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

struct PrimeFactor{
    unsigned value;
    unsigned multiplicity;
};
struct PrimeFactorization{
    unsigned number;
    unsigned count;
    struct PrimeFactor* primeFactors;
};

bool isPrime(unsigned number);
unsigned* primeFactorsA(unsigned* count, unsigned number);
unsigned* primeFactorsB(unsigned * * factor, unsigned * * multiplicity, unsigned number);
struct PrimeFactor* primeFactorsC(unsigned* count, unsigned number);
void primeFactorsD(struct PrimeFactorization* pf);
void printList(unsigned* list, unsigned length);

#endif // TD2_H
