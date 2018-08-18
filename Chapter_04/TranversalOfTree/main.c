#include <stdio.h>

#include "queue_idx.h"
#include "tree_tranversal.h"

int main()
{
  Tree T1 = NULL;
  T1 = NewNode(6);
  T1->Left = NewNode(5);
  T1->Right = NewNode(15);
  T1->Right->Left = NewNode(7);
  T1->Right->Left->Right = NewNode(14);
  T1->Right->Right = NewNode(16);

  printf("\nPre Order Tree Traversal:\n");
  PreOrder(T1);
  printf("\nIn Order Tree Traversal:\n");
  InOrder(T1);
  printf("\nPost Order Tree Traversal:\n");
  PostOrder(T1);
  printf("\nLevel Order Tree Traversal:\n");
  LevelOrder(T1);

  MakeEmpty(T1);
  return 0;
}