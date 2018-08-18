#ifndef TRANVERSALOFTREE_QUEUE_IDX_H
#define TRANVERSALOFTREE_QUEUE_IDX_H

#include "tree_tranversal.h"

#define MAX_QUEUE_SIZE 20

struct _Queue;

typedef struct _Queue *Queue;

Queue NewQueue();

void InitQueue(Queue Q);

void EnQueue(Queue Q, Postion X);

Postion DeQueue(Queue Q);

int IsEmpty(Queue Q);

#endif //TRANVERSALOFTREE_QUEUE_IDX_H
