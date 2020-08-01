#ifndef LIST_H
#define LIST_H

#include "../Utils/Utils.h"

struct LNode;
typedef struct LNode *PtrToLNode;
typedef PtrToLNode List;
typedef PtrToLNode LPosition;

typedef int LElementType;

// 链表主体
typedef struct _LinkedList *LinkedList;

// 生成一个链表实例
void InitList(LinkedList L);

// 判断链表是否为空
Bool LIsEmpty(LinkedList L);

// 判断P是不是L的最后一个元素
Bool LIsLast(LinkedList L, LPosition P);

// 在L中寻找值为X的元素
LPosition LFind(LinkedList L, LElementType X);

// 按值删除元素
void LDeleteByValue(LinkedList L, LElementType X);

// 按指针删除元素
void LDeleteByPtr(LinkedList L, LPosition X);

// 返回值为X元素的前一个元素
LPosition LFindPreviousByValue(LinkedList L, LElementType X);

// 返回指向P的元素的前一个元素
LPosition LFindPreviousByPtr(LinkedList L, LPosition P);

// 在L中P之前插入值X
LPosition LInsertAfter(LinkedList L, LElementType X, LPosition P);

// 删除链表L
void DeleteList(LinkedList L);

// 返回链表表头
LPosition LHeader(LinkedList L);

// 返回链表首元素指针
LPosition LFirstElement(LinkedList L);

// 指针P前进1
LPosition LAdvance(LPosition P);

// 指针P前进n
LPosition LAdvance_n(LPosition P, int n);

// 返回P所指单元存储的值
LElementType LRetrieve(LPosition P);

// 返回链表长度
int LLength(LinkedList L);

// 打印链表
void PrintList(LinkedList L, char *title, char *link);

// 新建外层链表主体
LinkedList NewLinkedList();

// 链表节点
struct LNode
{
    LElementType Element;
    LPosition Next;
};

struct _LinkedList
{
    List self;

    Bool (*isEmpty)(LinkedList);

    Bool (*isLast)(LinkedList, LPosition);

    LPosition (*find)(LinkedList, LElementType);

    void (*deleteByPointer)(LinkedList, LPosition);

    void (*deleteByValue)(LinkedList, LElementType);

    LPosition (*insertAfter)(LinkedList, LElementType, LPosition);

    void (*removeAll)(LinkedList);

    LPosition (*header)(LinkedList);

    LPosition (*first)(LinkedList);

    int (*size)(LinkedList);

    void (*printList)(LinkedList, char *, char *);
};

#endif  // LIST_H