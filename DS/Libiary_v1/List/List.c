#include "List.h"
#include <stdio.h>
#include <stdlib.h>

List InitList(List L)
{
    if (L != NULL)
    {
        DeleteList(L);
    }
    L = malloc(sizeof(struct LNode));
    if (L == NULL)
    {
        Fatal("[ERROR] Out of space!!\n");
    }
    L->Next = NULL;
    L->Element = -1;  // Header is not for restore data, the value of this Node
                      // is always -1
    return L;
}

Bool LIsEmpty(List L)
{
    return L->Next == NULL;
}

Bool LIsLast(LPosition P, List L)
{
    return P->Next == NULL;
}

LPosition LFind(LElementType X, List L)
{
    LPosition P;
    P = L->Next;
    while (P != NULL && P->Element != X)
    {
        P = P->Next;
    }
    return P;
}

void LDeleteByValue(LElementType X, List L)
{
    LPosition P, target;
    P = LFindPreviousByValue(X, L);
    if (!LIsLast(P, L))
    {
        target = P->Next;
        P->Next = target->Next;
        free(target);
    }
}

void LDeleteByPtr(LPosition P, List L)
{
    LPosition prev;
    prev = LFindPreviousByPtr(P, L);
    if (!LIsLast(prev, L))
    {
        prev->Next = P->Next;
        free(P);
    }
}

LPosition LFindPreviousByValue(LElementType X, List L)
{
    LPosition P;
    P = L;
    while (P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }
    return P;
}

LPosition LFindPreviousByPtr(LPosition P, List L)
{
    LPosition tmp;
    tmp = L;
    while (tmp->Next != NULL && tmp->Next != P)
    {
        tmp = tmp->Next;
    }
    return tmp;
}

// InsertAfter X after P in L
LPosition LInsertAfter(LElementType X, List L, LPosition P)
{
    LPosition target;
    target = malloc(sizeof(struct LNode));
    if (target == NULL)
    {
        Fatal("[ERROR] Out of space!!\n");
    }
    target->Element = X;
    target->Next = P->Next;
    P->Next = target;
    return target;
}

void DeleteList(List L)
{
    LPosition P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

LPosition LHeader(List L)
{
    if (L == NULL)
    {
        Fatal("[ERROR] Request for a NULL, cannot get Header\n");
    }
    return L;
}

LPosition LFirstElement(List L)
{
    if (L == NULL)
    {
        Fatal("[ERROR] Request for a NULL, cannot get first\n");
    }
    return L->Next;
}

LPosition LAdvance(LPosition P)
{
    if (P == NULL)
    {
        Fatal("[ERROR] Request for a NULL, cannot perform Advance\n");
    }
    return P->Next;
}

LPosition LAdvance_n(LPosition P, int n)
{
    LPosition Tmp = P;
    for (int i = 0; i < n; i++)
    {
        if (Tmp != NULL)
        {
            Tmp = Tmp->Next;
        }
        else
        {
            Fatal("[ERROR] Out of range, cannot perform Advance!\n");
        }
    }
    return Tmp;
}

LElementType LRetrieve(LPosition P)
{
    LElementType X = -1;
    if (P != NULL)
    {
        X = P->Element;
    }
    else
    {
        Fatal("[ERROR] Request for a NULL, cannot Retrieve!\n");
    }
    return X;
}

void PrintList(List L, char* title, char* link)
{
    char* s = StrConcat("Print: ", title);
    AlignPrint(GetConsoleWidth(), '-', s);
    free(s);
    LPosition P;
    P = L->Next;
    while (P != NULL)
    {
        printf("%d", P->Element);
        P = P->Next;
        if (P != NULL)
        {
            printf("%s", link);
        }
    }
    printf("\n");
    AlignPrint(GetConsoleWidth(), '-', "END");
}

int LLength(List L)
{
    int count = 0;
    LPosition tmp = LFirstElement(L);
    while (tmp != NULL)
    {
        ++count;
        tmp = tmp->Next;
    }
    return count;
}
