#include <stdio.h>
#include "List_IDX.h"

int main()
{
    InitListIDX();
    Position tmp;
    List list = NewList();
    tmp = list;
    for (int i = 1; i <= 5; i++)
    {
        tmp = Insert(i, list, tmp);
    }
    printf("data\n");
    PrintList(list);
    printf("delete element 3:\n");
    Delete(3, list);
    PrintList(list);
    tmp = First(list);
    printf("first element: [ %d ]\n", Retrieve(tmp));
    printf("insert 666 after 4:\n");
    tmp = Find(4, list);
    Insert(666, list, tmp);
    PrintList(list);
    printf("list 2 share same store space with list 1:\n");
    List list2 = NewList();
    tmp = list2;
    for (int i = 15; i >= 10; i--)
    {
        Insert(i, list2, tmp);
        tmp = CursorSpace[tmp].Next;
    }
    PrintList(list2);
    PrintList(list);
    ShowStoreSpace();
    return 0;
}