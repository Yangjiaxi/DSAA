#ifndef HASH_LIST_H
#define HASH_LIST_H

#include "../Utils/Utils.h"

struct HLNode;
typedef struct HLNode* PtrToHLNode;
typedef PtrToHLNode HList;
typedef PtrToHLNode HLPosition;

typedef char* HEleType;

typedef int (*Comparator)(HEleType RHS, HEleType LHS);

// 生成一个链表实例
HList InitHList(HList L);
// 判断链表是否为空
Bool HLIsEmpty(HList L);
// 判断P是不是L的最后一个元素
Bool HLIsLast(HLPosition P, HList L);
// 在L中寻找值为X的元素
HLPosition HLFind(HEleType X, HList L, Comparator cmp);
// 按值删除元素
void HLDeleteByValue(HEleType X, HList L, Comparator cmp);
// 按指针删除元素
// void HLDeleteByPtr(HLPosition X, HList L);
// 返回值为X元素的前一个元素
HLPosition HLFindPreviousByValue(HEleType X, HList L, Comparator cmp);
// 返回指向P的元素的前一个元素
// HLPosition HLFindPreviousByPtr(HLPosition P, HList L);
// 在L中P之前插入值X
HLPosition HLInsertAfter(HEleType X, HList L, HLPosition P);
// 指针P前进1
HLPosition HLAdvance(HLPosition P);
// 删除链表L
void DeleteHList(HList L);
// 返回链表表头
HLPosition HLHeader(HList L);
// 返回链表首元素指针
HLPosition HLFirstElement(HList L);
// 返回P所指单元存储的值
HEleType HLRetrieve(HLPosition P);
// 返回链表长度
int HLLength(HList L);
// 打印链表
void PrintHList(HList L, char* title, char* link);

// 链表节点
struct HLNode
{
    HEleType Element;
    HLPosition Next;
};

#endif  // HASH_LIST_H