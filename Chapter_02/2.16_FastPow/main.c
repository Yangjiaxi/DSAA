#include <stdio.h>

int cnt = 0;

long long FastPow(int a, int b) // compute a^b
{
  long long res = 1;
  long long base = a;
  while (b)
  {
    if (b % 2)
    {
      res *= base;
      cnt++;
    }
    b >>= 1;
    base *= base;
    cnt++;
  }
  printf("Total : %d\n", cnt);
  return res;
}

int main()
{
  int a = -3;
  int b = 10;
  printf("%d^%d = %lld\n", a, b, FastPow(a, b));
  return 0;
}

//-3^10 = 59049