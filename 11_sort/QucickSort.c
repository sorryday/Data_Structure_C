#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환
#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock .. 시간, 날짜 함수

#pragma warning(disable:4996)

#include "QuickSort.h"

void QuickSort(int arr[], int left, int right) // 재귀적으로 퀵정렬 수행
{
	if (left <= right)
	{
		int pivot = partition(arr, left, right);	// 둘로 쪼갤 위치 선정
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int partition(int arr[], int left, int right) // 배열 정렬 영역 쪼갤 지점을 리턴 
{
	// left, right ,low, high는 인덱스  , pivot은 값 .
	int pivot = arr[left];// pivot의 값으 가장 왼쪽의 값 .
	int low = left + 1;
	int high = right;

	// low , high 이동 ..
	while (low <= high) // 교차되기 전까지 반복 이동 
	{
		// 1.pivot 보다 큰 것을 만날때 까지 low 우측으로 이동 
		while (pivot >= arr[low] && low <= right)
		{
			low++;
		}

		// 2. pivot 보다 작은 것을 만날때 까지 high 는 좌측으로이동 
		while (pivot <= arr[high] && high >= (left) + 1)
		{
			high--;
		}

		if (low <= high) // 교차되지 않은 상태 라면
		{
			Swap(arr, low, high); // low 와 high가 가리키는 대상을 교환 
		}

	}//end while

	// pivot 과 high가 가리키는 값 교환
	Swap(arr, left, high);

	// 이 시점에서 high 우측에는 pivot보다 큰 값들이 , high 좌측에는 pivot보다 작은 값들이 위치함. 
	// pivot 값의 정렬 위치는 확정 !!!! 

	return high; // pivot 값이 자리잡은 그 위치가 쪼개지는 지점.
}

void Swap(int arr[], int idx1, int idx2) // 배열 두개값 바꾸기 
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

void QuickSortMain(int arr[], int n) // main() 에서 사용할 함수 
{
	QuickSort(arr, 0, n - 1);
}