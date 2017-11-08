#include <stdio.h>
#include "AvlTree.h"

int main()
{
  AvlTree AT = NULL;
  MakeEmpty(AT);
  AT = Insert(11, AT);
  AT = Insert(9, AT);
  AT = Insert(12, AT);
  AT = Insert(8, AT);
  AT = Insert(10, AT);


  printf("\nInorder:");
  InorderTreeWalk(AT);
  printf("\nPreOrder:");
  PreTreeWalk(AT);
  printf("\nPostOrder:");
  PostTreeWalk(AT);

  printf("\n\nDel Ele [12]\n");
  AT = Delete(12, AT);
  printf("\nInorder:");
  InorderTreeWalk(AT);
  printf("\nPreOrder:");
  PreTreeWalk(AT);
  printf("\nPostOrder:");
  PostTreeWalk(AT);

  printf("\n\nIns Ele [7]\n");
  AT = Insert(7, AT);
  printf("\nInorder:");
  InorderTreeWalk(AT);
  printf("\nPreOrder:");
  PreTreeWalk(AT);
  printf("\nPostOrder:");
  PostTreeWalk(AT);

  MakeEmpty(AT);
  return 0;
}