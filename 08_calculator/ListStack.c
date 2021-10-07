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
	//Data data;

	while (!stack_is_empty(pStack))
		stack_pop(pStack, NULL);
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
int stack_push(Stack *pStack, Data *pData) // ��
{
	// �� ��� ����
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	newNode->str = (char*)malloc(strlen(pData) + 1); // ��
	strcpy(newNode->str, pData); //�� ���ڿ� ����

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

	//*pData = pStack->pTop->str;  // ������ �б�
	if(pData != NULL)
		strcpy(pData, pStack->pTop->str); // ��

	Node *pCurrent = pStack->pTop;  // ����� ������ ��� �ּ�
	pStack->pTop = pStack->pTop->pNext; // top �̵�

	free(pCurrent->str);   // ���� data ���� ��
	free(pCurrent);        // �״����� node ���� 
	return SUCCESS;
}

// top �� ������ �̸� ����
int stack_peek(Stack *pStack, Data *pData)
{
	if (stack_is_empty(pStack))
	{
		//printf("Empty Stack\n");
		return FAIL;
	}

	//*pData = pStack->pTop->str;  // top �� �����͸� �о��
	strcpy(pData, pStack->pTop->str);  // ��

	return SUCCESS;
}
