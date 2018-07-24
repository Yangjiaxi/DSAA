#ifndef LIST_POINTER_LIST_H
#define LIST_POINTER_LIST_H

struct node;
typedef struct node *ptrToNode;
typedef ptrToNode list;
typedef ptrToNode position;

list initList(list L);

int isEmpty(list L);

int isLast(position P, list L);

position find(int X, list L);

void deleteByValue(int X, list L);

void deleteByPtr(position X, list L);

position findPreviousByValue(int X, list L);

position findPreviousByPtr(position P, list L);

position insertAfter(int X, list L, position P);

void deleteList(list L);

position header(list L);

position firstElement(list L);

position advance(position P);

position advance_n(position P, int n);

int retrieve(position P);

int length(list L);

void printList(list L);

#endif //LIST_POINTER_LIST_H