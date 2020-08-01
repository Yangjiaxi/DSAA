#include <stdio.h>
#include "AvlTree/AvlTree.h"
#include "Utils/Utils.h"

int main()
{
    AvlTree avl = MakeEmpty(NULL);
    for (int i = 1; i <= 15; i++)
    {
        int a = GetRandomNumber(0, 100);
        printf("Insert %d\n", a);
        avl = AvlInsert(a, avl);
        // TreePlot(avl, "%03d", 3);
    }
    TreePlot(avl, "%03d", 3);
    avl = MakeEmpty(avl);
    return 0;
}