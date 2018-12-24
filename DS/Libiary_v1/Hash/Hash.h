#ifndef HASH_H
#define HASH_H

#include "HashCode.h"
#include "HashList.h"

#define MIN_TABLE_SIZE 5

struct HashTbl;
typedef struct HashTbl* HashTable;

// 初始化Hash表
HashTable InitHashTable(int Pow2Size, double LoadFactor, Hasher hashFunc);
// 新建HashTable(初始大小13)
HashTable NewHashTable(Hasher hashFunc);
// 销毁表H
void DestoryTable(HashTable H);
// 清空表中数据
void MakeTableEmpty(HashTable H);
// 无扩容插入
void HashInsertWithoutCheck(HEleType Key, HashTable H);
// 插入键Key
HashTable HashInsert(HEleType Key, HashTable H);
// 查找键K
HLPosition HashFind(HEleType Key, HashTable H, Comparator cmp);
// 删除键K
void HashDelete(HEleType Key, HashTable H, Comparator cmp);
// 申请NewSize的哈希表，放入Old表，销毁Old表，返回New表
HashTable Resize(HashTable Old, int NewSize);
//  计算装填因子
double CalcLoadFactor(HashTable H);
// 计算桶使用量
double CalcBucketUsage(HashTable H);
// 绘制哈希表
void PlotHashTable(HashTable H);
// 哈希表的所有元素数量
unsigned HashEntryCnt(HashTable H);
// 哈希性能评分
void HashScore(HashTable H);
// 计算冲突数量
unsigned CalcCollision(HashTable H);

struct HashTbl
{
    int Size;  // 当前表容量 = 2 ^ Pow2 - 1
    int Pow2;  // 2的指数
    double LoadFactor;  // 临界装载因子，当元素数量大于Size * LF时进行扩容
    HList* Containers;  // Size个表，稍后在Init时分配
    Hasher hashFunc;
};

#endif  // HASH_H