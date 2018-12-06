#include <stdio.h>
#include "AvlTree.h"

int main()
{
    AvlTree AT = NULL;
    AT = MakeEmpty(AT);
    // for (int i = 9; i >= 1; i--)
    // {
    //     AT = Insert(i, AT);
    // }
    // 9, 7, 8, 4, 6, 5, 3, 1, 2
    AT = Insert(18, AT);
    AT = Insert(4, AT);
    AT = Insert(12, AT);
    AT = Insert(13, AT);
    AT = Insert(7, AT);
    AT = Insert(27, AT);
    AT = Insert(83, AT);
    AT = Insert(38, AT);
    AT = Insert(24, AT);
    AT = Insert(41, AT);

    printf("\nInorder:");
    InorderTreeWalk(AT);
    printf("\nPreOrder:");
    PreTreeWalk(AT);
    printf("\nPostOrder:");
    PostTreeWalk(AT);

    // printf("\n\nDel Ele [12]\n");
    // AT = Delete(12, AT);
    // printf("\nInorder:");
    // InorderTreeWalk(AT);
    // printf("\nPreOrder:");
    // PreTreeWalk(AT);
    // printf("\nPostOrder:");
    // PostTreeWalk(AT);

    // printf("\n\nIns Ele [7]\n");
    // AT = Insert(7, AT);
    // printf("\nInorder:");
    // InorderTreeWalk(AT);
    // printf("\nPreOrder:");
    // PreTreeWalk(AT);
    // printf("\nPostOrder:");
    // PostTreeWalk(AT);

    MakeEmpty(AT);
    printf("\n");
    return 0;
}