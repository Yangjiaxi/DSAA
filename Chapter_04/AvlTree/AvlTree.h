#include <stdio.h>
#include <stdlib.h>

#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty(AvlTree T);  //清空一棵树
Position Find(int X, AvlTree T);  //寻找值为X的节点并返回指向该节点的指针
Position FindMax(AvlTree T);                        //寻找最大的元素
Position FindMin(AvlTree T);                        //寻找最小的元素
AvlTree Insert(int X, AvlTree T);                   //插入元素X
AvlTree Delete(int X, AvlTree T);                   //删除元素X
static int Height(Position P);                      //返回节点P的高度
static Position SingleRotateWithLeft(Position K2);  // insert LC->L，返回新的根
static Position SingleRotateWithRight(Position K2);  // insert RC->R，返回新的根
static Position DoubleRotateWithLeft(Position K3);  // insert LC->R，返回新的根
static Position DoubleRotateWithRight(Position K3);  // insert RC->L，返回新的根
static int Max(int a, int b);                        //比大小
void InorderTreeWalk(AvlTree T);                     //中序遍历输出
void PreTreeWalk(AvlTree T);                         //先序遍历输出
void PostTreeWalk(AvlTree T);                        //后序遍历输出

#endif  // AVLTREE_AVLTREE_H