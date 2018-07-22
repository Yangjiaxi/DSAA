/*
 * THIS ALGORITHM IS DEFINITELY WRONG!!!
 * DO NOT USE!!!
 */

#include <stdio.h>
#include <limits.h>

int minSubSeqPosSum(const int A[], int N)
{
  int minSum = INT_MAX;
  int thisSum = 0;
  for (int i = 0; i < N; i++)
  {
    thisSum += A[i];
    if (thisSum < minSum && thisSum > 0)
    {
      minSum = thisSum;
    }
    else if (thisSum < 0)
    {
      thisSum = 0;
    }
  }
  return minSum;
}

int main()
{
  int A[8] = {4, -1, 5, -2, -1, 2, 6, -2};
  for (int i = 0; i < 8; i++)
  {
    printf("%d\t", A[i]);
  }
  printf("\n");
  printf("%d", minSubSeqPosSum(A, 8));
  return 0;
}