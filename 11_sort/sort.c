#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�

#pragma warning(disable:4996)

#include "Sort.h"

void printArr(int arr[], int n)
{
	printf("[");

	int i;

	for (i = 0; i < n; i++)

		printf("%d,", arr[i]);

	printf("\b\n]");
}
// ������ �迭 0 ~ bound ������ ���� x n �� 

void genRandom(int arr[], int n, int bound)
{
	int i;
	srand(time(NULL));

	for (i = 0; i < n; i++)
	{
		arr[i] = rand() % bound + 1;
	}
}

// ���� ���� �迭 
void genIncSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		arr[i] = i;		// �������� �迭 ���� 
	}
}

// ����ð� üũ
void chkTimeLap(fnSort sort, int arr[], int n, char* title)
{
	clock_t  start, end;
	start = clock();
	sort(arr, n);   // ���� ����
	end = clock();

	printf("%s (size: %d) ������: %ld ms\n", title, n, end - start);
}

// ���� ����
void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++)  // ó������ n-1���� �񱳹߻�. �״������ʹ� n-2, n-3 ...  1��    
	{
		for (j = 0; j < (n - i) - 1; j++)
		{
			// ������ �ΰ� ��
			if (arr[j] > arr[j + 1])  // ũ�Ⱑ �ݴ���
			{                         // ��ȯ(swap)
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
		// �߰��ܰ� ���

		//printf("%d:", i);
		//printArr(arr, n);  //
		//printf("\n");
	}
}

// ��������
void SelectionSort(int arr[], int n)
{
	int L, j;
	int X;
	int temp;

	for (L = 0; L < n - 1; L++)  // L : 0 ~ N-2 ����
	{
		X = L;  // ���� ������ ���� �ռ��� �������� index ���� X ����

		// [L .. n - 1] �������� '���� ���� ���� ��ġ' ã�Ƽ� --> X 

		for (j = L + 1; j < n; j++)  // �ּڰ� Ž��
		{
			if (arr[X] > arr[j])  // Ȥ�� ������ X���� ������ �� ���� ���� �߰ߵǾ��ٸ�!  
				X = j;            // X �� �̹��� �߰��� �� ���� ���� ����Ű��!
		}

		// ���� for���� ������
		// X ����  L ��° ������ �����߿��� ���� ���� ���� ����Ű�� �ִ�.
		// �׷��� ���� L ��° ���� X ��° ���� ��ȯ �ϸ� �ȴ�.

		temp = arr[L];
		arr[L] = arr[X];
		arr[X] = temp;
	}
}

// ���� ����
void InsertionSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)   // i = 1���� ����!
	{
		insData = arr[i];   // i��° �����ʹ� insData�� �ӽ� ����

		for (j = i - 1; j >= 0; j--)  // i ���ʺ��� �������� �˻�
		{
			if (arr[j] > insData)   // insData ����  j��° �����Ͱ� ũ��
				arr[j + 1] = arr[j];    // j��° �����͸� �������� �̵�

			else
				break;   // ���� ��ġ ã������ Ż��!
		}

		arr[j + 1] = insData;  // ã�� ��ġ�� ���� ��� ����!
	}
}