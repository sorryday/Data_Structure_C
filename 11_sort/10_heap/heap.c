#include <stdio.h>

#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환

#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수

#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수

#include <time.h>    // clock .. 시간, 날짜 함수

#pragma warning(disable:4996)

#include "Heap.h"



// 도우미 함수

// 부모 인덱스

int getParentIdx(int idx) { return idx / 2; }

// left 자식 인덱스

int getLeftIdx(int idx) { return idx * 2; }

// right 자식 인덱스

int getRightIdx(int idx) { return idx * 2 + 1; }



// delete 동작시

// 우선순위가 높은 자식의 인덱스 값 리턴

int getHighPriority(Heap *ph, int idx)

{

	// 자식노드가 없으면 0 리턴

	if (getLeftIdx(idx) > ph->numData)

		return 0;



	// 자식이 왼쪽 하나밖에 없다면 left 리턴

	if (getLeftIdx(idx) == ph->numData)

		return getLeftIdx(idx);



	// left vs right 비교

	if (ph->comp(

		ph->heapArr[getLeftIdx(idx)],

		ph->heapArr[getRightIdx(idx)]) < 0)

		return getRightIdx(idx);   // 오른쪽 우선순위가 높다

	else

		return getLeftIdx(idx);    // 왼쪽 우선순위가 높다(같거나)

}



// 힙초기화

void heap_init(Heap *ph, fnPriorityComp pc)

{

	ph->numData = 0;   // 데이터 개수 (노드 개수)

	ph->comp = pc;    // 비교함수

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

		if (ph->comp(data, ph->heapArr[getParentIdx(idx)]) > 0)  // 부모보다 우선순위가 높다면

		{

			// 부모를 끌어 내리고

			ph->heapArr[idx] = ph->heapArr[getParentIdx(idx)];

			idx = getParentIdx(idx);   // idx 를 부모의 위치로 이동.

		}

		else   // 부모보다 우선순위가 같거나 작다면..

		{

			break;

		}

	} // end while



	ph->heapArr[idx] = data;  // 올라가다 멈춘 그곳! 

							// 새로운 데이터 insert 됨!

	ph->numData++;   // 데이터 개수 증가

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

		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)

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