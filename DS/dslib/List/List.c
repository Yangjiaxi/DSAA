#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void InitList(LinkedList LL)
{
    if (LL->self != NULL)
    {
        DeleteList(LL);
    }
    LL->self = malloc(sizeof(struct LNode));
    if (LL->self == NULL)
    {
        Fatal("[ERROR] Out of space!!\n");
    }
    LL->self->Next = NULL;
    LL->self->Element = -1;
    // Header is not for restore data, the value of this Node
    // is always -1
}

Bool LIsEmpty(LinkedList LL)
{
    return LL->self->Next == NULL;
}

Bool LIsLast(LinkedList LL, LPosition P)
{
    return P->Next == NULL;
}

LPosition LFind(LinkedList LL, LElementType X)
{
    LPosition P;
    P = LL->self->Next;
    while (P != NULL && P->Element != X)
    {
        P = P->Next;
    }
    return P;
}

void LDeleteByValue(LinkedList LL, LElementType X)
{
    LPosition P, target;
    P = LFindPreviousByValue(LL, X);
    if (!LIsLast(LL, P))
    {
        target = P->Next;
        P->Next = target->Next;
        free(target);
    }
}

void LDeleteByPtr(LinkedList LL, LPosition P)
{
    LPosition prev;
    prev = LFindPreviousByPtr(LL, P);
    if (!LIsLast(LL, prev))
    {
        prev->Next = P->Next;
        free(P);
    }
}

LPosition LFindPreviousByValue(LinkedList LL, LElementType X)
{
    LPosition P;
    P = LL->self;
    while (P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }
    return P;
}

LPosition LFindPreviousByPtr(LinkedList LL, LPosition P)
{
    LPosition tmp;
    tmp = LL->self;
    while (tmp->Next != NULL && tmp->Next != P)
    {
        tmp = tmp->Next;
    }
    return tmp;
}

// InsertAfter X after P in L
LPosition LInsertAfter(LinkedList LL, LElementType X, LPosition P)
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

void DeleteList(LinkedList LL)
{
    LPosition P, Tmp;
    P = LL->self->Next;
    LL->self->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

LPosition LHeader(LinkedList LL)
{
    if (LL->self == NULL)
    {
        Fatal("[ERROR] Request for a NULL, cannot get Header\n");
    }
    return LL->self;
}

LPosition LFirstElement(LinkedList LL)
{
    if (LL->self == NULL)
    {
        Fatal("[ERROR] Request for a NULL, cannot get first\n");
    }
    return LL->self->Next;
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

void PrintList(LinkedList LL, char *title, char *link)
{
    char *s = StrConcat("Print: ", title);
    AlignPrint(GetConsoleWidth(), '-', s);
    free(s);
    LPosition P;
    P = LL->self->Next;
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

int LLength(LinkedList LL)
{
    int count = 0;
    LPosition tmp = LFirstElement(LL);
    while (tmp != NULL)
    {
        ++count;
        tmp = tmp->Next;
    }
    return count;
}
