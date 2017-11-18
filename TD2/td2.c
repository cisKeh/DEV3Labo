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

/*PROBLEM: factor and multiplicity number begin at [i+1]*/
unsigned* primeFactorsB(unsigned **factor, unsigned **multiplicity, unsigned number){
    int primeNumber = 2;
    int oldPrimeNumber = 0;
    unsigned* count = malloc(sizeof(unsigned));
    *count = 0;
    unsigned* factorB = malloc(sizeof(unsigned));
    unsigned* multiplicityB = malloc(sizeof(unsigned));
    if(factorB == NULL || multiplicityB == NULL){
        printf("error: primeFactorsB allocation");
        exit(1);
    }
    while (number > 1){
        if(number%primeNumber == 0){
            if(oldPrimeNumber != primeNumber){
                ++*count;
                factorB = realloc(factorB,sizeof(unsigned)*(*count));
                multiplicityB = realloc(multiplicityB,sizeof(unsigned)*(*count));
                *(factorB+*count) = primeNumber;
                *(multiplicityB+*count) = 0;
                oldPrimeNumber = primeNumber;
                number/=primeNumber;
            }
            else{
                ++*(multiplicityB+*count);
                number/=primeNumber;
            }
        }
        else{
            ++primeNumber;
            while(!isPrime(primeNumber)) ++primeNumber;
        }
    }
    *factor = factorB;
    *multiplicity = multiplicityB;
    return count;
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
