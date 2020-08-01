#include <stdio.h>
#include "list_ptr.h"

void findAndOut(int X, List L)
{
    Position P = Find(X, L);
    if (P != NULL)
    {
        printf("element [ %d ] found!, %d\n", X, Retrieve(P));
    }
    else
    {
        printf("element [ %d ] do not exist!\n", X);
    }
}

int main()
{
    List new_list = NULL;
    new_list = InitList(new_list);
    printf("Is Empty ? [ %d ]\n", IsEmpty(new_list));
    Position P = new_list;
    for (int i = 1; i <= 10; i++)
    {
        P = InsertAfter(i, new_list, P);
    }
    PrintList(new_list);
    printf("Is Empty ? [ %d ]\n", IsEmpty(new_list));
    printf("Value of Header: %d\n", Retrieve(Header(new_list)));
    printf("Value of first element: %d\n", Retrieve(FirstElement(new_list)));
    printf("Value of second element: %d\n",
           Retrieve(Advance(FirstElement(new_list))));
    printf("Value of 5-th element: %d\n",
           Retrieve(Advance_n(Header(new_list), 5)));
    findAndOut(5, new_list);
    findAndOut(11, new_list);
    DeleteByValue(5, new_list);
    PrintList(new_list);
    findAndOut(5, new_list);
    P = Advance_n(new_list, 5);
    printf("Value of 5-th element: %d\n", Retrieve(P));
    P = Find(9, new_list);
    DeleteByPtr(P, new_list);
    PrintList(new_list);
    printf("Find tail: [ %d ]\n",
           IsLast(Advance_n(new_list, Length(new_list)), new_list));
    printf("List Length: %d\n", Length(new_list));
    return 0;
}