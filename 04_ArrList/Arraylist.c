#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
#include "ArrayList.h"

// ����Ʈ �ʱ�ȭ

void list_init(List * pList)
{
	pList->numdata = 0; // �������� ���� : 0��
	pList ->curPosition = -1;					// curposition�� 0���ٴ� �׻� �Ѵܰ� ���� -1�� ����.
	memset(pList->arr, 0, sizeof(pList->arr));	// �迭 �ʱ�ȭ
	printf("����Ʈ �ʱ�ȭ\n");
}
// ����Ʈ ����
void list_distory(List*pList)
{
	pList->numdata = 0;
	printf("����Ʈ ���� \n");
}

int list_add(List * pList, Data data) // int�� ������  ? : ���� or ���� ���� ��ȯ�ϱ� ����
{
	//����Ʈ�� ������� �ִ��� Ȯ�� ( ���� ó�� )
	if (pList->numdata >= 4)
	{
		printf("������ �߰� �Ұ� : ����Ʈ�� �� ������ �����ϴ�.\n");
		return 0;
	}

	pList->arr[pList->numdata] = data;
	printf("[%d]��° ������ %d�� �߰��� �Ǿ����ϴ�.\n", pList->numdata, data);
	(pList->numdata)++;
	return 1;

}


void list_init_iter(List * pList)	//������ �ʱ�ȭ 
{
	pList->curPosition = -1;
}

int list_hasNext(List*pList)
{
	if (pList->curPosition + 1 < pList->numdata) // curPosition ���� �����ִ� �����ͺ��� �������
		return Success;							 // ���� �̾Ƴ� �� �ִ� �����Ͱ� �ִٴ� ��!!!.

	return Fail;
}

Data list_next(List*pList)
{
	pList->curPosition++;
	return pList->arr[pList->curPosition];
}

//n��°�� data�� ����
int list_set(List*pList, int n, Data data)
{
	if (n >= pList->numdata)
	{
		printf("%d ��° ������ ���� ���� \n",n);
		return Fail;
	}

	printf("%d ��° ������ ���� : %d --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;
	return Success;
}

//�������� ����-> ����
int list_length(List *pList)
{
	return pList->numdata;
}

// ������ ��ȸ , n��° ������ �� �б�
int list_get(List*pList, int n, Data *pData)
{
	if (n >= pList->numdata)
		return Fail;

	*pData = pList->arr[n];		// �����Ͱ� call by Reference 

}

// n��° ������ ����
int list_remove(List*pList, int n)
{
	//�迭�̴ϱ� �߰� ������ ���� �ϸ� ���� �͵� ��� �;���.
	if (n >= pList->numdata)
	{
		printf("%d ��° ������ ���� ���� \n", n);
		return Fail;
	}

	int i;
	for (i = n; i < pList->numdata - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->numdata--;	//����Ʈ length ����
	printf("%d��° ������ ����\n", n);
	return Success;
}