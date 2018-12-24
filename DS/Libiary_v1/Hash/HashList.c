#include "HashList.h"
#include <stdio.h>
#include <stdlib.h>

HList InitHList(HList L)
{
    if (L != NULL)
    {
        DeleteHList(L);
    }
    L = malloc(sizeof(struct HLNode));
    if (L == NULL)
    {
        Fatal("[ERROR] Out of space!!\n");
    }
    L->Next = NULL;
    L->Element = 0;
    return L;
}

Bool HLIsEmpty(HList L)
{
    return L->Next == NULL;
}

Bool HLIsLast(HLPosition P, HList L)
{
    return P->Next == NULL;
}

HLPosition HLFind(HEleType X, HList L, Comparator cmp)
{
    HLPosition P;
    P = L->Next;
    while (P != NULL && cmp(P->Element, X) != 0)
    {
        P = P->Next;
    }
    return P;
}

void HLDeleteByValue(HEleType X, HList L, Comparator cmp)
{
    HLPosition P, target;
    P = HLFindPreviousByValue(X, L, cmp);
    if (!HLIsLast(P, L))
    {
        target = P->Next;
        P->Next = target->Next;
        free(target);
    }
}

HLPosition HLFindPreviousByValue(HEleType X, HList L, Comparator cmp)
{
    HLPosition P;
    P = L;
    while (P->Next != NULL && cmp(P->Next->Element, X) != 0)
    {
        P = P->Next;
    }
    return P;
}

HLPosition HLInsertAfter(HEleType X, HList L, HLPosition P)
{
    HLPosition target;
    target = malloc(sizeof(struct HLNode));
    if (target == NULL)
    {
        Fatal("[ERROR] Out of space!!\n");
    }
    target->Element = X;
    target->Next = P->Next;
    P->Next = target;
    return target;
}

void DeleteHList(HList L)
{
    HLPosition P, Tmp;
    P = L->Next;
    L->Next = NULL;
    while (P != NULL)
    {
        Tmp = P->Next;
        // free(P->Element);
        free(P);
        P = Tmp;
    }
}

HLPosition HLHeader(HList L)
{
    if (L == NULL)
    {
        Fatal("[ERROR] Request for a NULL, cannot get Header\n");
    }
    return L;
}

HLPosition HLFirstElement(HList L)
{
    if (L == NULL)
    {
        Fatal("[ERROR] Request for a NULL, cannot get first\n");
    }
    return L->Next;
}

HEleType HLRetrieve(HLPosition P)
{
    HEleType X = 0;
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

HLPosition HLAdvance(HLPosition P)
{
    if (P == NULL)
    {
        Fatal("[ERROR] Request for a NULL, cannot perform Advance\n");
    }
    return P->Next;
}

void PrintHList(HList L, char* title, char* link)
{
    // char* s = StrConcat("Print: ", title);
    // AlignPrint(GetConsoleWidth(), '-', s);
    // free(s);
    HLPosition P;
    P = L->Next;
    while (P != NULL)
    {
        printf("[%s]", P->Element);
        P = P->Next;
        if (P != NULL)
        {
            printf("%s", link);
        }
    }
    printf("\n");
    // AlignPrint(GetConsoleWidth(), '-', "END");
}

int HLLength(HList L)
{
    if (L == NULL)
        return 0;
    int count = 0;
    HLPosition tmp = HLFirstElement(L);
    while (tmp != NULL)
    {
        ++count;
        tmp = tmp->Next;
    }
    return count;
}
