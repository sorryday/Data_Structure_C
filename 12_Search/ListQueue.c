#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#include "BinaryTree.h"
#include "ListQueue.h"
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
void queue_init(Queue *pq) // 큐 초기화
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}

void queue_destroy(Queue *pq) // 큐 제거
{
	while (!queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}

int queue_is_empty(Queue *pq) // 큐가 비어있나요? , front 포인터로 체크
{
	if (pq->pFront == NULL)
	{
		return SUCCESS;
	}
	else
		return FAIL;
}

int queue_enq(Queue *pq, Data data)// 데이터 추가 , enqueue
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->data = data;

	// 큐가 비어있을 때와 데이터가 하나라도 있을 떄 구분하여 동작.
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

int queue_deq(Queue *pq, Data *pData) // 데이터 꺼내기, dequeue
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

	Node *tmp = pq->pFront; // 삭제할 노드 주소 임시 저장.
	pq->pFront = pq->pFront->pNext; //먼저 front가 이동
	free(tmp); // 임시노드 삭제하면서 데이터를 담고있는 노드도 같이 삭제됨
	return SUCCESS;
}

int queue_peek(Queue *pq, Data *pData) // 데이터 들여다 보기 , peek.
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