#ifndef DLLIST_UTILITY_H
#define DLLIST_UTILITY_H

#include "dllist.h"

enum SortingMethod{
    SORT_BY_CHANGING_LINK,
    SORT_BY_CHANGING_VALUE
};

value_t* to_arrayDLL(size_t * size, const struct DLList* pDLL);
value_t * to_array_reverseDLL(size_t* size, const struct DLList* pDLL);
struct DLList* reverseDLL(const struct DLList* pDLL);
void sortDLL(struct DLList* pDLL, int (*comp)(value_t,value_t),enum SortingMethod sm);
struct DLList* mergeDLL(const struct DLList* pDLL_l, const struct DLList* pDLL_r, int (*comp)(value_t, value_t));
void printArray(const size_t* size,const value_t* firstElem);

#endif // DLLIST_UTILITY_H
