#ifndef LIST_H
#define LIST_H

#include "../Utils/Utils.h"

struct LNode;
typedef struct LNode* PtrToLNode;
typedef PtrToLNode List;
typedef PtrToLNode LPosition;

typedef int LElementType;

// 生成一个链表实例
List InitList(List L);
// 判断链表是否为空
Bool LIsEmpty(List L);
// 判断P是不是L的最后一个元素
Bool LIsLast(LPosition P, List L);
// 在L中寻找值为X的元素
LPosition LFind(LElementType X, List L);
// 按值删除元素
void LDeleteByValue(LElementType X, List L);
// 按指针删除元素
void LDeleteByPtr(LPosition X, List L);
// 返回值为X元素的前一个元素
LPosition LFindPreviousByValue(LElementType X, List L);
// 返回指向P的元素的前一个元素
LPosition LFindPreviousByPtr(LPosition P, List L);
// 在L中P之前插入值X
LPosition LInsertAfter(LElementType X, List L, LPosition P);
// 删除链表L
void DeleteList(List L);
// 返回链表表头
LPosition LHeader(List L);
// 返回链表首元素指针
LPosition LFirstElement(List L);
// 指针P前进1
LPosition LAdvance(LPosition P);
// 指针P前进n
LPosition LAdvance_n(LPosition P, int n);
// 返回P所指单元存储的值
LElementType LRetrieve(LPosition P);
// 返回链表长度
int LLength(List L);
// 打印链表
void PrintList(List L, char* title, char* link);
// 链表节点
struct LNode
{
    LElementType Element;
    LPosition Next;
};

#endif  // LIST_H