#include <stdio.h>

void PrintOut(int);

void PrintDigit(int);

void PrintOut(int N)
{
  if (N < 0)
  {
    printf("-");
    PrintOut(0 - N);
  }
  else
  {
    if (N >= 10)
    {
      PrintOut(N / 10);
    }
    PrintDigit(N % 10);
  }
}

void PrintDigit(int N)
{
  printf("%d", N);
}

int main()
{
  PrintOut(-89182);
  return 0;
}