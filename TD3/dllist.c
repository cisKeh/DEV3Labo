#include "dllist.h"


struct DLList* newDLL(){
    struct DLList* list = malloc(sizeof(struct DLList));
    if (list != NULL){
        list->head = NULL;
        list->tail = NULL;
    }
    else errno = EDLLMEMORYFAIL;
    return list;
}

void deleteDLL(struct DLList ** adpDLL){
    clearDLL(*adpDLL);
    free(*adpDLL);
    adpDLL = NULL;
}

void clearDLL(struct DLList * pDLL){
    struct DLNode* current = pDLL->head;
    struct DLNode* toDelete = current;
    while(current != pDLL->tail){
        current = current->next;
        deleteDLN(&toDelete);
        toDelete = current;
    }
    deleteDLL(&toDelete);
    pDLL->head = NULL;
    pDLL->tail = NULL;
}

struct DLNode * getHeadDLL(const struct DLList *pDLL){
    return pDLL->head;
}
value_t getHeadValueDLL(const struct DLList *pDLL){
    return getValueDLN(getHeadDLL(pDLL));
}
struct DLNode * getTailDLL(const struct DLList *pDLL){
    return pDLL->tail;
}
value_t getTailValueDLL(const struct DLList *pDLL){
    return getValueDLN(getTailDLL(pDLL));
}

bool isEmptyDLL(const struct DLList *pDLL){
    return (pDLL->head == NULL || pDLL->tail == NULL)? true : false;
}

size_t getSizeDLL(const struct DLList *pDLL){
    size_t count = 1;
    if(pDLL->head != NULL){
        struct DLNode* current = pDLL->head;
        while(current != pDLL->tail){
            current = getNextDLN(current);
            ++count;
        }
    }
    return count;
}

struct DLNode* insertHeadDLL(struct DLList *pDLL, value_t value){
    struct DLNode* newNode = newDLN(value);
    if (errno == EDLNMEMORYFAIL) errno = EDLLMEMORYFAIL;
    else{
        if(pDLL->head == NULL){
            pDLL->head = newNode;
            pDLL->tail = newNode;
        }
        else{
            newNode->next = pDLL->head;
            pDLL->head->previous = newNode;
            pDLL->head = newNode;
        }
    }
    return pDLL->head;
}

struct DLNode* removeHeadDLL(struct DLList *pDLL){
    if(isEmptyDLL(pDLL)) errno = EDLLEMPTY;
    else{
        pDLL->head = pDLL->head->next;
        deleteDLN(&pDLL->head->previous);
        pDLL->head->previous = NULL;
    }
    return (isEmptyDLL(pDLL)? NULL : pDLL->head);
}

struct DLNode* insertTailDLL(struct DLList *pDLL, value_t value){
    struct DLNode* newNode = newDLN(value);
    if (errno == EDLNMEMORYFAIL) errno = EDLLMEMORYFAIL;
    else{
        if(pDLL->head == NULL){
            pDLL->head = newNode;
            pDLL->tail = newNode;
        }
        else{
            newNode->next = pDLL->tail;
            pDLL->tail->next = newNode;
            pDLL->tail = newNode;
        }
    }
    return pDLL->tail;
}

struct DLNode* removeTailDLL(struct DLList *pDLL){
    if(isEmptyDLL(pDLL)) errno = EDLLEMPTY;
    else{
        pDLL->tail = pDLL->tail->previous;
        deleteDLN(&pDLL->tail->next);
        pDLL->tail->next = NULL;
    }
    return (isEmptyDLL(pDLL)? NULL : pDLL->tail);
}


struct DLNode* insertAfterDLL(struct DLList* pDLL,
                              struct DLNode* pDLN,
                              value_t newValue){
    struct DLNode* newNode = newDLN(newValue);
    struct DLNode* current = pDLN;
    if (errno == EDLNMEMORYFAIL) errno = EDLLMEMORYFAIL;
    else{
        bool setted = false;
        current = pDLL->head;
        while(current != pDLL->tail && !setted){
            if(current == pDLN){
                newNode = newDLN(newValue);
                if(current == pDLL->tail) pDLL->tail = newNode;
                newNode->previous = current;
                newNode->next = current->next;
                current->next->previous = newNode;
                current->next = newNode;
                setted = true;
            }
            current = current->next;
        }
    }
    return current;
}

struct DLNode* insertBeforeDLL(struct DLList *pDLL,
                               struct  DLNode *pDLN,
                               value_t newValue){
    struct DLNode* newNode = newDLN(newValue);
    struct DLNode* current = pDLN;
    if (errno == EDLNMEMORYFAIL) errno = EDLLMEMORYFAIL;
    else{
        bool setted = false;
        current = pDLL->tail;
        while(current != pDLL->head && !setted){
            if(current == pDLN){
                newNode = newDLN(newValue);
                if(current == pDLL->head) pDLL->head = newNode;
                newNode->next = current;
                newNode->previous = current->previous;
                current->previous->next = newNode;
                current->previous = newNode;
                setted = true;
            }
            current = current->previous;
        }
    }
    return current;
}


struct DLNode* removeDLL(struct DLList* pDLL, struct DLNode * pDLN){
    if (pDLL != NULL && pDLN != NULL){
        struct DLNode* current = pDLL->head;
        while(current != pDLN) current = current->next;
        if(pDLN == pDLL->head ) pDLL->head = pDLN->next;
        else if(pDLN == pDLL->tail ) pDLL->tail = pDLN->previous;
        /*TODO: is pDLN part of pDLL or can they have a same value ?
         * Do we test by the address of each or with value ?*/

    }
    else if(pDLL != NULL && pDLN == NULL){

    }
    else if(pDLL == NULL && pDLN != NULL){

    }
    else{

    }
}

void printDLL(const struct DLList *pDLL){
    if(pDLL == NULL){
        printf("list is NULL\n");
    }
    else if(pDLL->head != NULL){
        struct DLNode* current = pDLL->head;
        int i = 0;
        while(current != pDLL->tail){
            printf("N°%d value: %d\n",i,current->value);
            current = current->next;
            ++i;
        }
        printf("N°%d value: %d\n",i,current->value);
        printf("size of nodeList:\t%lu\n",getSizeDLL(pDLL));
        printf("get head value:\t%d\n",getHeadValueDLL(pDLL));
        printf("get tail value:\t%d\n",getTailValueDLL(pDLL));
    }
    else printf("********The list is empty*****\n");
}


