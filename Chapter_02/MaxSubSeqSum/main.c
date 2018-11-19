#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define _TIME_INIT clock_t tic = 0;
#define _TIME_START tic = clock();
#define _TIME_END printf("TIME USE: %lu ticks\n", clock() - tic);

#define OUTPUT_ARRAY 0

#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct result
{
  int maxSum;
  int left;
  int right;
} group;

void output(const int[], int);

group maxSubSeqSum_1(const int[], int);     // O(N^3)
group maxSubSeqSum_2(const int[], int);     // O(N^2)
int maxSubSeqSum_3(const int[], int);       // O(N*logN)
static int maxSub_3(const int[], int, int); // Start point of above
group maxSubSeqSum_4(const int[], int);     // O(N), online algorithm
void showRes(const int[], int, group);


void output(const int A[], int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("%3d\t", i);
  }
  printf("\n---------------------------------\n");
  for (int i = 0; i < N; i++)
  {
    printf("%3d\t", A[i]);
  }
  printf("\n");
}

group maxSubSeqSum_1(const int A[], int N)
{
  int thisSum = 0;
  group ans = {0, 0, 0};
  for (int i = 0; i < N; i++)
  {
    for (int j = i; j < N; j++)
    {
      thisSum = 0;
      /* most waste time part,
       * this block make O(N^2) to O(N^3),
       * but is useless */
      for (int k = i; k <= j; k++)
      {
        thisSum += A[k];
      }
      if (thisSum > ans.maxSum)
      {
        ans.maxSum = thisSum;
        ans.left = i;
        ans.right = j;
      }
    }
  }
  return ans;
}

group maxSubSeqSum_2(const int A[], int N)
{
  int thisSum = 0;
  group ans = {0, 0, 0};
  for (int i = 0; i < N; i++)
  {
    thisSum = 0;
    for (int j = i; j < N; j++)
    {
      thisSum += A[j];
      if (thisSum > ans.maxSum)
      {
        ans.maxSum = thisSum;
        ans.left = i;
        ans.right = j;
      }
    }
  }
  return ans;
}

/*
 * Alg.3:
 * for array A, we spilt it equally to two part,
 * e.g A = [2,-3,1,-5,-3,7,-5,9]
 * left part is [2,-3,1,-5]
 * right part is [-3,7,-5,9]
 * the goal sub must be involved in these three situation:
 * 1. sub in left part => [-3,1,-5]
 * 2. sub in right part => [7,-5,9]
 * 3. sub cross the middle border => [-5,-3,7]
 */

static int maxSub_3(const int A[], int left, int right)
{
  if (left == right)
  {
    if (A[left] > 0)
    {
      return A[left];
    }
    else
      return 0;
  }

  int center = (left + right) / 2;
  int maxLeftSum = maxSub_3(A, left, center);
  int maxRightSum = maxSub_3(A, center + 1, right);

  int maxLeftBorderSum = 0;
  int leftBorderSum = 0;
  for (int i = center; i >= left; i--)
  {
    leftBorderSum += A[i];
    if (leftBorderSum > maxLeftBorderSum)
    {
      maxLeftBorderSum = leftBorderSum;
    }
  }

  int maxRightBorderSum = 0;
  int rightBorderSum = 0;
  for (int i = center + 1; i <= right; i++)
  {
    rightBorderSum += A[i];
    if (rightBorderSum > maxRightBorderSum)
    {
      maxRightBorderSum = rightBorderSum;
    }
  }

  return max(max(maxLeftSum, maxRightSum), maxLeftBorderSum + maxRightBorderSum);
}

int maxSubSeqSum_3(const int A[], int N)
{
  return maxSub_3(A, 0, N - 1);
}

group maxSubSeqSum_4(const int A[], int N)
{
  int thisSum = 0;
  group ans = {0, 0, 0};
  for (int i = 0; i < N; i++)
  {
    thisSum += A[i];
    if (thisSum < 0)
    {
      thisSum = 0;
      ans.left = i + 1;
      ans.right = i + 1;
    }
    if (thisSum > ans.maxSum)
    {
      ans.maxSum = thisSum;
      ans.right = i;
    }
  }
  return ans;
}

void showRes(const int A[], int N, group ans)
{
  if (OUTPUT_ARRAY)
  {
    output(A, N);
  }
  printf("\tMax Sub Sequence is From %d to %d\n", ans.left, ans.right);
  printf("\tMax Sum is %d\n\n", ans.maxSum);
}

int *make_rand(int size)
{
  srand((unsigned int) time(NULL));
  int *rnd = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++)
  {
    rnd[i] = rand() % 200 - 100;
  }
  return rnd;
}

int main()
{
  _TIME_INIT
  int size = 2000;
  int *arr = make_rand(size);
  group ans;
  printf("Problem size: %d\n", size);

  printf("Method.01\n");
  _TIME_START
  ans = maxSubSeqSum_1(arr, size);
  _TIME_END
  showRes(arr, size, ans);

  printf("Method.02\n");
  _TIME_START
  ans = maxSubSeqSum_2(arr, size);
  _TIME_END
  showRes(arr, size, ans);

  printf("Method.03\n");
  _TIME_START
  int res = maxSubSeqSum_3(arr, size);
  _TIME_END
  printf("\tMax Sum is %d\n", res);

  printf("\nMethod.04\n");
  _TIME_START
  ans = maxSubSeqSum_4(arr, size);
  _TIME_END
  showRes(arr, size, ans);

  return 0;
}