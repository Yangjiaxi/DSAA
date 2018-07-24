#include <stdio.h>
#include "list_ptr.h"

void findAndOut(int X, list L)
{
  position P = find(X, L);
  if (P != NULL)
  {
    printf("element [ %d ] found!, %d\n", X, retrieve(P));
  }
  else
  {
    printf("element [ %d ] do not exist!\n", X);
  }
}

int main()
{
  list L = NULL;
  L = initList(L);
  printf("Is Empty ? [ %d ]\n", isEmpty(L));
  position P = L;
  for (int i = 1; i <= 10; i++)
  {
    P = insertAfter(i, L, P);
  }
  printList(L);
  printf("Is Empty ? [ %d ]\n", isEmpty(L));
  printf("Value of header: %d\n", retrieve(header(L)));
  printf("Value of first element: %d\n", retrieve(firstElement(L)));
  printf("Value of second element: %d\n", retrieve(advance(firstElement(L))));
  printf("Value of 5-th element: %d\n", retrieve(advance_n(header(L), 5)));
  findAndOut(5, L);
  findAndOut(11, L);
  deleteByValue(5, L);
  printList(L);
  findAndOut(5, L);
  P = advance_n(L, 5);
  printf("Value of 5-th element: %d\n", retrieve(P));
  P = find(9, L);
  deleteByPtr(P, L);
  printList(L);
  printf("Find tail: [ %d ]\n", isLast(advance_n(L, length(L)), L));
  printf("List length: %d\n", length(L));
  return 0;
}