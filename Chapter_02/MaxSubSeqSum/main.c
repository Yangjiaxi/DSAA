#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

void output(const int[], int);

typedef struct result group;

group maxSubSeqSum_1(const int[], int); // O(N^3)

group maxSubSeqSum_2(const int[], int); // O(N^2)

int maxSubSeqSum_3(const int[], int); // O(N*logN)
static int maxSub_3(const int[], int, int);

group maxSubSeqSum_4(const int[], int); // O(N), online algorithm

void showRes(const int[], int, group);

typedef struct result
{
  int maxSum;
  int left;
  int right;
} group;

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
  output(A, N);
  printf("\tMax Sub Sequence is From %d to %d\n", ans.left, ans.right);
  printf("\tMax Sum is %d\n\n", ans.maxSum);
}

int main()
{
  int NA = 6;
  int A[6] = {-2, 11, -4, 13, -5, -2};
  int NB = 8;
  int B[8] = {4, -3, 5, -2, -1, 2, 6, -2};
  group ans;

  printf("Method.01\n");
  ans = maxSubSeqSum_1(A, NA);
  showRes(A, NA, ans);

  printf("Method.02\n");
  ans = maxSubSeqSum_2(B, NB);
  showRes(B, NB, ans);

  printf("Method.03\n");
  int res = maxSubSeqSum_3(B, NB);
  printf("\tMax Sum is %d\n", res);

  printf("\nMethod.04\n");
  ans = maxSubSeqSum_4(A, NA);
  showRes(A, NA, ans);
  ans = maxSubSeqSum_4(B, NB);
  showRes(B, NB, ans);
  int NC = 3;
  int C[8] = {-1, -2, -3};
  ans = maxSubSeqSum_4(C, NC);
  showRes(C, NC, ans);

  return 0;
}

/*
Method.01
  0	  1	  2	  3	  4	  5
---------------------------------
 -2	 11	 -4	 13	 -5	 -2
	Max Sub Sequence is From 1 to 3
	Max Sum is 20

Method.02
  0	  1	  2	  3	  4	  5	  6	  7
---------------------------------
  4	 -3	  5	 -2	 -1	  2	  6	 -2
	Max Sub Sequence is From 0 to 6
	Max Sum is 11

Method.03
	Max Sum is 11

Method.04
  0	  1	  2	  3	  4	  5
---------------------------------
 -2	 11	 -4	 13	 -5	 -2
	Max Sub Sequence is From 1 to 3
	Max Sum is 20

  0	  1	  2	  3	  4	  5	  6	  7
---------------------------------
  4	 -3	  5	 -2	 -1	  2	  6	 -2
	Max Sub Sequence is From 0 to 6
	Max Sum is 11

  0	  1	  2
---------------------------------
 -1	 -2	 -3
	Max Sub Sequence is From 3 to 3
	Max Sum is 0

 */