#include <stdlib.h>
#include <stdio.h>

#include "tree_tranversal.h"
#include "queue_idx.h"

struct Node
{
  int Element;
  Postion Left;
  Postion Right;
};

Tree MakeEmpty(Tree T)
{
  if (T != NULL)
  {
    MakeEmpty(T->Left);
    MakeEmpty(T->Right);
    free(T);
    T = NULL;
  }
  return T;
}

Tree NewNode(int X)
{
  Postion Tmp = malloc(sizeof(struct Node));
  Tmp->Element = X;
  Tmp->Right = Tmp->Left = NULL;
  return Tmp;
}

void PreOrder(Tree T)
{
  if (T != NULL)
  {
    printf("%d ", T->Element);
    PreOrder(T->Left);
    PreOrder(T->Right);
  }
}

void InOrder(Tree T)
{
  if (T != NULL)
  {
    InOrder(T->Left);
    printf("%d ", T->Element);
    InOrder(T->Right);
  }
}

void PostOrder(Tree T)
{
  if (T != NULL)
  {
    PostOrder(T->Left);
    PostOrder(T->Right);
    printf("%d ", T->Element);
  }
}

void LevelOrder(Tree T)
{
  Queue Q = NewQueue();
  InitQueue(Q);
  EnQueue(Q, T);
  Postion Tmp = NULL;
  while (!IsEmpty(Q))
  {
    Tmp = DeQueue(Q);
    printf("%d ", Tmp->Element);
    if (Tmp->Left != NULL) EnQueue(Q, Tmp->Left);
    if (Tmp->Right != NULL) EnQueue(Q, Tmp->Right);
  }
}

Tree MakeTree()
{
  Tree T = NULL;
  T = NewNode(6);
  T->Left = NewNode(5);
  T->Right = NewNode(15);
  T->Right->Left = NewNode(7);
  T->Right->Left->Right = NewNode(14);
  T->Right->Right = NewNode(16);
  return T;
}
