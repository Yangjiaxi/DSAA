//
// Created by VanYang on 2018/8/2.
//

// Doubly Linked List

#include <stdlib.h>
#include <stdio.h>
#include "doubly_list.h"
#include "fatal.h"

struct Node
{
  int element;
  Position next;
  Position prev;
};

DoublyList InitList(DoublyList L)
{
  if (L != NULL)
  {
    DeleteList(L);
  }
  L = malloc(sizeof(struct Node));
  if (L == NULL)
  {
    Fatal("[ERROR] Out of Space!\n");
  }
  else
  {
    L->next = NULL;
    L->prev = NULL;
    L->element = -1;
  }
  return L;
}

void DeleteList(DoublyList L)
{
  Position p, tmp;
  p = L->next;
  L->next = NULL;
  L->prev = NULL;
  while (p != NULL)
  {
    tmp = p->next;
    free(p);
    p = tmp;
  }
}

int IsEmpty(DoublyList L)
{
  return L->next == NULL;
}

int IsFirst(Position P, DoublyList L)
{
  return L->next == P;
}

int IsLast(Position P, DoublyList L)
{
  return P->next == NULL;
}

Position Find(int X, DoublyList L)
{
  Position P;
  P = L->next;
  while (P != NULL && P->element != X)
  {
    P = P->next;
  }
  return P;
}

void DeleteByValue(int X, DoublyList L)
{
  Position P;
  P = Find(X, L);
  DeleteByPtr(P, L);
}

void DeleteByPtr(Position P, DoublyList L)
{
  P->prev->next = P->next;
  if (!IsLast(P, L))
  {
    P->next->prev = P->prev;
  }
  P->next = NULL;
  P->prev = NULL;
  free(P);
}

Position InsertAfter(int X, DoublyList L, Position P)
{
  Position newbee = NULL;
  newbee = malloc(sizeof(struct Node));
  if (newbee == NULL)
  {
    Fatal("[ERROR] Out of space!\n");
  }
  else
  {
    newbee->element = X;
    newbee->prev = P;
    newbee->next = P->next;
    if (!IsLast(P, L))
    {
      P->next->prev = newbee;
    }
    P->next = newbee;
  }
  return newbee;
}

Position InsertBefore(int X, DoublyList L, Position P)
{
  if (P->prev != NULL)
  {
    return InsertAfter(X, L, P->prev);
  }
  else
  {
    Fatal("[ERROR] Out of range!\n");
    return NULL;
  }
}

Position Header(DoublyList L)
{
  return L;
}

Position Last(DoublyList L)
{
  return Forward_n(L, Length(L));
}


Position First(DoublyList L)
{
  return L->next;
}

Position Forward(Position P)
{
  return P->next;
}

Position Forward_n(Position P, int n)
{
  Position target = P;
  for (int i = 1; i <= n; i++)
  {
    target = target->next;
  }
  return target;
}

Position Backward(Position P)
{
  return P->prev;
}

Position Backward_n(Position P, int n)
{
  Position target = P;
  for (int i = 1; i <= n; i++)
  {
    target = target->prev;
  }
  return target;
}

int Retrieve(Position P)
{
  return P->element;
}

int Length(DoublyList L)
{
  int count = 0;
  Position tmp = First(L);
  while (tmp != NULL)
  {
    ++count;
    tmp = tmp->next;
  }
  return count;
}

void PrintList(DoublyList L)
{
  printf("---[Print]---\n");
  Position P;
  P = L->next;
  while (P != NULL)
  {
    printf("%d", P->element);
    P = P->next;
    if (P != NULL)
    {
      printf("->");
    }
  }
  printf("\n-------------\n");
}

