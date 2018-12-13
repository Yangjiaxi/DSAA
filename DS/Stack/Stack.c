#include "Stack.h"

Stack InitStack(Stack S)
{
    return InitList(S);
}

void Push(SElementType X, Stack S)
{
    LInsertAfter(X, S, S);
}

SElementType Pop(Stack S)
{
    SPosition P = LFirstElement(S);
    SElementType X = LRetrieve(P);
    LDeleteByPtr(P, S);
    return X;
}

SElementType Top(Stack S)
{
    return LRetrieve(LFirstElement(S));
}

SElementType Peek(Stack S)
{
    return Top(S);
}

Bool IsStackEmpty(Stack S)
{
    return LIsEmpty(S);
}

void DeleteStack(Stack S)
{
    DeleteList(S);
}

void PrintStack(Stack S)
{
    PrintList(S, "Stack", " ");
}