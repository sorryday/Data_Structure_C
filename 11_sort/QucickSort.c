#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�

#pragma warning(disable:4996)

#include "QuickSort.h"

void QuickSort(int arr[], int left, int right) // ��������� ������ ����
{
	if (left <= right)
	{
		int pivot = partition(arr, left, right);	// �ѷ� �ɰ� ��ġ ����
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int partition(int arr[], int left, int right) // �迭 ���� ���� �ɰ� ������ ���� 
{
	// left, right ,low, high�� �ε���  , pivot�� �� .
	int pivot = arr[left];// pivot�� ���� ���� ������ �� .
	int low = left + 1;
	int high = right;

	// low , high �̵� ..
	while (low <= high) // �����Ǳ� ������ �ݺ� �̵� 
	{
		// 1.pivot ���� ū ���� ������ ���� low �������� �̵� 
		while (pivot >= arr[low] && low <= right)
		{
			low++;
		}

		// 2. pivot ���� ���� ���� ������ ���� high �� ���������̵� 
		while (pivot <= arr[high] && high >= (left) + 1)
		{
			high--;
		}

		if (low <= high) // �������� ���� ���� ���
		{
			Swap(arr, low, high); // low �� high�� ����Ű�� ����� ��ȯ 
		}

	}//end while

	// pivot �� high�� ����Ű�� �� ��ȯ
	Swap(arr, left, high);

	// �� �������� high �������� pivot���� ū ������ , high �������� pivot���� ���� ������ ��ġ��. 
	// pivot ���� ���� ��ġ�� Ȯ�� !!!! 

	return high; // pivot ���� �ڸ����� �� ��ġ�� �ɰ����� ����.
}

void Swap(int arr[], int idx1, int idx2) // �迭 �ΰ��� �ٲٱ� 
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void QuickSortMain(int arr[], int n) // main() ���� ����� �Լ� 
{
	QuickSort(arr, 0, n - 1);
}