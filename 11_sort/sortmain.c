#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환
#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock .. 시간, 날짜 함수

#pragma warning(disable:4996)

#include "Sort.h"
#include "Heap.h"
#include "QuickSort.h"

#define LEN 4000

int main(int argc, char **argv)
{
	//int srcArr[LEN] = {45, 21, 5, 36, 12}; // 원본배열

	int srcArr[LEN];

	genRandom(srcArr, LEN, LEN);  // 무작위 배열 

	//printArr(srcArr, LEN);

	int workArr[LEN];  // 작업용 배열

	/*
	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(BubbleSort, workArr, LEN, "버블정렬");
	//printArr(workArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(SelectionSort, workArr, LEN, "선택정렬");
	//printArr(workArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(InsertionSort, workArr, LEN, "삽입정렬");
	//printArr(workArr, LEN);

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	Heap hp;
	heap_init(&hp, LEN);
	chkTimeLap(HeapSort, workArr, LEN, "힙 정렬 ");
	heap_destroy(&hp);
	//printArr(workArr, LEN);

	*/
	// Quick Sort

	memcpy(workArr, srcArr, sizeof(int) * LEN);
	chkTimeLap(QuickSortMain, workArr, LEN, "퀵정렬");
	//printArr(workArr, LEN);

	// 오름 차순 배열로 퀵 정렬 성능 평가 
	genIncSorted(workArr, LEN); // 오름 차순 배열 생성 
	chkTimeLap(QuickSortMain, workArr, LEN, "퀵 오름 차순정렬");

	printf("\n아무키나 입력하시면 프로그램이 종료됩니다\n");
	_getch();
	return 0;

} // end main()

// 자료구조의 최종목표는 프로그램의 성능 !!!!!