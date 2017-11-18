#include "dllist_utility.h"


int main(int argc, char *argv[])
{
    printf("Hello World!\n");

    /*test DLNode*/

//    size_t count = 10;
//    struct DLNode* node = newDLN(14);

//    while(count > 0){
//        setNextDLN(current,newDLN(count));
//        current = current->next;
//        --count;
//    }

//    current = node;
//    while(count++ < 10){
//        printf("forward: %d\n",getValueDLN(forwardDLN(current,1)));
//        current = forwardDLN(current,1);
//    }

//    while(count-- > 0){
//        printf("backward: %d\n",getValueDLN(backDLN(current,1)));
//        current = backDLN(current,1);
//    }

//    deleteDLN(node);

    /*test DLList*/
    struct DLList* nodeList = newDLL();

    for(int i = 0; i < 10; ++i){
        insertHeadDLL(nodeList, i);
        printf("new head is %d\n",getHeadValueDLL(nodeList));
    }
    printf("Is nodeList empty:\t");
    printf(isEmptyDLL(nodeList)? "true\n":"false\n");
    printDLL(nodeList);
    printf("====================================\n");
    printf("remove head (value:%d)\n",getHeadValueDLL(nodeList));
    removeHeadDLL(nodeList);
    printDLL(nodeList);
    printf("====================================\n");
    printf("remove tail (value:%d)\n",getTailValueDLL(nodeList));
    removeTailDLL(nodeList);
    printDLL(nodeList);
    printf("====================================\n");
    printf("insert node after head (value:%d)\n",insertAfterDLL(nodeList, nodeList->head,18)->value);
    printDLL(nodeList);
    printf("====================================\n");
    printf("insert node before tail (value:%d)\n",insertBeforeDLL(nodeList, nodeList->tail,23)->value);
    printDLL(nodeList);
    printf("====================================\n");
    printf("remove next head element(value:%d)\n",nodeList->head->next->value);
    removeDLL(nodeList, nodeList->head->next);
    printDLL(nodeList);
    printf("====================================\n");
    printf("remove previous tail element(value:%d)\n",nodeList->tail->previous->value);
    removeDLL(nodeList, nodeList->tail->previous);
    printDLL(nodeList);




    /*test DLList_utility*/
    size_t* size;
    value_t* firstElem;
    struct DLList* reversed;
    printf("====================================\n");
    printf("to_arrayDLL()\n");
    size = malloc(sizeof(size_t));
    firstElem = to_arrayDLL(size,nodeList);
    printArray(size, firstElem);
    printf("====================================\n");
    printf("to_array_reverseDLL()\n");
    size = malloc(sizeof(size_t));
    firstElem = to_array_reverseDLL(size,nodeList);
    printArray(size, firstElem);
    printf("====================================\n");
    printf("reverseDLL()\n");
    reversed = reverseDLL(nodeList);
    printDLL(reversed);

    printf("====================================\n");
    printf("clear list\n");
    clearDLL(nodeList);
    printDLL(nodeList);
    printf("====================================\n");
    printf("delete list\n");
    deleteDLL(&nodeList);
    printf("====================================\n");
    printf("clear reversedlist\n");
    clearDLL(reversed);
    printDLL(reversed);
    printf("====================================\n");
    printf("delete reverselist\n");
    deleteDLL(&reversed);

    return 0;
}
