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

DoublyList initList(DoublyList L)
{
  if (L != NULL)
  {
    deleteList(L);
  }
  L = malloc(sizeof(struct Node));
  if (L == NULL)
  {
    fatal("[ERROR] Out of Space!\n");
  }
  else
  {
    L->next = NULL;
    L->prev = NULL;
    L->element = -1;
  }
  return L;
}

void deleteList(DoublyList L)
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

int isEmpty(DoublyList L)
{
  return L->next == NULL;
}

int isFirst(Position P, DoublyList L)
{
  return L->next == P;
}

int isLast(Position P, DoublyList L)
{
  return P->next == NULL;
}

Position find(int X, DoublyList L)
{
  Position P;
  P = L->next;
  while (P != NULL && P->element != X)
  {
    P = P->next;
  }
  return P;
}

void deleteByValue(int X, DoublyList L)
{
  Position P;
  P = find(X, L);
  deleteByPtr(P, L);
}

void deleteByPtr(Position P, DoublyList L)
{
  P->prev->next = P->next;
  if (!isLast(P, L))
  {
    P->next->prev = P->prev;
  }
  P->next = NULL;
  P->prev = NULL;
  free(P);
}

Position insertAfter(int X, DoublyList L, Position P)
{
  Position newbee = NULL;
  newbee = malloc(sizeof(struct Node));
  if (newbee == NULL)
  {
    fatal("[ERROR] Out of space!\n");
  }
  else
  {
    newbee->element = X;
    newbee->prev = P;
    newbee->next = P->next;
    if (!isLast(P, L))
    {
      P->next->prev = newbee;
    }
    P->next = newbee;
  }
  return newbee;
}

Position insertBefore(int X, DoublyList L, Position P)
{
  if (P->prev != NULL)
  {
    return insertAfter(X, L, P->prev);
  }
  else
  {
    fatal("[ERROR] Out of range!\n");
    return NULL;
  }
}

Position header(DoublyList L)
{
  return L;
}

Position last(DoublyList L)
{
  return forward_n(L, length(L));
}


Position first(DoublyList L)
{
  return L->next;
}

Position forward(Position P)
{
  return P->next;
}

Position forward_n(Position P, int n)
{
  Position target = P;
  for (int i = 1; i <= n; i++)
  {
    target = target->next;
  }
  return target;
}

Position backward(Position P)
{
  return P->prev;
}

Position backward_n(Position P, int n)
{
  Position target = P;
  for (int i = 1; i <= n; i++)
  {
    target = target->prev;
  }
  return target;
}

int retrieve(Position P)
{
  return P->element;
}

int length(DoublyList L)
{
  int count = 0;
  Position tmp = first(L);
  while (tmp != NULL)
  {
    ++count;
    tmp = tmp->next;
  }
  return count;
}

void printList(DoublyList L)
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

