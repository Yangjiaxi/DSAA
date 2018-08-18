#include <stdio.h>

#include "queue_idx.h"
#include "tree_tranversal.h"

int main()
{
  Tree T1 = NULL;
  T1 = MakeTree();

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