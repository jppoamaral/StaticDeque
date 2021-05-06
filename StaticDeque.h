#ifndef __STATIC_DEQUE_H__
#define __STATIC_DEQUE_H__

const int CAPACITY = 8;

struct StaticDeque
{
	int count;
	int back;
	int front;
	int values[CAPACITY];
};

StaticDeque Create();

bool InsertFront(StaticDeque& deque, int elem);

bool InsertBack(StaticDeque& deque, int elem);

int RemoveFront(StaticDeque& deque);

int RemoveBack(StaticDeque& deque);

int Front(StaticDeque& deque);

int Back(StaticDeque& deque);

int Size(StaticDeque& deque);

int Count(StaticDeque& deque);

bool IsEmpty(StaticDeque& deque);

bool Clear(StaticDeque& deque);
#endif