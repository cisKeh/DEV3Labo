#include "mathesi.h"


unsigned int isPrime(unsigned int number) {
    unsigned int result = number;
    if(number >= 2) {
        for(unsigned int i = 2; i < number; ++i) {
            if(number % i == 0) result = 0;
        }
    }
    return result;
}

bool exo1dot1(unsigned int number) {
    return isPrime(number);

}



void exo1dot2(unsigned int from, unsigned int to) {
    int count = 0;
    printf("Les nombres premiers entre %3d et %3d :\n", from, to);
    for (unsigned int i=from; i < to; ++i) {
        if (count == 10) {
            printf("\n");
            count = 0;
        }
        if (exo1dot1(i)) printf(" %3d",i);
        else printf("   .");
        ++count;
    }
}

void exo1dot3(unsigned int number, bool showPower) {
    unsigned int currentNumber = number;
    unsigned int currentDivider = 2;
    printf("%d = ",number);
    while (currentDivider < currentNumber) {
        if (exo1dot1(currentDivider)) {
            printf("%d*",currentDivider);
            currentNumber /= currentDivider;
// TODO: pas fini!
        }
        else ++currentDivider;

    }
}
