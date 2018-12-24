#include <stdio.h>
#include "AvlTree/AvlTree.h"
#include "BST/BST.h"
#include "DoublyList/DoublyList.h"
#include "Hash/Hash.h"
#include "Hash/HashCode.h"
#include "List/List.h"
#include "Queue/Queue.h"
#include "Stack/Stack.h"
#include "Utils/Utils.h"

int main()
{
    printf("%s\n", "1. List");
    List list = InitList(NULL);
    LPosition cur = LHeader(list);
    for (int i = 1; i <= 5; i++)
        cur = LInsertAfter(i, list, cur);
    PrintList(list, "list", "->");
    DeleteList(list);

    printf("\n%s\n", "2. Doubly Linked List");
    DoublyList dlist = InitDoublyList(NULL);
    for (int i = 2; i <= 10; i += 2)
        DLInsertAfter(i, dlist, DLTail(dlist));
    for (int i = 9; i >= 1; i -= 2)
        DLInsertBefore(i, dlist, DLHead(dlist));
    PrintDLList(dlist, "Doubly Linked List", "<->");
    DeleteDoublyList(dlist);

    printf("\n%s\n", "3. Queue");
    Queue queue = InitQueue(NULL);
    for (int i = 9; i >= 1; i -= 2)
        InsertLast(i, queue);
    for (int i = 2; i <= 10; i += 2)
        InsertFirst(i, queue);
    PrintQueue(queue);
    DeleteQueue(queue);

    printf("\n%s\n", "4. Stack");
    Stack stack = InitStack(NULL);
    for (int i = 1; i <= 10; i++)
        Push(i, stack);
    PrintStack(stack);
    DeleteStack(stack);

    printf("\n%s\n", "5. Tree");
    Tree tree = InPreBuild("ABC", "BAC");
    TreePlot(tree, "<%c>", 3);
    tree = MakeEmpty(tree);

    printf("\n%s\n", "6. BST");
    SearchTree bst = MakeEmpty(NULL);
    for (int i = 1; i <= 20; i++)
        bst = BSTInsert(GetRandomNumber(0, 100), bst);
    TreePlot(bst, "%03d", 3);
    bst = MakeEmpty(bst);

    printf("\n%s\n", "7. AvlTree");
    AvlTree avl = MakeEmpty(NULL);
    for (int i = 1; i <= 20; i++)
        avl = AvlInsert(GetRandomNumber(0, 100), avl);
    TreePlot(avl, "%03d", 3);
    avl = MakeEmpty(avl);

    printf("\n%s\n", "8. Hash");
    HashTable hash = NewHashTable(BKDRHash);
    for (int i = 1; i <= 100; i++)
    {
        hash = HashInsert(RandomString(GetRandomNumber(2, 65)), hash);
    }
    HashScore(hash);

    DestoryTable(hash);
    return 0;
}