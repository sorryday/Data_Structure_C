#pragma once
#define __QUEUE_H_
#define SUCCESS 1
#define FAIL 0

/* 큐의 데이터 */
typedef BTreeNode *Data;

typedef struct _node
{
	Data data;
	struct _node *pNext;
}Node;

typedef struct _listQueue
{
	Node *pFront; // dequeus 발생
	Node *pRear; //  eㅜqueus 발생 ,back과 같은 이름임 
}ListQueue;

typedef ListQueue Queue;

/* 큐의 동작 */
void queue_init(Queue *pq); // 큐 초기화
void queue_destroy(Queue *pq); // 큐 제거

int queue_is_empty(Queue *pq); // 큐가 비어있나요?

int queue_enq(Queue *pq, Data data); // 데이터 추가 , enqueue
int queue_deq(Queue *pq, Data *pData); // 데이터 꺼내기, dequeue
int queue_peek(Queue *pq, Data *pData); // 데이터 들여다 보기 , peek.