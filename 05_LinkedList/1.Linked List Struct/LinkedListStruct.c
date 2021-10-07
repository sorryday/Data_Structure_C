#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
#include "LinkedListStruct.h"

// ����Ʈ �ʱ�ȭ
void list_init(List* pList)
{
	// head �� dummy node
	pList->pHead = (Node*)malloc(sizeof(Node));
	memset(pList->pHead, 0, sizeof(Node));  // Node �ʱ�ȭ.

	pList->pTail = pList->pHead;   // ���ʿ��� tail �� head ����

	pList->numData = 0;
	printf("����Ʈ �ʱ�ȭ\n");
}
// ����Ʈ ����
void list_destroy(List* pList)
{
	// Linked List �� node �� ����
	pList->pCurrent = pList->pHead->pNext;

	int cnt = 0;   // ������ node ����
	while (pList->pCurrent != NULL)
	{
		Node *pPrev = pList->pCurrent;  // ������ ���
		pList->pCurrent = pList->pCurrent->pNext;  // �������� current �̵�

		free(pPrev->pData);  // ������ ����
		free(pPrev);         // ��� ����
		cnt++;
	}

	// dummy node ����
	free(pList->pHead);

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("����Ʈ ���� %d ���� node ����\n", cnt);
}

// ������ data �߰� �ڵ����ʹ� �����ͷ�
int list_add(List* pList, Data *pData)
{
	// ���ο� Node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	// ������ ����
	pNewNode->pData = (Data*)malloc(sizeof(Data));
	memcpy(pNewNode->pData, pData, sizeof(Data));

	// tail �� ����Ű�� next �� ���ο� node �� ����
	pList->pTail->pNext = pNewNode;

	// tail �̵�
	pList->pTail = pNewNode;

	printf("[%d] ��° ������ %s �߰�\n", pList->numData, pData->szName);
	(pList->numData)++;
	return SUCCESS;
}

// ������ ��ȸ (iteration)  �ʱ�ȭ
void list_init_iter(List* pList)
{
	pList->pCurrent = pList->pHead;  // current �� dummy ���� ����
}
// ������ ��ȸ : ���� ������ �ֳ�?
int list_hasNext(List* pList)
{
	if (pList->pCurrent->pNext == NULL) // ���� ��� ���� ���� üũ
		return FAIL;

	return SUCCESS;  // ���� ��� �־��~
}
// ������ ��ȸ : ���� ������ ���� �ڸ��ϰ��� �����ͷ�
Data *list_next(List* pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // ���� current �̵�
	return pList->pCurrent->pData;
}

// n��°�� data�� ���� �ڵ����ʹ� ������
int list_set(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("��������: %d ���� ������ ���� ����\n", n);
		return FAIL;
	}

	pList->pCurrent = pList->pHead->pNext;  // ù��° ������ ����
	int i;
	for (i = 0; i < n; i++)  // n ��°�� ã�Ƽ�~~
		pList->pCurrent = pList->pCurrent->pNext;  // ����.. ����...

	// �� for���� ������ current �� n���� node �� ����Ű�� �ִ�
	// ������ ����
	pList->pCurrent->pData->age = pData->age;
	pList->pCurrent->pData->grade = pData->grade;
	//pList->pCurrent->pData->szName = pData->szName;  // �迭(������ ���)�̶� �ȵȴ�
	strcpy(pList->pCurrent->pData->szName, pData->szName);  // ���ڿ� ����

	printf("%d ��° ������ ����\n", n);
	return SUCCESS;
}

// ������ ���� -> ����
int list_length(List* pList)
{
	return pList->numData;
}

// ������ ��ȸ : n��° ������ �� �б�
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("%d ���� ������ �����ϴ�\n", n);
		return FAIL;
	}

	// n��° node ã�ư���
	pList->pCurrent = pList->pHead->pNext;
	int i;
	for (i = 0; i < n; i++)
		pList->pCurrent = pList->pCurrent->pNext;

	// data�� n��° ��尪 ����ֱ�
	pData->age = pList->pCurrent->pData->age;
	pData->grade = pList->pCurrent->pData->grade;
	strcpy(pData->szName, pList->pCurrent->pData->szName);

	return SUCCESS;
}

// n��° ������ ����
int list_remove(List* pList, int n)
{
	if (n >= pList->numData)
	{
		printf("%d ��° ������ ���� ����\n", n);
		return FAIL;
	}

	// LinkedList ���� n��° ��� ���� ������ �Ϸ���
	// current �� �ƴ϶� prev(����) ��嵵 �˰� �־�� �Ѵ�
	int i;
	pList->pCurrent = pList->pHead->pNext;
	Node *pPrev = pList->pHead;   // <-- prev �� dummy node ���� ����

	for (i = 0; i < n; i++)
	{
		pPrev = pList->pCurrent;
		pList->pCurrent = pList->pCurrent->pNext;
	}

	// for ���� ������
	// current �� n��°, prev �� n-1 ��° ����Ŵ

	// ������ �ſ� �ܼ�!!!!!  (�迭 ����Ʈ�� ���� �ſ� ����, ����)
	pPrev->pNext = pList->pCurrent->pNext;

	// ���� tail�� ���� ��� ���ٸ�.  
	// tail �� �����ؾ� ��. --> prev(����) ����..
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev;

	// node �� data ���� �Ҵ� ����
	free(pList->pCurrent->pData);    // ������ ���� ����
	free(pList->pCurrent);           // ��� ����

	pList->numData--;   // ����Ʈ ������ ���� ����
	printf("%d ��° ������ ����\n", n);
	return SUCCESS;

}