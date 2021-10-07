#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환
#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock .. 시간, 날짜 함수

#pragma warning(disable:4996)

#include "Heap.h"

// 도우미 함수

//노드 인덱스 계산 매크로 ( 성능  UP )

// 부모 인덱스
#define GET_PARENT_IDX(idx) ( (idx) >> 1) // == idx / 2

// left 자식 인덱스
#define GET_LEFT_IDX(idx) ( (idx) << 1 )  // == idx *2

// right 자식 인덱스
//int GET_RIGHT_IDX(int idx) { return idx * 2 + 1; }
#define GET_RIGHT_IDX(idx) ( ((idx) << 1) + 1 )  // == idx *2 + 1

// 비교 함수 대신  매크로 사용 
#define COMP_ASC(d1,d2) ((d2)-(d1))		//오름 차순 

// delete 동작시
// 우선순위가 높은 자식의 인덱스 값 리턴

int getHighPriority(Heap *ph, int idx)
{
	// 자식노드가 없으면 0 리턴
	if (GET_LEFT_IDX(idx) > ph->numData)
		return 0;

	// 자식이 왼쪽 하나밖에 없다면 left 리턴
	if (GET_LEFT_IDX(idx) == ph->numData)
		return GET_LEFT_IDX(idx);

	// left vs right 비교
	if (COMP_ASC(
		ph->heapArr[GET_LEFT_IDX(idx)],
		ph->heapArr[GET_RIGHT_IDX(idx)]) < 0)

		return GET_RIGHT_IDX(idx);   // 오른쪽 우선순위가 높다
	else

		return GET_LEFT_IDX(idx);    // 왼쪽 우선순위가 높다(같거나)
}

void heap_init(Heap *ph, int len)
{
	ph->numData = 0;
	ph->heapArr = (int*)malloc(sizeof(int) * (len + 1)); // +1 개 만큼 추가
	g_hp = ph; // 힙 정렬에필요
}

// 삭제 해주는거
void heap_destroy(Heap *ph)
{
	free(ph->heapArr);
	ph->heapArr = NULL;
	ph->numData = 0;
	g_hp = NULL;
}

// 힙이 비어있나요?

int heap_is_empty(Heap *ph)
{
	if (ph->numData == 0)
		return SUCCESS;

	else
		return FAIL;
}

// 힙에 데이터 추가
void heap_insert(Heap *ph, HData data)
{
	int idx = ph->numData + 1;   // 배열 끝+1번째 일단 위치
	while (idx != 1)
	{
		if (COMP_ASC(data, ph->heapArr[GET_PARENT_IDX(idx)]) > 0)  // 부모보다 우선순위가 높다면
		{
			// 부모를 끌어 내리고
			ph->heapArr[idx] = ph->heapArr[GET_PARENT_IDX(idx)];
			idx = GET_PARENT_IDX(idx);   // idx 를 부모의 위치로 이동.
		}

		else   // 부모보다 우선순위가 같거나 작다면..
		{
			break;
		}
	} // end while

	ph->heapArr[idx] = data;  // 올라가다 멈춘 그곳! 

							// 새로운 데이터 insert 됨!
	ph->numData++;			// 데이터 개수 증가
}

// 힙에서 root 삭제 & 리턴
HData heap_delete(Heap *ph)
{
	HData retData = ph->heapArr[1];  // 인덱스 1번이 루트. 
	HData lastElem = ph->heapArr[ph->numData];  // numData 번째가 마지막 노드.

	int parentIdx = 1;
	int childIdx;

	// 자식 노드 중, 우선순위 높은거 선택
	// 자식이 하나도 없다면 while 문 종료

	while (childIdx = getHighPriority(ph, parentIdx))
	{
		// 선택된 자식(childIdx) 와 우선순위 비교
		// 만약 자식의 우선순위가 같거나 낮다면 while 종료

		if (COMP_ASC(lastElem, ph->heapArr[childIdx]) >= 0)
			break;

		// 자식의 우선순위가 더 크다면,  그 자식이 부모의 자리로 교체
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx; // 다음 비교를 위해 부모인덱스를 자식의 위치로 이동
	}

	// while 이 다 끝난 그 자리(parentIdx)가, 
	// 맨밑에서 올라왔던 노드가 새로 위치할 자리

	ph->heapArr[parentIdx] = lastElem;
	ph->numData--;

	return retData;   // 최초에 저장해놓은 root 데이터 리턴
}

// 힙 정렬 
void HeapSort(int arr[], int n)
{
	int i;
	// 힙 정렬 구현은 간단 
	// 다 insert 하고 , 다시 다 delete 하면 알아서 정렬됨 

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