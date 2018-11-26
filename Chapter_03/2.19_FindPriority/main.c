#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utils.c"

int *rand_arr(int size, int l, int r)
{
    srand(time(NULL));
    int *a = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
        a[i] = rand() % (l - r + 1) + l;
    return a;
}

void out_arr(int *a, int size)
{
    printf("size : %d\n", size);
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int isPriority(int *a, int size, int cdt)
{
    int count = 1;
    for (int i = 0; i < size - 1; i++)
        if (a[i] == cdt)
            count++;
    if (count > size / 2)
        return 1;
    else
        return 0;
}

int checkLast(int *a, int size)
{
    return isPriority(a, size, a[size - 1]);
}

int findPriority_1(int *a, int size)
{
    if (size == 0)
        return -1;
    if (size == 1)
        return a[0];
    int tmp[size];
    int t_size = 0;
    for (int i = 0; i < size; i += 2)
        if (a[i] == a[i + 1])
            tmp[t_size++] = a[i];
    int res = findPriority_1(tmp, t_size);
    if (size % 2 && res == -1 && checkLast(a, size))
        return a[size - 1];
    else if (isPriority(a, size, res))
        return res;
    return -1;
}

int findPriority_2(int *a, int size)
{
    int current = -1;
    int cnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (cnt == 0)
        {
            current = a[i];
            cnt++;
        }
        else
            cnt += (a[i] == current) ? 1 : -1;
    }
    if (isPriority(a, size, current))
        return current;
    return -1;
}

int main()
{
    int n = 10;
    int *a = rand_arr(n, 1, 10);
    // int a[10] = {1, 2, 2, 2, 3, 2, 1, 1, 2, 2};
    // out_arr(a, n);
    printf("ans = %d\n", findPriority_1(a, n));
    printf("ans = %d\n", findPriority_2(a, n));
    return 0;
}