#ifndef __QUEUE_H__
#define __QUEUE_H__

#define SUCCESS 1
#define FAIL 0

/* 큐 의 데이터 */
#ifndef __NODE_DATA__
#define __NODE_DATA__
typedef char Data;

typedef struct _node
{
	Data *str;
	struct _node *pNext;
} Node;
#endif

typedef struct _listQueue
{
	Node *pFront;    // dequeue 발생
	Node *pRear;    // enqueue 발생
} ListQueue;
typedef ListQueue Queue;

/*  큐의 동작 */
void queue_init(Queue *pq);   // 큐 초기화
void queue_destroy(Queue *pq);  // 큐 제거

int queue_is_empty(Queue *pq);   // 큐 비어있나요?

int queue_enq(Queue *pq, Data *pData);    // ★enqueue 데이터 추가
int queue_deq(Queue *pq, Data *pData);  // dequeue 데이터 꺼내기
int queue_peek(Queue *pq, Data *pData);  // peek 데이터 들여다 보기

#endif


