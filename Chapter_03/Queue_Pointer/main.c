#include <stdio.h>
#include "queue.h"

int main()
{
  Queue Q;
  InitQueue(Q);
  printf("EnQueue: 1 2 3 4 5\n");
  for (int i = 1; i <= 5; i++)
  {
    EnQueue(i, Q);
  }
  PrintQueue(Q);
  printf("Front: [ %d ]\n", Front(Q));
  printf("Back: [ %d ]\n", Back(Q));
  printf("DeQueue: [ %d ]\n", DeQueue(Q));
  PrintQueue(Q);
  printf("Front: [ %d ]\n", Front(Q));
  printf("Delete Queue:\n");
  DeleteQueue(Q);
  printf("Is Queue Empty? [ %d ]\n", IsEmpty(Q));
  printf("EnQueue: [69]\n");
  EnQueue(69, Q);
  printf("Is Queue Empty? [ %d ]\n", IsEmpty(Q));
  PrintQueue(Q);
  return 0;
}
/*
 * EnQueue: 1 2 3 4 5
 * ----[Print]----
 * 1 2 3 4 5
 * ---------------
 * Front: [ 1 ]
 * Back: [ 5 ]
 * DeQueue: [ 1 ]
 * ----[Print]----
 * 2 3 4 5
 * ---------------
 * Front: [ 2 ]
 * Delete Queue:
 * Is Queue Empty? [ 1 ]
 * EnQueue: [69]
 * Is Queue Empty? [ 0 ]
 * ----[Print]----
 * 69
 * ---------------
 */