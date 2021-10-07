#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi .    �����޸�, ����, ���ڿ� ��ȯ�Լ�
#include <string.h>  // memcpy, memcpy, strcpy   �޸� ���, ���ڿ� �Լ�.
#include <conio.h>   //_getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock ..  �ð� ��¥ �Լ�
#pragma warning(disable:4996)   // scanf() �� ���� C �Լ��� ���� ����
#include "ListStack.h"

//���� �ʱ�ȭ
void stack_init(Stack *pStack)
{
	pStack->pTop = NULL;
}

// ���� ����
void stack_destroy(Stack *pStack)
{
	// ������ �� ����������� pop �ϸ� ��.
	Data data;

	while (!stack_is_empty(pStack))
		stack_pop(&pStack, &data);
}

// ������ ������� Ȯ��
int stack_is_empty(Stack *pStack)
{
	if (pStack->pTop == NULL)
		return SUCCESS;   // ���������
	else
		return FAIL;    // ������� ������
}

// top�� ������ �ֱ�
int stack_push(Stack *pStack, Data data)
{
	// �� ��� ����
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	newNode->data = data;
	newNode->pNext = pStack->pTop;

	pStack->pTop = newNode;
	return SUCCESS;
}

// top �� ������ ������
int stack_pop(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack))
	{
		printf("Empty Stack\n");
		return FAIL;
	}

	*pData = pStack->pTop->data;  // ������ �б�

	Node *pCurrent = pStack->pTop;  // ����� ������ ��� �ּ�
	pStack->pTop = pStack->pTop->pNext; // top �̵�
	free(pCurrent);
	return SUCCESS;
}

// top �� ������ �̸� ����
int stack_peek(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack))
	{
		printf("Empty Stack\n");
		return FAIL;
	}

	*pData = pStack->pTop->data;  // top �� �����͸� �о��
	return SUCCESS;
}