#include <stdio.h>
#include "fatal.h"
#include "doubly_list.h"

int main()
{
  DoublyList newList = NULL;
  DoublyList Tail = NULL;
  Position P;
  Tail = newList = initList(newList);
  for (int i = 1; i <= 10; i++)
  {
    Tail = insertAfter(i, newList, Tail);
  }

  printList(newList);

  printf("Is [10] the TAIL ? [ %d ]\n", isLast(Tail, newList));

  printf("What's the value of HEADER? [ %d ]\n", retrieve(header(newList)));

  P = forward_n(header(newList), 5);
  printf("What's the value of 5th element? [ %d ]\n", retrieve(P));

  deleteByPtr(P, newList);
  printf("After delete 5th element:\n");
  printList(newList);

  P = forward_n(header(newList), 5);
  printf("What's the value of 5th element? [ %d ]\n", retrieve(P));

  printf("Insert [69] before that:\n");
  P = insertBefore(69, newList, P);
  printList(newList);

  printf("Where's the element [8]? [ %d ]\n", retrieve(find(8, newList)));

  printf("Delete element 7\n");
  deleteByValue(7, newList);
  printList(newList);

  P = last(newList);
  printf("What's the value of the last element? [%d]\n", retrieve(P));

  deleteByPtr(P, newList);
  P = NULL;
  printList(newList);

  P = forward(find(69, newList));
  printf("What's the element after [69]? [ %d ]\n", retrieve(P));

  P = backward(find(69, newList));
  printf("What's the element before [69]? [ %d ]\n", retrieve(P));

  P = backward_n(last(newList), length(newList) - 1);
  printf("Get 1st element using the tail [ %d ]\n", retrieve(P));

  return 0;
}

/*
 * ---[Print]---
 * 1->2->3->4->5->6->7->8->9->10
 * -------------
 * Is [10] the TAIL ? [ 1 ]
 * What's the value of HEADER? [ -1 ]
 * What's the value of 5th element? [ 5 ]
 * After delete 5th element:
 * ---[Print]---
 * 1->2->3->4->6->7->8->9->10
 * -------------
 * What's the value of 5th element? [ 6 ]
 * Insert [69] before that:
 * ---[Print]---
 * 1->2->3->4->69->6->7->8->9->10
 * -------------
 * Where's the element [8]? [ 8 ]
 * Delete element 7
 * ---[Print]---
 * 1->2->3->4->69->6->8->9->10
 * -------------
 * What's the value of the last element? [10]
 * ---[Print]---
 * 1->2->3->4->69->6->8->9
 * -------------
 * What's the element after [69]? [ 6 ]
 * What's the element before [69]? [ 4 ]
 * Get 1st element using the tail [ 1 ]
 *
 */