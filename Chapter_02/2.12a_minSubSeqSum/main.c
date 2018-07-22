#include <stdio.h>

int minSubSeqSum(const int A[], int N)
{
  int thisSum = 0;
  int minSum = 0;
  for(int i = 0; i < N; i++)
  {
    thisSum += A[i];
    if(thisSum < minSum)
    {
      minSum = thisSum;
    }
    else if(thisSum > 0)
      thisSum = 0;
  }
  return minSum;
}

int main()
{
  int A[8] = {12, -2, 1, -4, 3, -5, -12, 10};
  for(int i = 0; i < 8; i++)
    printf("%d\t", A[i]);
  int res = minSubSeqSum(A, 8);
  printf("\nMin sum is : %d\n", res);
  return 0;
}