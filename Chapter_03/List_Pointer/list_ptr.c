#include <stdio.h>
#include <stdlib.h>

#include "list_ptr.h"

struct node
{
  int element;
  position next;
};

list initList(list L)
{
  if (L != NULL)
  {
    deleteList(L);
  }
  L = malloc(sizeof(struct node));
  if (L == NULL)
  {
    printf("[ERROR] Out of space!!\n");
    exit(1);
  }
  L->next = NULL;
  L->element = -1; // header is not for restore data, the value of this node is always -1
  return L;
}

int isEmpty(list L)
{
  return L->next == NULL;
}

int isLast(position P, list L)
{
  return P->next == NULL;
}

position find(int X, list L)
{
  position P;
  P = L->next;
  while (P != NULL && P->element != X)
  {
    P = P->next;
  }
  return P;
}

void deleteByValue(int X, list L)
{
  position P, target;
  P = findPreviousByValue(X, L);
  if (!isLast(P, L))
  {
    target = P->next;
    P->next = target->next;
    free(target);
  }
}

void deleteByPtr(position P, list L)
{
  position prev;
  prev = findPreviousByPtr(P, L);
  if (!isLast(prev, L))
  {
    prev->next = P->next;
    free(P);
  }
}

position findPreviousByValue(int X, list L)
{
  position P;
  P = L;
  while (P->next != NULL && P->next->element != X)
  {
    P = P->next;
  }
  return P;
}

position findPreviousByPtr(position P, list L)
{
  position tmp;
  tmp = L;
  while (tmp->next != NULL && tmp->next != P)
  {
    tmp = tmp->next;
  }
  return tmp;
}

// insertAfter X after P in L
position insertAfter(int X, list L, position P)
{
  position target;
  target = malloc(sizeof(struct node));
  if (target == NULL)
  {
    printf("[ERROR] Out of space!!\n");
    exit(1);
  }
  target->element = X;
  target->next = P->next;
  P->next = target;
  return target;
}

void deleteList(list L)
{
  position P, Tmp;
  P = L->next;
  L->next = NULL;
  while (P != NULL)
  {
    Tmp = P->next;
    free(P);
    P = Tmp;
  }
}

position header(list L)
{
  if (L != NULL)
  {
    return L;
  }
  else
  {
    printf("[ERROR] Request for a NULL, cannot get header\n");
    // exit(1);
  }
}

position firstElement(list L)
{
  if (L != NULL)
  {
    return L->next;
  }
  else
  {
    printf("[ERROR] Request for a NULL, cannot get first\n");
    // exit(1);
  }
}

position advance(position P)
{
  if (P != NULL)
  {
    return P->next;
  }
  else
  {
    printf("[ERROR] Request for a NULL, cannot perform advance\n");
    // exit(1);
  }
}

position advance_n(position P, int n)
{
  position Tmp = P;
  for (int i = 0; i < n; i++)
  {
    if (Tmp != NULL)
    {
      Tmp = Tmp->next;
    }
    else
    {
      printf("[ERROR] Out of range, cannot perform advance!\n");
      Tmp = NULL;
      break;
      // exit(1);
    }
  }
  return Tmp;
}

int retrieve(position P)
{
  if (P != NULL)
  {
    return P->element;
  }
  else
  {
    printf("[ERROR] Request for a NULL, cannot retrieve!\n");
    return -1;
    // exit(1);
  }
}

void printList(list L)
{
  printf("---[Print]---\n");
  position P;
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

int length(list L)
{
  int count = 0;
  position tmp = firstElement(L);
  while (tmp != NULL)
  {
    ++count;
    tmp = tmp->next;
  }
  return count;
}
