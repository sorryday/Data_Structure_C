#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환
#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock .. 시간, 날짜 함수
#pragma warning(disable:4996)
#include "DLinkedListStruct.h"

// 리스트 초기화
void list_init(List* pList)
{
	// head 와 tail에 dummy node 생성. ** 
	pList->pHead = (Node*)malloc(sizeof(Node));//**
	memset(pList->pHead, 0, sizeof(Node));  // **Node 초기화.

	pList->pTail = (Node *)malloc(sizeof(Node));//**
	memset(pList->pTail, 0, sizeof(Node));	//** tail 초기화 

	pList->numData = 0;
	printf("리스트 초기화\n");
}
// 리스트 제거
void list_destroy(List* pList)
{
	// Linked List 의 node 들 삭제
	pList->pCurrent = pList->pHead->pNext;

	int cnt = 0;   // 삭제된 node 개수
	while (pList->pCurrent != NULL)
	{
		Node *pPrev = pList->pCurrent;  // 삭제될 노드
		pList->pCurrent = pList->pCurrent->pNext;  // 지우전에 current 이동

		free(pPrev->pData);  // 데이터 삭제
		free(pPrev);         // 노드 삭제
		cnt++;
	}

	// dummy node 삭제
	free(pList->pHead);
	free(pList->pTail); //*** 

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("리스트 제거 %d 개의 node 삭제\n", cnt);
}

// 데이터 data 추가 ★데이터는 포인터로
int list_add(List* pList, Data *pData)
{
	// 새로운 Node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	// 데이터 생성
	pNewNode->pData = (Data*)malloc(sizeof(Data));
	memcpy(pNewNode->pData, pData, sizeof(Data));

	// 데이터 노트가 하나도 없을 때 와 한개 이상 있을 때 구분하여 동작.****
	if (pList->numData == 0) // <-- 데이터 노드가 한개도 없을 때.
	{
		pList->pHead->pNext = pNewNode;	
		pList->pTail->pPrev = pNewNode;
	}
	else                     // <-- 데이터 노드가 1개 이상 있을 때.
	{
		// tail 이 가리키던 next 를 새로운 node 에 연결
		pList->pTail->pPrev->pNext = pNewNode; // pptx의 (1)번
		pNewNode->pPrev = pList->pTail->pPrev;	// "" (2) 번
		pList->pTail->pPrev = pNewNode;		// "" (3)
	}

	printf("[%d] 번째 데이터 %s 추가\n", pList->numData, pData->szName);
	(pList->numData)++;
	return 1;	//오류 떠서 1로 바꿈 
}

// 데이터 조회 (iteration)  초기화
void list_init_iter(List* pList)
{
	pList->pCurrent = pList->pHead;  // current 는 dummy 부터 시작
}
// 데이터 조회 : 다음 데이터 있나?
int list_hasNext(List* pList)
{
	if (pList->pCurrent->pNext == NULL) // 다음 노드 존재 여부 체크
		return FAIL;

	return SUCCESS;  // 다음 노드 있어요~
}
// 데이터 조회 : 다음 데이터 추출 ★리턴값은 포인터로
Data *list_next(List* pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // 먼저 current 이동
	return pList->pCurrent->pData;
}
//** 백워드 방향 iteration
void list_init_backward(List* pList)// ** 백 워드 iteration 초기화 
{
	pList->pCurrent = pList->pTail;
}
int list_hasPrev(List* pList)	 // * 데이터 조회 : 이전 노드가 있나?
{
	if (pList->pCurrent->pPrev == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
Data *list_prev(List* pList)	//  * 데이터 조회 : 이전 노드 데이터 
{
	pList->pCurrent = pList->pCurrent->pPrev;	// 우선 current 이동
	return pList->pCurrent->pData;
}

int list_get(List* pList, int n, Data *pData)// 데이터 조회 : n번째 데이터 값 읽기
{
	//if (n >= pList->numData)
		//return 0;
	
	int i;
	if (n <= pList->numData / 2)
	{	// head 부터 찾기
		pList->pCurrent = pList->pHead->pNext; // 첫번째 노드부터 찾기 
		for (i = 0; i < n; i++)
		{
			pList->pCurrent = pList->pCurrent->pNext;
		}
	}
	else
	{   // tail 부터 찾기 
		pList->pCurrent = pList->pTail->pPrev; // 마지막 노드부터 찾기
		for (i = 0;i<pList->numData-n-1; i++)
		{
			pList->pCurrent = pList->pCurrent->pPrev;
		}
	}
}

// n번째를 data로 수정 ★데이터는 포인터
int list_set(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("수정실패: %d 번째 데이터 수정 실패\n", n);
		return FAIL;
	}
	List_move_current(pList, n); //current 이동 -> n 번째 노드 
	// 위 for문이 끝나면 current 는 n번재 node 를 가리키고 있다
	// 데이터 수정
	pList->pCurrent->pData->age = pData->age;
	pList->pCurrent->pData->grade = pData->grade;
	//pList->pCurrent->pData->szName = pData->szName;  // 배열(포인터 상수)이라 안된다
	strcpy(pList->pCurrent->pData->szName, pData->szName);  // 문자열 복사

	printf("%d 번째 데이터 수정\n", n);
	return SUCCESS;
}

// 데이터 개수 -> 리턴
int list_length(List* pList)
{
	return pList->numData;
}

// 데이터 조회 : n번째 데이터 값 읽기
int list_get(List* pList, int n, Data *pData)
{
	if (n >= pList->numData)
	{
		printf("%d 번재 데이터 없습니다\n", n);
		return FAIL;
	}

	list_move_current(pList, n);
	// data에 n번째 노드값 담아주기
	pData->age = pList->pCurrent->pData->age;
	pData->grade = pList->pCurrent->pData->grade;
	strcpy(pData->szName, pList->pCurrent->pData->szName);

	return SUCCESS;
}

// n번째 데이터 삭제
int list_remove(List* pList, int n)
{
	if (n >= pList->numData)
	{
		printf("%d 번째 데이터 삭제 실패\n", n);
		return FAIL;
	}

	list_move_current(pList, n); // n번째 노드로 이동
	
	// 이중연결리스트 는 current만 알아도 삭제가 편하다.
	if (pList->pCurrent->pPrev != NULL) // 첫번째 노드가 아닐 경우 
	{
		pList->pCurrent->pPrev->pNext = pList->pCurrent->pNext;
	}
	else 
	{
		pList->pHead->pNext = pList->pCurrent->pNext; // 첫번째 노드일 경우
	}
	
	if (pList->pCurrent->pNext != NULL) // 마지막노드가 아닐경우 .
	{
		pList->pCurrent->pNext->pPrev= pList->pCurrent->pPrev;
	}
	else
	{
		pList->pTail->pPrev = pList->pCurrent->pPrev; // 마지막 노드일 경우
	}
	// node 와 data 동적 할당 해제
	free(pList->pCurrent->pData);    // 데이터 삭제 먼저
	free(pList->pCurrent);           // 노드 삭제

	pList->numData--;   // 리스트 데이터 개수 감소
	printf("%d 번째 데이터 삭제\n", n);
	return SUCCESS;
}