#ifndef TRANVERSALOFTREE_TREE_H
#define TRANVERSALOFTREE_TREE_H

typedef struct Node *Postion;
typedef struct Node *Tree;

struct Node
{
  int Element;
  Postion Left;
  Postion Right;
};

Tree MakeEmpty(Tree T);

Tree NewNode(int X);

void PreOrder(Tree T);

void InOrder(Tree T);

void PostOrder(Tree T);

void LevelOrder(Tree T);

#endif //TRANVERSALOFTREE_TREE_H
