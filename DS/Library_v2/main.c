#include <stdio.h>
#include "List.h"
#include "Utils.h"

int main()
{
    LinkedList list = NewLinkedList();
    for (int i = 1; i <= 10; i++)
    {
        list->insertAfter(list, i, list->header(list));
    }
    list->printList(list, "Linked List", "->");
    LPosition cur = list->find(list, 5);
    list->deleteByPointer(list, cur);
    list->printList(list, "Linked List", "->");
    return 0;
}