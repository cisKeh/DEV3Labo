#include "dllist.h"


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





    return 0;
}
