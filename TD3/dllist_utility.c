#include "dllist_utility.h"

value_t* to_arrayDLL(size_t *size, const struct DLList *pDLL){

    value_t* firstElem = NULL;

    if(isEmptyDLL(pDLL)){
        *size = 0;
    }
    else{
        firstElem = malloc(sizeof(value_t));
        if(firstElem == NULL) errno = EDLLMEMORYFAIL;
        else{
            struct DLNode* current = getHeadDLL(pDLL);
            *size = 0;
            while(current != NULL && errno != EDLLMEMORYFAIL){
                firstElem = realloc(firstElem, sizeof(value_t)*(*size+1));
                if(firstElem == NULL) errno = EDLLMEMORYFAIL;
                else{
                    *(firstElem+*size) = getValueDLN(current);
                    current = getNextDLN(current);
                    ++*size;
                }
            }
        }
    }
    return firstElem;
}

value_t* to_array_reverseDLL(size_t *size, const struct DLList *pDLL){
    value_t* firstElem = NULL;

    if(isEmptyDLL(pDLL)){
        *size = 0;
    }
    else{
        firstElem = malloc(sizeof(value_t));
        if(firstElem == NULL) errno = EDLLMEMORYFAIL;
        else{
            struct DLNode* current = getTailDLL(pDLL);
            *size = 0;
            while(current != NULL && errno != EDLLMEMORYFAIL){
                firstElem = realloc(firstElem, sizeof(value_t)*(*size+1));
                if(firstElem == NULL) errno = EDLLMEMORYFAIL;
                else{
                    *(firstElem+*size) = getValueDLN(current);
                    current = getPreviousDLN(current);
                    ++*size;
                }
            }
        }
    }
    return firstElem;
}


struct DLList* reverseDLL(const struct DLList *pDLL){
    struct DLList* reversed = newDLL();
    struct DLNode* current = getTailDLL(pDLL);
    insertHeadDLL(reversed,getValueDLN(current));
    struct DLNode* currentRev = getHeadDLL(reversed);
//    printf("next: %d\n",getValueDLN(getPreviousDLN(current)));

    while(getPreviousDLN(current)!= NULL){
        current = getPreviousDLN(current);
        insertTailDLL(reversed, getValueDLN(current));
//        printf("currentRev:%d\n",getValueDLN(currentRev));

        currentRev = getNextDLN(currentRev);
    }
    return reversed;
}


void printArray(const size_t* size,const value_t *firstElem){
    printf("array: [");
    for(size_t i=0; i<*size; ++i){
        printf("%d,",*(firstElem+i));
    }
    printf("]\n");
}
