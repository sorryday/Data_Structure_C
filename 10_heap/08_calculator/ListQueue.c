#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#include "ListQueue.h"
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.

// ť �ʱ�ȭ
void queue_init(Queue *pq)
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}
// ť ����
void queue_destroy(Queue *pq)
{
	//int data;
	while (!queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}

// ť ����ֳ���?
int queue_is_empty(Queue *pq)
{
	if (pq->pFront == NULL)
		return SUCCESS;
	else
		return FAIL;
}

// enqueue ������ �߰�
int queue_enq(Queue *pq, Data *pData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->str = (char*)malloc(strlen(pData) + 1); //��
	strcpy(newNode->str, pData);  // ���ڿ� ���� ��


	// ť�� ����������� �ϳ��� ������ ������ �����Ͽ� ����
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
}
// dequeue ������ ������
int queue_deq(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq))
	{
		printf("Queue Empty!\n");
		return FAIL;
	}

	//*pData = pq->pFront->str;

	if(pData !=NULL)
		strcpy(pData, pq->pFront->str); // ��

	Node *tmp = pq->pFront;  // ������ ��� �ּ� �ӽ� ����
	pq->pFront = pq->pFront->pNext;  // ���� front �̵�

	free(tmp->str);   // ���� ���ڿ� ���� ��
	free(tmp);  // �׸��� ���� ��� ����

	return SUCCESS;
}
// peek ������ �鿩�� ����
int queue_peek(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq))
	{
		printf("Queue Empty!\n");
		return FAIL;
	}
	//*pData = pq->pFront->str;
	strcpy(pData, pq->pFront->str);  // ��

	return SUCCESS;
}