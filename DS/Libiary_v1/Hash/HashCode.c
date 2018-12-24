#include "HashCode.h"
#include <stdio.h>
#include <string.h>

Index StrHash1(char* Key, int Size)
{
    unsigned int HashVal = 0;
    while (*Key != '\0')
        HashVal += *Key++;
    return HashVal % Size;
}

Index StrHash2(char* Key, int Size)
{
    unsigned int HashVal = 0;
    while (*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
    return HashVal % Size;
}

Index NumHash1(int Key, int Size)
{
    char b[20];
    memset(b, 0, sizeof(b));
    sprintf(b, "%d", Key);
    return StrHash1(b, Size);
}

// 数字哈希2
Index NumHash2(int Key, int Size)
{
    char b[20];
    memset(b, 0, sizeof(b));
    sprintf(b, "%d", Key);
    return StrHash2(b, Size);
}

// 数字哈希3
Index NumHash3(int Key, int Size)
{
    return ((Key << 4) - (Key >> 4) + (Key << 3) - (Key >> 3)) % Size;
}

Index BKDRHash(char* str, int Size)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = hash * 131 + *str++;
    }
    return hash % Size;
}

Index SDBMHash(char* str, int Size)
{
    unsigned int hash = 0;
    while (*str)
    {
        hash = 65599 * hash + *str++;
        // hash = (size_t)ch + (hash << 6) + (hash << 16) - hash;
    }
    return hash % Size;
}

Index RSHash(char* str, int Size)
{
    unsigned int hash = 0;
    unsigned magic = 63689;
    while (*str)
    {
        hash = hash * magic + *str++;
        magic *= 378551;
    }
    return hash % Size;
}

Index APHash(char* str, int Size)
{
    unsigned int hash = 0;
    for (long i = 0; *str; i++)
    {
        if ((i & 1) == 0)
        {
            hash ^= ((hash << 7) ^ *str ^ (hash >> 3));
        }
        else
        {
            hash ^= (~((hash << 11) ^ *str ^ (hash >> 5)));
        }
        ++str;
    }
    return hash % Size;
}