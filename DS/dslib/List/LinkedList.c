#include <stdio.h>
#include <stdlib.h>
#include "List.h"

LinkedList NewLinkedList()
{
    LinkedList res = malloc(sizeof(struct _LinkedList));
    res->isEmpty = LIsEmpty;
    res->isLast = LIsLast;
    res->find = LFind;
    res->deleteByPointer = LDeleteByPtr;
    res->deleteByValue = LDeleteByValue;
    res->insertAfter = LInsertAfter;
    res->removeAll = DeleteList;
    res->header = LHeader;
    res->first = LFirstElement;
    res->size = LLength;
    res->printList = PrintList;
    res->self = NULL;
    InitList(res);
    return res;
}