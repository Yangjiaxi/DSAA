#ifndef QUEUE_POINTER_QUEUE_H
#define QUEUE_POINTER_QUEUE_H

struct _Node;
typedef struct _Node Node;
typedef Node *Position;

struct _Queue;
typedef struct _Queue *Queue;

void InitQueue(Queue Q);

int IsEmpty(Queue Q);

void EnQueue(int X, Queue Q);

int Front(Queue Q);

int Back(Queue Q);

int DeQueue(Queue Q);

void DeleteQueue(Queue Q);

void PrintQueue(Queue Q);

#endif