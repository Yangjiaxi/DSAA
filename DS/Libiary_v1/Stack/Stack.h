#ifndef STACK_H
#define STACK_H

#include "../List/List.h"

typedef List Stack;

typedef LPosition SPosition;

typedef LElementType SElementType;

// 初始化栈
Stack InitStack(Stack S);
// 入栈
void Push(SElementType X, Stack S);
// 弹栈并返回
SElementType Pop(Stack S);
// 返回栈顶元素
SElementType Top(Stack S);
// 返回栈顶元素
SElementType Peek(Stack S);
// 栈是否为空
Bool IsStackEmpty(Stack S);
// 清空栈
void DeleteStack(Stack S);
// 打印栈
void PrintStack(Stack S);

#endif  // STACK_H