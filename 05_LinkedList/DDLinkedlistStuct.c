#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996)
#include "DLinkedListStruct.h"

// ����Ʈ �ʱ�ȭ
void list_init(List* pList)
{
	// head �� tail�� dummy node ����. ** 
	pList->pHead = (Node*)malloc(sizeof(Node));//**
	memset(pList->pHead, 0, sizeof(Node));  // **Node �ʱ�ȭ.

	pList->pTail = (Node *)malloc(sizeof(Node));//**
	memset(pList->pTail, 0, sizeof(Node));	//** tail �ʱ�ȭ 

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
	free(pList->pTail); //*** 

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

	// ������ ��Ʈ�� �ϳ��� ���� �� �� �Ѱ� �̻� ���� �� �����Ͽ� ����.****
	if (pList->numData == 0) // <-- ������ ��尡 �Ѱ��� ���� ��.
	{
		pList->pHead->pNext = pNewNode;	
		pList->pTail->pPrev = pNewNode;
	}
	else                     // <-- ������ ��尡 1�� �̻� ���� ��.
	{
		// tail �� ����Ű�� next �� ���ο� node �� ����
		pList->pTail->pPrev->pNext = pNewNode; // pptx�� (1)��
		pNewNode->pPrev = pList->pTail->pPrev;	// "" (2) ��
		pList->pTail->pPrev = pNewNode;		// "" (3)
	}

	printf("[%d] ��° ������ %s �߰�\n", pList->numData, pData->szName);
	(pList->numData)++;
	return 1;	//���� ���� 1�� �ٲ� 
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
//** ����� ���� iteration
void list_init_backward(List* pList)// ** �� ���� iteration �ʱ�ȭ 
{
	pList->pCurrent = pList->pTail;
}
int list_hasPrev(List* pList)	 // * ������ ��ȸ : ���� ��尡 �ֳ�?
{
	if (pList->pCurrent->pPrev == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
Data *list_prev(List* pList)	//  * ������ ��ȸ : ���� ��� ������ 
{
	pList->pCurrent = pList->pCurrent->pPrev;	// �켱 current �̵�
	return pList->pCurrent->pData;
}

int list_get(List* pList, int n, Data *pData)// ������ ��ȸ : n��° ������ �� �б�
{
	//if (n >= pList->numData)
		//return 0;
	
	int i;
	if (n <= pList->numData / 2)
	{	// head ���� ã��
		pList->pCurrent = pList->pHead->pNext; // ù��° ������ ã�� 
		for (i = 0; i < n; i++)
		{
			pList->pCurrent = pList->pCurrent->pNext;
		}
	}
	else
	{   // tail ���� ã�� 
		pList->pCurrent = pList->pTail->pPrev; // ������ ������ ã��
		for (i = 0;i<pList->numData-n-1; i++)
		{
			pList->pCurrent = pList->pCurrent->pPrev;
		}
	}
}

// n��°�� data�� ���� �ڵ����ʹ� ������
int list_set(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("��������: %d ��° ������ ���� ����\n", n);
		return FAIL;
	}
	List_move_current(pList, n); //current �̵� -> n ��° ��� 
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

	list_move_current(pList, n);
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

	list_move_current(pList, n); // n��° ���� �̵�
	
	// ���߿��Ḯ��Ʈ �� current�� �˾Ƶ� ������ ���ϴ�.
	if (pList->pCurrent->pPrev != NULL) // ù��° ��尡 �ƴ� ��� 
	{
		pList->pCurrent->pPrev->pNext = pList->pCurrent->pNext;
	}
	else 
	{
		pList->pHead->pNext = pList->pCurrent->pNext; // ù��° ����� ���
	}
	
	if (pList->pCurrent->pNext != NULL) // ��������尡 �ƴҰ�� .
	{
		pList->pCurrent->pNext->pPrev= pList->pCurrent->pPrev;
	}
	else
	{
		pList->pTail->pPrev = pList->pCurrent->pPrev; // ������ ����� ���
	}
	// node �� data ���� �Ҵ� ����
	free(pList->pCurrent->pData);    // ������ ���� ����
	free(pList->pCurrent);           // ��� ����

	pList->numData--;   // ����Ʈ ������ ���� ����
	printf("%d ��° ������ ����\n", n);
	return SUCCESS;
}