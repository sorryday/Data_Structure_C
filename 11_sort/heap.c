#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�

#pragma warning(disable:4996)

#include "Heap.h"

// ����� �Լ�

//��� �ε��� ��� ��ũ�� ( ����  UP )

// �θ� �ε���
#define GET_PARENT_IDX(idx) ( (idx) >> 1) // == idx / 2

// left �ڽ� �ε���
#define GET_LEFT_IDX(idx) ( (idx) << 1 )  // == idx *2

// right �ڽ� �ε���
//int GET_RIGHT_IDX(int idx) { return idx * 2 + 1; }
#define GET_RIGHT_IDX(idx) ( ((idx) << 1) + 1 )  // == idx *2 + 1

// �� �Լ� ���  ��ũ�� ��� 
#define COMP_ASC(d1,d2) ((d2)-(d1))		//���� ���� 

// delete ���۽�
// �켱������ ���� �ڽ��� �ε��� �� ����

int getHighPriority(Heap *ph, int idx)
{
	// �ڽĳ�尡 ������ 0 ����
	if (GET_LEFT_IDX(idx) > ph->numData)
		return 0;

	// �ڽ��� ���� �ϳ��ۿ� ���ٸ� left ����
	if (GET_LEFT_IDX(idx) == ph->numData)
		return GET_LEFT_IDX(idx);

	// left vs right ��
	if (COMP_ASC(
		ph->heapArr[GET_LEFT_IDX(idx)],
		ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)

		return GET_RIGHT_IDX(idx);   // ������ �켱������ ����
	else

		return GET_LEFT_IDX(idx);    // ���� �켱������ ����(���ų�)
}

void heap_init(Heap *ph, int len)
{
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1)); // +1 �� ��ŭ �߰�
	g_hp = ph; // �� ���Ŀ��ʿ�
}

// ���� ���ִ°�
void heap_destroy(Heap *ph)
{
	free(ph->heapArr);
	ph->heapArr = NULL;
	ph->numData = 0;
	g_hp = NULL;
}

// ���� ����ֳ���?

int heap_is_empty(Heap *ph)
{
	if (ph->numData == 0)
		return SUCCESS;

	else
		return FAIL;
}

// ���� ������ �߰�
void heap_insert(Heap *ph, HData data)
{
	int idx = ph->numData + 1;   // �迭 ��+1��° �ϴ� ��ġ
	while (idx != 1)
	{
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)  // �θ𺸴� �켱������ ���ٸ�
		{
			// �θ� ���� ������
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];
			idx = GET_PARENT_IDX(idx);   // idx �� �θ��� ��ġ�� �̵�.
		}

		else   // �θ𺸴� �켱������ ���ų� �۴ٸ�..
		{
			break;
		}
	} // end while

	ph->heapArr[idx] = data;  // �ö󰡴� ���� �װ�! 

							// ���ο� ������ insert ��!
	ph->numData++;			// ������ ���� ����
}

// ������ root ���� & ����
HData heap_delete(Heap *ph)
{
	HData retData = ph->heapArr[1];  // �ε��� 1���� ��Ʈ. 
	HData lastElem = ph->heapArr[ph->numData];  // numData ��°�� ������ ���.

	int parentIdx = 1;
	int childIdx;

	// �ڽ� ��� ��, �켱���� ������ ����
	// �ڽ��� �ϳ��� ���ٸ� while �� ����

	while (childIdx = getHighPriority(ph, parentIdx))
	{
		// ���õ� �ڽ�(childIdx) �� �켱���� ��
		// ���� �ڽ��� �켱������ ���ų� ���ٸ� while ����

		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		// �ڽ��� �켱������ �� ũ�ٸ�,  �� �ڽ��� �θ��� �ڸ��� ��ü
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx; // ���� �񱳸� ���� �θ��ε����� �ڽ��� ��ġ�� �̵�
	}

	// while �� �� ���� �� �ڸ�(parentIdx)��, 
	// �ǹؿ��� �ö�Դ� ��尡 ���� ��ġ�� �ڸ�

	ph->heapArr[parentIdx] = lastElem;
	ph->numData--;

	return retData;   // ���ʿ� �����س��� root ������ ����
}

// �� ���� 
void HeapSort(int arr[], int n)
{
	int i;
	// �� ���� ������ ���� 
	// �� insert �ϰ� , �ٽ� �� delete �ϸ� �˾Ƽ� ���ĵ� 

	for (i = 0; i < n; i++)
	{
		heap_insert(g_hp, arr[i]);
	}

	// delete

	for (i = 0; i < n; i++)
	{
		arr[i]=heap_delete(g_hp);
	}
}