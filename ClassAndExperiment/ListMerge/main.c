#include <stdio.h>
#include "list_ptr.h"

List MergeTwoList(List A, List B)
{
    List Res = NULL;
    Res = InitList(Res);
    Position P1 = FirstElement(A);
    Position P2 = FirstElement(B);
    Position Pres = Header(Res);
    int Tmp;
    while (P1 && P2)
    {
        if (Retrieve(P1) < Retrieve(P2))
        {
            Tmp = Retrieve(P1);
            P1 = Advance(P1);
        }
        else if (Retrieve(P1) > Retrieve(P2))
        {
            Tmp = Retrieve(P2);
            P2 = Advance(P2);
        }
        else
        {
            Tmp = Retrieve(P1);
            P1 = Advance(P1);
            P2 = Advance(P2);
        }
        InsertAfter(Tmp, Res, Pres);
        Pres = Advance(Pres);
    }
    while (P1)
    {
        InsertAfter(Retrieve(P1), Res, Pres);
        Pres = Advance(Pres);
        P1 = Advance(P1);
    }
    while (P2)
    {
        InsertAfter(Retrieve(P2), Res, Pres);
        Pres = Advance(Pres);
        P2 = Advance(P2);
    }
    return Res;
}

List MergeThreeList(List A, List B, List C)
{
    List Res = MergeTwoList(A, B);
    return MergeTwoList(Res, C);
}

int main()
{
    List list1 = NULL;
    list1 = InitList(list1);
    List list2 = NULL;
    list2 = InitList(list2);
    List list3 = NULL;
    list3 = InitList(list3);

    Position tmp;

    tmp = list1;
    tmp = InsertAfter(1, list1, tmp);
    tmp = InsertAfter(4, list1, tmp);
    tmp = InsertAfter(10, list1, tmp);
    tmp = InsertAfter(35, list1, tmp);
    tmp = InsertAfter(100, list1, tmp);

    tmp = list2;
    tmp = InsertAfter(5, list2, tmp);
    tmp = InsertAfter(15, list2, tmp);
    tmp = InsertAfter(40, list2, tmp);
    tmp = InsertAfter(50, list2, tmp);

    tmp = list3;
    tmp = InsertAfter(13, list3, tmp);
    tmp = InsertAfter(36, list3, tmp);
    tmp = InsertAfter(54, list3, tmp);
    tmp = InsertAfter(96700, list3, tmp);

    List res = MergeThreeList(list1, list2, list3);

    PrintList(res);

    return 0;
}
