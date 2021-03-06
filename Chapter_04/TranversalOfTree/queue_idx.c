#include "queue_idx.h"
#include <stdio.h>
#include <stdlib.h>

struct _Queue
{
  Postion Data[MAX_QUEUE_SIZE];
  int front;
  int rear;
  int size;
};

Queue NewQueue()
{
  return malloc(sizeof(struct _Queue));
}

void InitQueue(Queue Q)
{
  for (int i = 0; i < MAX_QUEUE_SIZE; i++)
  {
    Q->Data[i] = NULL;
  }
  Q->front = Q->size = 0;
  Q->rear = -1;
}

void EnQueue(Queue Q, Postion X)
{
  Q->size++;
  Q->rear++;
  Q->Data[Q->rear] = X;
}

Postion DeQueue(Queue Q)
{
  Postion Tmp = Q->Data[Q->front];
  Q->size--;
  Q->front++;
  return Tmp;
}

int IsEmpty(Queue Q)
{
  return Q->size == 0;
}
