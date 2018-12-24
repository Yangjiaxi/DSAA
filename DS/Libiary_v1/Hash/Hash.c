#include "Hash.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "../Utils/Utils.h"

HashTable InitHashTable(int Pow2Size, double LoadFactor, Hasher hashFunc)
{
    HashTable H;
    int InitSize = IntPow(2, Pow2Size);
    if (InitSize < MIN_TABLE_SIZE)
    {
        Fatal("Table size too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        Fatal("Out of space!");

    H->Pow2 = Pow2Size;
    H->Size = InitSize - 1;
    H->LoadFactor = LoadFactor;
    // printf("Init a hash table with size %d\n", H->Size);
    // 设置哈希函数
    H->hashFunc = hashFunc;

    // 分配子链表表头空间
    H->Containers = malloc(sizeof(HList) * H->Size);
    if (H->Containers == NULL)
        Fatal("Out of space!");

    // 分配所有子链表空间
    for (int i = 0; i < H->Size; i++)
    {
        H->Containers[i] = InitHList(NULL);
    }
    return H;
}

HashTable NewHashTable(Hasher hashFunc)
{
    return InitHashTable(4, 0.75, hashFunc);
}

void DestoryTable(HashTable H)
{
    MakeTableEmpty(H);
    free(H->Containers);
    free(H);
}

void MakeTableEmpty(HashTable H)
{
    for (int i = 0; i < H->Size; i++)
    {
        DeleteHList(H->Containers[i]);
    }
}

HashTable HashInsert(HEleType Key, HashTable H)
{
    Index pos = H->hashFunc(Key, H->Size);
    HLInsertAfter(Key, H->Containers[pos], HLHeader(H->Containers[pos]));
    // if (CalcBucketUsage(H) > 0.75)
    // if (CalcLoadFactor(H) > 0.75)
    while (CalcCollision(H) * 1.0 / HashEntryCnt(H) >= 0.1)
    {
        H = Resize(H, H->Pow2 + 1);
    }
    return H;
}

void HashInsertWithoutCheck(HEleType Key, HashTable H)
{
    Index pos = H->hashFunc(Key, H->Size);
    HLInsertAfter(Key, H->Containers[pos], HLHeader(H->Containers[pos]));
    // return H;
}

HashTable Resize(HashTable Old, int NewPow2)
{
    // printf("Call for Resize, size : %d\n", NewSize);
    HashTable ResNew = InitHashTable(NewPow2, Old->LoadFactor, Old->hashFunc);
    for (int i = 0; i < Old->Size; i++)
    {
        HLPosition cursor = HLFirstElement(Old->Containers[i]);
        while (cursor != NULL)
        {
            HashInsertWithoutCheck(HLRetrieve(cursor), ResNew);
            cursor = HLAdvance(cursor);
        }
    }
    // PlotHashTable(Old);

    printf("Resize! %d -> %d\n", Old->Size, ResNew->Size);
    DestoryTable(Old);
    return ResNew;
}

HLPosition HashFind(HEleType Key, HashTable H, Comparator cmp)
{
    Index pos = H->hashFunc(Key, H->Size);
    return HLFind(Key, H->Containers[pos], cmp);
}

void HashDelete(HEleType Key, HashTable H, Comparator cmp)
{
    Index pos = H->hashFunc(Key, H->Size);
    HLDeleteByValue(Key, H->Containers[pos], cmp);
}

//  计算装填因子
double CalcLoadFactor(HashTable H)
{
    unsigned total = 0;
    for (int i = 0; i < H->Size; i++)
    {
        total += HLLength(H->Containers[i]);
    }
    return total * 1.0 / H->Size;
}

double CalcBucketUsage(HashTable H)
{
    unsigned use = 0;
    for (int i = 0; i < H->Size; i++)
    {
        use += !HLIsEmpty(H->Containers[i]);
    }
    return use * 1.0 / H->Size;
}

unsigned HashEntryCnt(HashTable H)
{
    unsigned sum = 0;
    for (int i = 0; i < H->Size; i++)
    {
        sum += HLLength(H->Containers[i]);
    }
    return sum;
}

void PlotHashTable(HashTable H)
{
    AlignPrint(GetConsoleWidth(), '-', "Print : Hash Table");
    for (int i = 0; i < H->Size; i++)
    {
        printf("%3d :: ", i);
        PrintHList(H->Containers[i], NULL, "->");
    }
    AlignPrint(GetConsoleWidth(), '-', "END");
}

unsigned LongestList(HashTable H)
{
    if (H->Size <= 0)
        return 0;
    int max = INT_MIN;
    for (int i = 0; i < H->Size; i++)
    {
        int t = HLLength(H->Containers[i]);
        if (max < t)
        {
            max = t;
        }
    }
    return max;
}

double CalcTableStd(HashTable H)
{
    int* p = (int*)AllocZeroArray(sizeof(int), H->Size);
    for (int i = 0; i < H->Size; i++)
    {
        p[i] = HLLength(H->Containers[i]);
    }
    double std = ArrayStd(p, H->Size);
    free(p);
    return std;
}

double CalcTableMean(HashTable H)
{
    int* p = (int*)AllocZeroArray(sizeof(int), H->Size);
    for (int i = 0; i < H->Size; i++)
    {
        p[i] = HLLength(H->Containers[i]);
    }
    double avg = ArrayMean(p, H->Size);
    free(p);
    return avg;
}

unsigned CalcCollision(HashTable H)
{
    int res = 0;
    for (int i = 0; i < H->Size; i++)
    {
        res +=
            (HLIsEmpty(H->Containers[i])) ? 0 : HLLength(H->Containers[i]) - 1;
    }
    return res;
}

void HashScore(HashTable H)
{
    printf("Hash Info : \n");
    printf("\tTotal : %u\n", HashEntryCnt(H));
    printf("\tAvg : %lf\n", CalcTableMean(H));
    printf("\tStd : %lf\n", CalcTableStd(H));
    printf("\tMax : %d\n", LongestList(H));
    printf("\tBucket Usage : %lf\n", CalcBucketUsage(H));
    printf("\tLoad Factor : %lf\n", CalcLoadFactor(H));
    printf("\tCollisions : %u\n", CalcCollision(H));
    printf("\tCollision ratio %lf\n", CalcCollision(H) * 1.0 / HashEntryCnt(H));
}