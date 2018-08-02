#ifndef DEQUE_POINTER_DEQUE_H
#define DEQUE_POINTER_DEQUE_H

struct _Node;
typedef struct _Node Node;
typedef Node *Position;

struct _Deque;
typedef struct _Deque *Deque;

void InitDeque(Deque D);

int IsEmpty(Deque D);

void Push(int X, Deque D);

int Pop(Deque D);

void Inject(int X, Deque D);

int Eject(Deque D);

int Front(Deque D);

int Back(Deque D);

void DeleteDeque(Deque D);

void PrintDeque(Deque D);

#endif