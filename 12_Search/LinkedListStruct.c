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

	//  free(pPrev->pData);  // ������ ����
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
int list_add(List* pList, Data data)
{
	// ���ο� Node ����
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->data = data;

	// tail �� ����Ű�� next �� ���ο� node �� ����
	pList->pTail->pNext = pNewNode;

	// tail �̵�
	pList->pTail = pNewNode;

	// printf("[%d] ��° ������ %s �߰�\n", pList->numData, pData->szName);
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
Data list_next(List* pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // ���� current �̵�
	return pList->pCurrent->data;
}

// n��°�� data�� ���� �ڵ����ʹ� ������
int list_set(List* pList, int n, Data data)
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
	
	pList->pCurrent->data = data;

	//printf("%d ��° ������ ����\n", n);
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
	*pData = pList->pCurrent->data;

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
	// free(pList->pCurrent->pData);    // ������ ���� ����

	free(pList->pCurrent);           // ��� ����

	pList->numData--;   // ����Ʈ ������ ���� ����
	//printf("%d ��° ������ ����\n", n);
	return SUCCESS;
}

// �־��� pList���� Ư�� �����Ͱ� ��� ��带 Ž���ؼ� �����ϴ� �Լ�
// ������ NULL ���� 
Node *list_search(List *pList, int data)
{

	pList->pCurrent = pList->pHead;
	while (pList->pCurrent->pNext != NULL)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		if (pList->pCurrent->data == data)
			return pList->pCurrent;   // ������ �������ٸ� Ž�� good , ��帮�� 
	}

	//int d;
	//list_init_iter(pList);
	//while (list_hasNext(pList))
	//{
	//	d = list_next(pList); // Node�� data���� d�� ����.
	//	if (d == data)  // ã������ �����Ϳ� d�� ���� ���ٸ�
	//	{
	//		return pList->pCurrent; // ��� �����͸� ���� 
	//	}
	//}
	return NULL; // data ���� ��ã���� NULL ���� 
}