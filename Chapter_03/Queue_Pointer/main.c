#include <stdio.h>
#include "queue.h"

int main()
{
  Queue Q;
  InitQueue(Q);
  printf("Push: 1 2 3 4 5\n");
  for (int i = 1; i <= 5; i++)
  {
    Push(i, Q);
  }
  PrintQueue(Q);
  printf("Front: [ %d ]\n", Front(Q));
  printf("Back: [ %d ]\n", Back(Q));
  printf("Pop: [ %d ]\n", Pop(Q));
  PrintQueue(Q);
  printf("Front: [ %d ]\n", Front(Q));
  printf("Delete Queue:\n");
  DeleteQueue(Q);
  printf("Is Queue Empty? [ %d ]\n", IsEmpty(Q));
  printf("Push: [69]\n");
  Push(69, Q);
  printf("Is Queue Empty? [ %d ]\n", IsEmpty(Q));
  PrintQueue(Q);
  return 0;
}