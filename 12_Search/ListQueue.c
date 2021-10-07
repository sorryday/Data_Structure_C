#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#include "BinaryTree.h"
#include "ListQueue.h"
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
void queue_init(Queue *pq) // ť �ʱ�ȭ
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}

void queue_destroy(Queue *pq) // ť ����
{
	while (!queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}

int queue_is_empty(Queue *pq) // ť�� ����ֳ���? , front �����ͷ� üũ
{
	if (pq->pFront == NULL)
	{
		return SUCCESS;
	}
	else
		return FAIL;
}

int queue_enq(Queue *pq, Data data)// ������ �߰� , enqueue
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->data = data;

	// ť�� ������� ���� �����Ͱ� �ϳ��� ���� �� �����Ͽ� ����.
	if (queue_is_empty(pq))
	{
		pq->pFront = newNode;
		pq->pRear = newNode;
	}
	else
	{
		pq->pRear->pNext = newNode;
		pq->pRear = newNode;
	}
	return SUCCESS;
}

int queue_deq(Queue *pq, Data *pData) // ������ ������, dequeue
{
	if (queue_is_empty(pq))
	{
		printf("Queue_i_empty\n");
		return FAIL;
	}

	if (pData != NULL)
	{
		*pData = pq->pFront->data;
	}

	Node *tmp = pq->pFront; // ������ ��� �ּ� �ӽ� ����.
	pq->pFront = pq->pFront->pNext; //���� front�� �̵�
	free(tmp); // �ӽó�� �����ϸ鼭 �����͸� ����ִ� ��嵵 ���� ������
	return SUCCESS;
}

int queue_peek(Queue *pq, Data *pData) // ������ �鿩�� ���� , peek.
{
	if (queue_is_empty(pq))
	{
		//printf("Queue_i_empty\n");
		return FAIL;
	}

	if (pData != NULL)
	{
		*pData = pq->pFront->data;
	}
	return SUCCESS;
}