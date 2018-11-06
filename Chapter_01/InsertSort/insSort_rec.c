#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utils.c"

void ins(int arr[], int size)
{
    int key = arr[size - 1];
    for (int j = size - 2; j >= 0 && arr[j] > key; j--)
    {
        arr[j + 1] = arr[j];
        arr[j] = key;
    }
}

void sort_rec(int arr[], int size)
{
    if (size > 0)
    {
        sort_rec(arr, size - 1);
        ins(arr, size);
    }
}

void sort_nor(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        for (int j = i - 1; j >= 0 && arr[j] > key; j--)
        {
            arr[j + 1] = arr[j];
            arr[j] = key;
        }
    }
}

int *rand_arr(int size)
{
    srand(time(NULL));
    int *a = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 10000;
    }
    return a;
}

int *cpy(int arr[], int size)
{
    int *b = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        b[i] = arr[i];
    }
    return b;
}

int main()
{
    _TIME_INIT
    int n = 50000;
    int *a = rand_arr(n);
    int *b = cpy(a, n);

    _TIME_START
    sort_rec(a, n);
    _TIME_END

    _TIME_START
    sort_nor(b, n);
    _TIME_END

    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", b[i]);
    // }
    // printf("\n");
    return 0;
}