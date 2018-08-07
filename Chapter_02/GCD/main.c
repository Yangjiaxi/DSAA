#include <stdio.h>

unsigned int GCD(unsigned int a, unsigned int b)
{
  unsigned int rem;
  while (b > 0)
  {
    rem = a % b;
    a = b;
    b = rem;
  }
  return a;
}

unsigned m_GCD(const unsigned int A[], int N)
{
  if (N == 1)
  {
    return A[0];
  }
  else
  {
    return GCD(A[0], m_GCD(&A[1], N - 1));
  }
}

int main()
{
  printf("GCD(24, 36) = %u\n", GCD(24, 36));
  unsigned int A[4] = {15, 24, 318, 300};
  printf("GCD(15, 24, 318, 300) = %u\n", m_GCD(A, 4));
  return 0;
}

/*
 * GCD(24, 36) = 12
 * GCD(15, 24, 318, 300) = 3
 */