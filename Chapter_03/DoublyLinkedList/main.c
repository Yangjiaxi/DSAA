#include <stdio.h>
#include "fatal.h"
#include "doubly_list.h"

int main()
{
  DoublyList new_list = NULL;
  DoublyList tail = NULL;
  Position P;
  tail = new_list = InitList(new_list);
  for (int i = 1; i <= 10; i++)
  {
    tail = InsertAfter(i, new_list, tail);
  }

  PrintList(new_list);

  printf("Is [10] the TAIL ? [ %d ]\n", IsLast(tail, new_list));

  printf("What's the value of HEADER? [ %d ]\n", Retrieve(Header(new_list)));

  P = Forward_n(Header(new_list), 5);
  printf("What's the value of 5th element? [ %d ]\n", Retrieve(P));

  DeleteByPtr(P, new_list);
  printf("After delete 5th element:\n");
  PrintList(new_list);

  P = Forward_n(Header(new_list), 5);
  printf("What's the value of 5th element? [ %d ]\n", Retrieve(P));

  printf("Insert [69] before that:\n");
  InsertBefore(69, new_list, P);
  PrintList(new_list);

  printf("Where's the element [8]? [ %d ]\n", Retrieve(Find(8, new_list)));

  printf("Delete element 7\n");
  DeleteByValue(7, new_list);
  PrintList(new_list);

  P = Last(new_list);
  printf("What's the value of the Last element? [%d]\n", Retrieve(P));

  DeleteByPtr(P, new_list);
  PrintList(new_list);

  P = Forward(Find(69, new_list));
  printf("What's the element after [69]? [ %d ]\n", Retrieve(P));

  P = Backward(Find(69, new_list));
  printf("What's the element before [69]? [ %d ]\n", Retrieve(P));

  P = Backward_n(Last(new_list), Length(new_list) - 1);
  printf("Get 1st element using the tail [ %d ]\n", Retrieve(P));

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
 * What's the value of the Last element? [10]
 * ---[Print]---
 * 1->2->3->4->69->6->8->9
 * -------------
 * What's the element after [69]? [ 6 ]
 * What's the element before [69]? [ 4 ]
 * Get 1st element using the tail [ 1 ]
 *
 */