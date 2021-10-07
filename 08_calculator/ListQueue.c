#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#include "ListQueue.h"
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.

// 큐 초기화
void queue_init(Queue *pq)
{
	pq->pFront = NULL;
	pq->pRear = NULL;
}
// 큐 제거
void queue_destroy(Queue *pq)
{
	//int data;
	while (!queue_is_empty(pq))
	{
		queue_deq(pq, NULL);
	}
}

// 큐 비어있나요?
int queue_is_empty(Queue *pq)
{
	if (pq->pFront == NULL)
		return SUCCESS;
	else
		return FAIL;
}

// enqueue 데이터 추가
int queue_enq(Queue *pq, Data *pData)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->pNext = NULL;
	newNode->str = (char*)malloc(strlen(pData) + 1); //★
	strcpy(newNode->str, pData);  // 문자열 복사 ★


	// 큐가 비어있을때와 하나라도 데이터 있을때 구분하여 동작
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
// dequeue 데이터 꺼내기
int queue_deq(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq))
	{
		printf("Queue Empty!\n");
		return FAIL;
	}

	//*pData = pq->pFront->str;

	if(pData !=NULL)
		strcpy(pData, pq->pFront->str); // ★

	Node *tmp = pq->pFront;  // 삭제할 노드 주소 임시 저장
	pq->pFront = pq->pFront->pNext;  // 먼저 front 이동

	free(tmp->str);   // 먼저 문자열 삭제 ★
	free(tmp);  // 그리고 나서 노드 삭제

	return SUCCESS;
}
// peek 데이터 들여다 보기
int queue_peek(Queue *pq, Data *pData)
{
	if (queue_is_empty(pq))
	{
		printf("Queue Empty!\n");
		return FAIL;
	}
	//*pData = pq->pFront->str;
	strcpy(pData, pq->pFront->str);  // ★

	return SUCCESS;
}