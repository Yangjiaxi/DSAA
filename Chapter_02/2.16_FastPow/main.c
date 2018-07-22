#include <stdio.h>

long long FastPow(int a, int b) // compute a^b
{
  long long res = 1;
  long long base = a;
  while (b)
  {
    if(b % 2)
    {
      res *= base;
    }
    b >>= 1;
    base *= base;
  }
  return res;
}

int main()
{
  int a = -3;
  int b = 10;
  printf("%d^%d = %lld", a, b, FastPow(a, b));
  return 0;
}

//-3^10 = 59049