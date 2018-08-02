#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

struct _Node
{
  int element;
  Position next;
};

struct _Queue
{
  Position front;
  Position rear;
};

void InitQueue(Queue Q)
{
  Q->front = NULL;
  Q->rear = NULL;
}

int IsEmpty(Queue Q)
{
  return Q->front == NULL;
}

void Push(int X, Queue Q)
{
  Position newbee = malloc(sizeof(Node));
  newbee->element = X;
  newbee->next = NULL;
  if (IsEmpty(Q))
  {
    Q->front = newbee;
  }
  else
  {
    Q->rear->next = newbee;
  }
  Q->rear = newbee;
}

int Front(Queue Q)
{
  return Q->front->element;
}

int Back(Queue Q)
{
  return Q->rear->element;
}

int Pop(Queue Q)
{
  Position tmp = Q->front;
  Q->front = Q->front->next;
  if (IsEmpty(Q))
  {
    Q->rear = NULL;
  }
  int X = tmp->element;
  free(tmp);
  return X;
}

void DeleteQueue(Queue Q)
{
  Position P = Q->front;
  Position tmp;
  while (P != NULL)
  {
    tmp = P->next;
    free(P);
    P = tmp;
  }
  InitQueue(Q);
}

void PrintQueue(Queue Q)
{
  printf("----[Print]----\n");
  Position P = Q->front;
  while (P != NULL)
  {
    printf("%d ", P->element);
    P = P->next;
  }
  printf("\n---------------\n");
}