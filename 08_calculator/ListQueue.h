#ifndef __QUEUE_H__
#define __QUEUE_H__

#define SUCCESS 1
#define FAIL 0

/* ť �� ������ */
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
	Node *pFront;    // dequeue �߻�
	Node *pRear;    // enqueue �߻�
} ListQueue;
typedef ListQueue Queue;

/*  ť�� ���� */
void queue_init(Queue *pq);   // ť �ʱ�ȭ
void queue_destroy(Queue *pq);  // ť ����

int queue_is_empty(Queue *pq);   // ť ����ֳ���?

int queue_enq(Queue *pq, Data *pData);    // ��enqueue ������ �߰�
int queue_deq(Queue *pq, Data *pData);  // dequeue ������ ������
int queue_peek(Queue *pq, Data *pData);  // peek ������ �鿩�� ����

#endif