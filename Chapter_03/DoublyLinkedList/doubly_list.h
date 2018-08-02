//
// Created by VanYang on 2018/8/2.
//

#ifndef DOUBLYLINKEDLIST_DOUBLY_LIST_H
#define DOUBLYLINKEDLIST_DOUBLY_LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode DoublyList;  //ADT::DoublyList
typedef PtrToNode Position;

DoublyList initList(DoublyList L);

void deleteList(DoublyList L);

int isEmpty(DoublyList L);

int isFirst(Position P, DoublyList L);

int isLast(Position P, DoublyList L);

Position find(int X, DoublyList L);

void deleteByValue(int X, DoublyList L);

void deleteByPtr(Position P, DoublyList L);

Position insertAfter(int X, DoublyList L, Position P);

Position insertBefore(int X, DoublyList L, Position P);

Position header(DoublyList L);

Position last(DoublyList L);

Position first(DoublyList L);

Position forward(Position P);

Position forward_n(Position P, int n);

Position backward(Position P);

Position backward_n(Position P, int n);

int retrieve(Position P);

int length(DoublyList L);

void printList(DoublyList L);

#endif //DOUBLYLINKEDLIST_DOUBLY_LIST_H
