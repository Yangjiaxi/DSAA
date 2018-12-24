#include "Utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>

void Fatal(const char* info)
{
    fprintf(stderr, "%s\n", info);
    fflush(stderr);
    exit(1);
}

void endl()
{
    printf("\n");
}

char* StrConcat(const char* s1, char* s2)
{
    const size_t len1 = strlen(s1);
    if (!s2)
        s2 = "No Name";
    const size_t len2 = strlen(s2);
    char* result = malloc(len1 + len2 + 1);
    memcpy(result, s1, len1);
    memcpy(result + len1, s2, len2 + 1);
    return result;
}

void AlignPrint(int width, char pad, const char* text)
{
    // printf("\n");
    int t_len = strlen(text) + 4;
    int l = (width - t_len + 1) / 2;
    for (int i = 1; i <= l; i++)
        printf("%c", pad);
    width -= l;
    printf("[ %s ]", text);
    width -= t_len;
    for (int i = 1; i <= width; i++)
        printf("%c", pad);
    printf("\n");
}

int FindChar(const char* str, char ch)
{
    char* res = strchr(str, ch);
    if (res != NULL)
    {
        return res - str;
    }
    else
    {
        return -1;
    }
}

char* StrCopy(const char* str, int size)
{
    char* res = malloc(sizeof(char) * (size + 1));
    strncpy(res, str, size);
    res[size] = '\0';
    return res;
}

int GetConsoleWidth()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    return w.ws_col;
}

int Max(int a, int b)
{
    return a > b ? a : b;
}

int GetRandomNumber(int L, int R)
{
    static unsigned seed = 0;
    seed += 1;
    unsigned r = time(NULL) + seed * seed + 3 * seed;
    srand(r * r);
    return (R - L) * (rand() / (double)(RAND_MAX)) + L;
}

Bool IsPrime(int num)
{
    if (num <= 1)
    {
        return False;
    }
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return False;
        }
    }
    return True;
}

int NextPrime(int num)
{
    if (IsPrime(num))
    {
        return num;
    }
    while (!IsPrime(++num))
        ;
    return num;
}

double ArrayMean(int a[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    return 1.0 * sum / size;
}

double ArrayStd(int a[], int size)
{
    double mean = ArrayMean(a, size);
    double std = 0;
    for (int i = 0; i < size; i++)
    {
        std += (mean - a[i]) * (mean - a[i]);
    }
    return sqrt(std / size);
}

void* AllocArray(unsigned bytes, unsigned size)
{
    void* p = malloc(size * bytes);
    return p;
}

void* AllocZeroArray(unsigned bytes, unsigned size)
{
    return AllocSpecArray(bytes, size, 0);
}
// 产生特定字符初始化的数组
void* AllocSpecArray(unsigned bytes, unsigned size, char spec)
{
    void* p = AllocArray(bytes, size);
    memset(p, spec, bytes * size);
    return p;
}

char* RandomString(unsigned size)
{
    static char charset[] =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,.-#'?!";
    char* randomString = NULL;
    if (size)
    {
        randomString = malloc(size + 1);
        if (randomString)
        {
            for (int n = 0; n < size; n++)
            {
                int key = GetRandomNumber(0, sizeof(charset) - 1);
                randomString[n] = charset[key];
            }
            randomString[size] = '\0';
        }
    }
    return randomString;
}

int IntPow(int a, int b)
{
    int res = 1;
    for (int i = 1; i <= b; i++)
    {
        res *= a;
    }
    return res;
}

int CmpString(const char* LHS, const char* RHS)
{
    return strcmp(LHS, RHS);
}

int CmpInteger(int LHS, int RHS)
{
    return LHS - RHS;
}