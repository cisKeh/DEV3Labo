#include "dllist.h"


int main(int argc, char *argv[])
{
    printf("Hello World!\n");

    /*test DLNode*/

    size_t count = 10;
    struct DLNode* node = newDLN(14);
    struct DLNode* current = node;

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
    printf("size of nodeList:\t%d\n",getSizeDLL(nodeList));
    printf("get head value:\t%d\n",getHeadValueDLL(nodeList));
    printf("get tail value:\t%d\n",getTailValueDLL(nodeList));

    printf("remove head (value:%d)\t",removeHeadDLL(nodeList)->value);
    printf("size of nodeList:\t%d\n",getSizeDLL(nodeList));
    current = nodeList->head;
    int i = 0;
    while(current != nodeList->tail){
        printf("N°%d value: %d\n",i,current->value);
        current = current->next;
        ++i;
    }

    printf("remove tail (value:%d)\t",removeTailDLL(nodeList)->value);
    printf("size of nodeList:\t%d\n",getSizeDLL(nodeList));
    current = nodeList->head;
    i = 0;
    while(current != nodeList->tail){
        printf("N°%d value: %d\n",i,current->value);
        current = current->next;
        ++i;
    }

    /*why head->previous has node and tail->next also*/
    printf("insert node after head->next (value:%d)\t",insertAfterDLL(nodeList, nodeList->head,18)->value);
    printf("size of nodeList:\t%d\n",getSizeDLL(nodeList));
    current = nodeList->head;
    i = 0;
    while(current != nodeList->tail){
        printf("N°%d value: %d\n",i,current->value);
        current = current->next;
        ++i;
    }




    return 0;
}
