#include <stdio.h>
#include "td2.h"
int main(int argc, char *argv[])
{
    printf("Hello World!\n");
    unsigned* count;
    unsigned* result;
    count = malloc(sizeof(unsigned));
    printf("====================================\n");
    result = primeFactorsA(count,84);
    printf("count:%d\nprime factor:", *count);
    for(unsigned i=0;i<*count;++i){
        printf("%d,",*(result+i));
    }
    printf("\n");
    printf("====================================\n");
    unsigned* factor;
    unsigned* multiplicity;
    unsigned* nbElem = primeFactorsB(&factor, &multiplicity, 84);
    printf("factor:");
    for(unsigned i=0;i<*nbElem;++i){
        printf("%d,",*(factor+i));
    }
    printf("\nmultiplicity:");
    for(unsigned i=0;i<*nbElem;++i){
        printf("%d,",*(multiplicity+i));
    }
    printf("\n");

    free(result);

    return 0;
}
