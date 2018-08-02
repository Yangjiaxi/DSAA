#include <stdio.h>

#include "stack.h"
int main()
{
  Stack new_stack = NULL;
  new_stack = InitStack(new_stack);

  for (int i = 1; i <= 10; i++)
  {
    Push(i, new_stack);
  }
  PrintStack(new_stack);

  printf("Pop: [ %d ]\n", Pop(new_stack));
  PrintStack(new_stack);

  printf("Top : [ %d ]\n", Top(new_stack));

  printf("Push [99]\n");
  Push(99, new_stack);
  PrintStack(new_stack);

  printf("Pop 9 elements\n");
  for (int i = 1; i <= 9; i++)
  {
    Pop(new_stack);
  }
  printf("Is empty? [ %d ]\n", IsEmpty(new_stack));

  printf("Pop 1 element\n");
  Pop(new_stack);
  printf("Is empty? [ %d ]\n", IsEmpty(new_stack));

  return 0;
}
/*
 * ---[Print]---
 * 10->9->8->7->6->5->4->3->2->1
 * -------------
 * Pop: [ 10 ]
 * ---[Print]---
 * 9->8->7->6->5->4->3->2->1
 * -------------
 * Top : [ 9 ]
 * Push [99]
 * ---[Print]---
 * 99->9->8->7->6->5->4->3->2->1
 * -------------
 * Pop 9 elements
 * Is empty? [ 0 ]
 * Pop 1 element
 * Is empty? [ 1 ]
 */