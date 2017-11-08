#include "dlnode.h"

struct DLNode* newDLN(value_t value) {
    struct DLNode* node = malloc(sizeof(struct DLNode));
    if(node != NULL) {
        node->previous = NULL;
        node->next = NULL;
        node->value = value;
    }
    else errno = EDLNMEMORYFAIL;
    return node;
};

void deleteDLN(struct DLNode* * adpDLN){
    free(*adpDLN);
    *adpDLN = NULL;
}

struct DLNode * getPreviousDLN(const struct DLNode *pDLN){
    return pDLN->previous;
}

struct DLNode* getNextDLN(const struct DLNode *pDLN){
    return pDLN->next;
}

value_t getValueDLN(const struct DLNode* pDLN){
    return pDLN->value;
}

void setPreviousDLN(struct DLNode* pDLN, struct DLNode* pNewPrevious){
    pDLN->previous = pNewPrevious;
    pDLN->previous->next = pDLN;
}

void setNextDLN(struct DLNode *pDLN, struct DLNode *pNewNext) {
    pDLN->next = pNewNext;
    pDLN->next->previous = pDLN;
}

struct DLNode * forwardDLN(struct DLNode *pDLN, int value) {
    struct DLNode * result = pDLN;
    while(value != 0){
        if (result == NULL) {
            value = 0;
        }
        else if (value < 0){
            result = result -> previous;
            ++value;
        }
        else if(value > 0){
            result = result -> next;
            --value;
        }
    }
    return result;
}

struct DLNode * backDLN(struct DLNode *pDLN, int value) {
    return forwardDLN(pDLN, -value);
}
