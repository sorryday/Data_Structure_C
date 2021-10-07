#include <stdio.h>

#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ

#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�

#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�

#include <time.h>    // clock .. �ð�, ��¥ �Լ�

#pragma warning(disable:4996)

#include "Heap.h"



// ����� �Լ�

// �θ� �ε���

int getParentIdx(int idx) { return idx / 2; }

// left �ڽ� �ε���

int getLeftIdx(int idx) { return idx * 2; }

// right �ڽ� �ε���

int getRightIdx(int idx) { return idx * 2 + 1; }



// delete ���۽�

// �켱������ ���� �ڽ��� �ε��� �� ����

int getHighPriority(Heap *ph, int idx)

{

	// �ڽĳ�尡 ������ 0 ����

	if (getLeftIdx(idx) > ph->numData)

		return 0;



	// �ڽ��� ���� �ϳ��ۿ� ���ٸ� left ����

	if (getLeftIdx(idx) == ph->numData)

		return getLeftIdx(idx);



	// left vs right ��

	if (ph->comp(

		ph->heapArr[getLeftIdx(idx)],

		ph->heapArr[getRightIdx(idx)]) < 0)

		return getRightIdx(idx);   // ������ �켱������ ����

	else

		return getLeftIdx(idx);    // ���� �켱������ ����(���ų�)

}



// ���ʱ�ȭ

void heap_init(Heap *ph, fnPriorityComp pc)

{

	ph->numData = 0;   // ������ ���� (��� ����)

	ph->comp = pc;    // ���Լ�

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

		if (ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0)  // �θ𺸴� �켱������ ���ٸ�

		{

			// �θ� ���� ������

			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];

			idx = getParentIdx(idx);   // idx �� �θ��� ��ġ�� �̵�.

		}

		else   // �θ𺸴� �켱������ ���ų� �۴ٸ�..

		{

			break;

		}

	} // end while



	ph->heapArr[idx] = data;  // �ö󰡴� ���� �װ�! 

							// ���ο� ������ insert ��!

	ph->numData++;   // ������ ���� ����

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

		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)

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