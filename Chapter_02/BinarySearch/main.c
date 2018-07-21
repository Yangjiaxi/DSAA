#include <stdio.h>
#include <stdlib.h>

#define NN 10

int cmp(const void *, const void *);

int binarySearch(const int[], int, int);

int cmp(const void *a, const void *b)
{
  return (*(int *) a - *(int *) b);
}

// find key in a strictly increasing integer array
int binarySearch(const int A[], int N, int key)
{
  int low = 0;
  int high = N - 1;
  int mid;
  while (low <= high)
  {
    mid = (high - low) / 2 + low;
    if (A[mid] < key)
    {
      low = mid + 1;
    }
    else if (A[mid] > key)
    {
      high = mid - 1;
    }
    else
    {
      return mid;
    }
  }
  return -1;
}

int main()
{
  int A[NN] = {84, 5, 40, 89, 52, 29, 20, 25, 44, 77};
  int key = A[NN / 2 - 1];
  for (int i = 0; i < NN; i++)
  {
    printf("%2d\t", i);
  }
  printf("\n--------------------------------------------------\n");
  for (int i = 0; i < NN; i++)
  {
    printf("%2d\t", A[i]);
  }
  printf("\n");
  qsort(A, NN, sizeof(int), cmp);
  for (int i = 0; i < NN; i++)
  {
    printf("%2d\t", A[i]);
  }
  printf("\nThe key to find is [%d]\n", key);
  int pos = binarySearch(A, NN, key);
  printf("Found at %d\n", pos);
  return 0;
}

/*
 *
 * 0	 1	 2	 3	 4	 5	 6	 7	 8	 9
  --------------------------------------------------
  84	 5	40	89	52	29	20	25	44	77
   5	20	25	29	40	44	52	77	84	89
  The key to find is [52]
  Found at 6
 */