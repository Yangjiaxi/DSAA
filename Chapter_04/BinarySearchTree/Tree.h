//
// Created by Vans on 2017/11/6.
//

#ifndef BINARYSEARCHTREE_TREE_H
#define BINARYSEARCHTREE_TREE_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);     //清空（初始化或程序结束后的释放）
Position Find(int X, SearchTree T);     //在树T中寻找元素X的位置，并返回指向节点的指针，未找到返回NULL
Position FindMin(SearchTree T);         //寻找树中最小元素
Position FindMax(SearchTree T);         //寻找树中最大元素（不使用递归）
SearchTree Insert(int X, SearchTree T); //插入值为X的节点
SearchTree Delete(int X, SearchTree T); //删除树中值为X的节点
void InorderTreeWalk(SearchTree T);     //中序遍历输出
void PreTreeWalk(SearchTree T);         //先序遍历输出
void PostTreeWalk(SearchTree T);        //后序遍历输出

#endif //BINARYSEARCHTREE_TREE_H