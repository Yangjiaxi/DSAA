#include <stdio.h>
#include <time.h>
#include "utils.c"

#define N 1476

double f[1500];

double fib(int n)
{
    if (f[n])
    {
        return f[n];
    }
    else
    {
        f[n] = fib(n - 1) + fib(n - 2);
        return f[n];
    }
}

int main()
{
    _TIME_INIT
    _TIME_START
    f[0] = 0;
    f[1] = f[2] = 1;
    printf("%.0lf\n", fib(N));
    _TIME_END

    _TIME_START
    double a, b, t;
    a = 1;
    b = 1;
    for (int i = 3; i <= N; i++)
    {
        t = b;
        b = a + b;
        a = t;
    }
    printf("fib(%d) = \n%.0lf\n", N, b);
    _TIME_END
    return 0;
}