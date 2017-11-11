#include "td2.h"

unsigned* primeFactorsA(unsigned *count, unsigned number){
    printf("number: %d\nprime factor:",number);
    unsigned* result = malloc(sizeof(unsigned));
    int primeNumber=2;
    *count = 0;
    while(number > 1){
        if (number%primeNumber == 0){
            ++*count;
            result = realloc(result,sizeof(unsigned)* ((*count)));
            result[*count-1] = primeNumber;
            number = number/primeNumber;
        }
        else{
                ++primeNumber;
                while(!isPrime(primeNumber)) ++primeNumber;
        }
    }
    printf("\n");
    return result;
}

void printList(unsigned* list, unsigned length){
    printf("[");
    for(unsigned i=0; i< length; ++i){
        printf("%d,",*(list+1));
    }
    printf("]\n");
}


bool isPrime(unsigned number){
    bool result = true;
    for(unsigned i=2; i<number; ++i){
        if (number%i == 0) {
            result = false;
        }
    }
    return result;
}
