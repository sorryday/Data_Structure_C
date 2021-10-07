#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�

#pragma warning(disable:4996)

#include "Sort.h"
#include "Heap.h"
#include "QuickSort.h"

#define LEN 4000

int main(int argc, char **argv)
{
	//int srcArr[LEN] = {45, 21, 5, 36, 12}; // �����迭

	int srcArr[LEN];

	genRandom(srcArr, LEN, LEN);  // ������ �迭 

	//printArr(srcArr, LEN);

	int workArr[LEN];  // �۾��� �迭

	/*
	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(BubbleSort, workArr, LEN, "��������");
	//printArr(workArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(SelectionSort, workArr, LEN, "��������");
	//printArr(workArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(InsertionSort, workArr, LEN, "��������");
	//printArr(workArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	Heap hp;
	heap_init(&hp, LEN);
	chkTimeLap(HeapSort, workArr, LEN, "�� ���� ");
	heap_destroy(&hp);
	//printArr(workArr, LEN);

	*/
	// Quick Sort

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(QuickSortMain, workArr, LEN, "������");
	//printArr(workArr, LEN);

	// ���� ���� �迭�� �� ���� ���� �� 
	genIncSorted(workArr, LEN); // ���� ���� �迭 ���� 
	chkTimeLap(QuickSortMain, workArr, LEN, "�� ���� ��������");

	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�\n");
	_getch();
	return 0;

} // end main()

// �ڷᱸ���� ������ǥ�� ���α׷��� ���� !!!!!