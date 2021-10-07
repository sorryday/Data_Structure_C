#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    동적메모리, 난수, 문자열 변환함수
#include <string.h>  // memcpy, memcpy, strcpy   메모리 블록, 문자열 함수.
#include <conio.h>   //_getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock ..  시간 날짜 함수
#pragma warning(disable:4996)   // scanf() 등 전통 C 함수중 버퍼 문제
#include "ListStack.h"
//스택 초기화
void stack_init(Stack *pStack)
{
	pStack->pTop = NULL;
}

// 스택 제거
void stack_destroy(Stack *pStack)
{
	// 스택이 다 비워질때까지 pop 하면 됨.
	//Data data;

	while (!stack_is_empty(pStack))
		stack_pop(pStack, NULL);
}

// 스택이 비었는지 확인
int stack_is_empty(Stack *pStack)
{
	if (pStack->pTop == NULL)
		return SUCCESS;   // 비어있으면
	else
		return FAIL;    // 비어있지 않으면
}

// top에 데이터 넣기
int stack_push(Stack *pStack, Data *pData) // ★
{
	// 새 노드 생성
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	newNode->str = (char*)malloc(strlen(pData) + 1); // ★
	strcpy(newNode->str, pData); //★ 문자열 복사

	newNode->pNext = pStack->pTop;

	pStack->pTop = newNode;
	return SUCCESS;
}

// top 의 데이터 꺼내기
int stack_pop(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack))
	{
		printf("Empty Stack\n");
		return FAIL;
	}

	//*pData = pStack->pTop->str;  // 데이터 읽기
	if(pData != NULL)
		strcpy(pData, pStack->pTop->str); // ★

	Node *pCurrent = pStack->pTop;  // 잠시후 삭제할 노드 주소
	pStack->pTop = pStack->pTop->pNext; // top 이동

	free(pCurrent->str);   // 먼저 data 제거 ★
	free(pCurrent);        // 그다음에 node 제거 
	return SUCCESS;
}

// top 의 데이터 미리 보기
int stack_peek(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack))
	{
		//printf("Empty Stack\n");
		return FAIL;
	}

	//*pData = pStack->pTop->str;  // top 의 데이터만 읽어옴
	strcpy(pData, pStack->pTop->str);  // ★

	return SUCCESS;
}
