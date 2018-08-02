//
// Created by VanYang on 2018/8/2.
//

#ifndef DOUBLYLINKEDLIST_DOUBLY_LIST_H
#define DOUBLYLINKEDLIST_DOUBLY_LIST_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode DoublyList; //ADT::DoublyList
typedef PtrToNode Position;

DoublyList InitList(DoublyList L);

void DeleteList(DoublyList L);

int IsEmpty(DoublyList L);

int IsFirst(Position P, DoublyList L);

int IsLast(Position P, DoublyList L);

Position Find(int X, DoublyList L);

void DeleteByValue(int X, DoublyList L);

void DeleteByPtr(Position P, DoublyList L);

Position InsertAfter(int X, DoublyList L, Position P);

Position InsertBefore(int X, DoublyList L, Position P);

Position Header(DoublyList L);

Position Last(DoublyList L);

Position First(DoublyList L);

Position Forward(Position P);

Position Forward_n(Position P, int n);

Position Backward(Position P);

Position Backward_n(Position P, int n);

int Retrieve(Position P);

int Length(DoublyList L);

void PrintList(DoublyList L);

#endif //DOUBLYLINKEDLIST_DOUBLY_LIST_H
