#ifndef BINARYSEARCHTREE_TREE_H
#define BINARYSEARCHTREE_TREE_H

#include "../Tree/Tree.h"

typedef Tree SearchTree;
typedef TPosition BSTPosition;
typedef TElementType BSTElementType;

SearchTree BSTInsert(BSTElementType X, SearchTree T);  //插入值为X的节点
SearchTree BSTDelete(BSTElementType X, SearchTree T);  //删除树中值为X的节点

#endif  // BINARYSEARCHTREE_TREE_H