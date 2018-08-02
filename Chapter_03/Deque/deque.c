#include "deque.h"
#include <stdlib.h>
#include <stdio.h>

struct _Node
{
  int element;
  Position next;
  Position prev;
};

struct _Deque
{
  Position front;
  Position rear;
};

void InitDeque(Deque D)
{
  D->front = NULL;
  D->rear = NULL;
}

int IsEmpty(Deque D)
{
  return (D->front == NULL) || (D->rear == NULL);
}

void Push(int X, Deque D)
{
  Position newbee = malloc(sizeof(Node));
  newbee->element = X;
  newbee->next = NULL;
  newbee->prev = D->rear;
  if (IsEmpty(D))
  {
    D->front = newbee;
  }
  else
  {
    D->rear->next = newbee;
  }
  D->rear = newbee;
}

int Pop(Deque D)
{
  Position tmp = D->front;
  D->front = D->front->next;
  if (IsEmpty(D))
  {
    D->rear = NULL;
  }
  else
  {
    D->front->prev = NULL;
  }
  int X = tmp->element;
  free(tmp);
  return X;
}

void Inject(int X, Deque D)
{
  Position newbee = malloc(sizeof(Node));
  newbee->element = X;
  newbee->prev = NULL;
  newbee->next = D->front;
  if (IsEmpty(D))
  {
    D->rear = newbee;
  }
  else
  {
    D->front->prev = newbee;
  }
  D->front = newbee;
}

int Eject(Deque D)
{
  Position tmp = D->rear;
  D->rear = D->rear->prev;
  if (IsEmpty(D))
  {
    D->front = NULL;
  }
  else
  {
    D->rear->next = NULL;
  }
  int X = tmp->element;
  free(tmp);
  return X;
}

int Front(Deque D)
{
  return D->front->element;
}

int Back(Deque D)
{
  return D->rear->element;
}

void DeleteDeque(Deque D)
{
  Position P = D->front;
  Position tmp;
  while (P != NULL)
  {
    tmp = P->next;
    free(P);
    P = tmp;
  }
  InitDeque(D);
}

void PrintDeque(Deque D)
{
  printf("----[Print]----\n");
  Position P = D->front;
  while (P != NULL)
  {
    printf("%d ", P->element);
    P = P->next;
  }
  printf("\n---------------\n");
}