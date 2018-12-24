#ifndef HASHCODE_H
#define HASHCODE_H

#include "HashList.h"

typedef unsigned int Index;

typedef Index (*Hasher)(HEleType Key, int Size);

// 数字哈希1
Index NumHash1(int Key, int Size);

// 数字哈希2
Index NumHash2(int Key, int Size);

// 数字哈希3
Index NumHash3(int Key, int Size);

// 平凡字符串哈希1
Index StrHash1(char* Key, int Size);

// 平凡字符串哈希2
Index StrHash2(char* Key, int Size);

// BKDR
Index BKDRHash(char* str, int Size);
// SDBM
Index SDBMHash(char* str, int Size);
Index RSHash(char* str, int Size);
Index APHash(char* str, int Size);
#endif  // HASHCODE_H