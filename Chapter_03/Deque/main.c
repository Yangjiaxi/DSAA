#include <stdio.h>
#include "deque.h"

int main()
{
  Deque D;
  InitDeque(D);
  printf("Eject: ");
  for (int i = 13; i >= 7; i -= 2)
  {
    Inject(i, D);
  }
  PrintDeque(D);
  printf("Front: [ %d ]\n", Front(D));
  printf("Back: [ %d ]\n", Back(D));
  printf("Pop: [ %d ]\n", Pop(D));
  printf("Eject: [ %d ]\n", Eject(D));
  PrintDeque(D);
  printf("Push: 1 2 3 4 5\n");
  for (int i = 1; i <= 5; i++)
  {
    Push(i, D);
  }
  PrintDeque(D);
  printf("Front: [ %d ]\n", Front(D));
  printf("Back: [ %d ]\n", Back(D));
  printf("Pop: [ %d ]\n", Pop(D));
  PrintDeque(D);
  printf("Front: [ %d ]\n", Front(D));
  printf("Delete Deque:\n");
  DeleteDeque(D);
  printf("Is Deque Empty? [ %d ]\n", IsEmpty(D));
  printf("Push: [69]\n");
  Push(69, D);
  printf("Is Deque Empty? [ %d ]\n", IsEmpty(D));
  PrintDeque(D);
  printf("Inject: [213]\n");
  Inject(213, D);
  PrintDeque(D);
  return 0;
}