#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
#include "LinkedListStruct.h"

// 리스트 초기화
void list_init(List* pList)
{
	// head 용 dummy node
	pList->pHead = (Node*)malloc(sizeof(Node));
	memset(pList->pHead, 0, sizeof(Node));  // Node 초기화.

	pList->pTail = pList->pHead;   // 최초에는 tail 과 head 동일

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

	//  free(pPrev->pData);  // 데이터 삭제
		free(pPrev);         // 노드 삭제
		cnt++;
	}

	// dummy node 삭제
	free(pList->pHead);

	pList->pHead = NULL;
	pList->pTail = NULL;
	pList->numData = 0;
	printf("리스트 제거 %d 개의 node 삭제\n", cnt);
}

// 데이터 data 추가 ★데이터는 포인터로
int list_add(List* pList, Data data)
{
	// 새로운 Node 생성
	Node *pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));

	pNewNode->data = data;

	// tail 이 가리키던 next 를 새로운 node 에 연결
	pList->pTail->pNext = pNewNode;

	// tail 이동
	pList->pTail = pNewNode;

	// printf("[%d] 번째 데이터 %s 추가\n", pList->numData, pData->szName);
	(pList->numData)++;
	return SUCCESS;
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
Data list_next(List* pList)
{
	pList->pCurrent = pList->pCurrent->pNext;  // 먼저 current 이동
	return pList->pCurrent->data;
}

// n번째를 data로 수정 ★데이터는 포인터
int list_set(List* pList, int n, Data data)
{
	if (n >= pList->numData)
	{
		printf("수정실패: %d 번재 데이터 수정 실패\n", n);
		return FAIL;
	}

	pList->pCurrent = pList->pHead->pNext;  // 첫번째 노드부터 시작
	int i;
	for (i = 0; i < n; i++)  // n 번째를 찾아서~~
		pList->pCurrent = pList->pCurrent->pNext;  // 다음.. 다음...

	// 위 for문이 끝나면 current 는 n번재 node 를 가리키고 있다
	// 데이터 수정
	
	pList->pCurrent->data = data;

	//printf("%d 번째 데이터 수정\n", n);
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

	// n번째 node 찾아가기
	pList->pCurrent = pList->pHead->pNext;
	int i;
	for (i = 0; i < n; i++)
		pList->pCurrent = pList->pCurrent->pNext;

	// data에 n번째 노드값 담아주기
	*pData = pList->pCurrent->data;

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

	// LinkedList 에서 n번째 노드 삭제 동작을 하려면
	// current 뿐 아니라 prev(직전) 노드도 알고 있어야 한다
	int i;
	pList->pCurrent = pList->pHead->pNext;
	Node *pPrev = pList->pHead;   // <-- prev 는 dummy node 부터 시작

	for (i = 0; i < n; i++)
	{
		pPrev = pList->pCurrent;
		pList->pCurrent = pList->pCurrent->pNext;
	}

	// for 문이 끝나면
	// current 는 n번째, prev 는 n-1 번째 가리킴

	// 삭제가 매우 단순!!!!!  (배열 리스트에 비해 매우 빠름, 간단)
	pPrev->pNext = pList->pCurrent->pNext;

	// 만약 tail이 삭제 노드 였다면.  
	// tail 값 수정해야 함. --> prev(직전) 노드로..
	if (pList->pCurrent == pList->pTail)
		pList->pTail = pPrev;

	// node 와 data 동적 할당 해제
	// free(pList->pCurrent->pData);    // 데이터 삭제 먼저

	free(pList->pCurrent);           // 노드 삭제

	pList->numData--;   // 리스트 데이터 개수 감소
	//printf("%d 번째 데이터 삭제\n", n);
	return SUCCESS;
}

// 주어진 pList에서 특정 데이터가 담긴 노드를 탐색해서 리턴하는 함수
// 없으면 NULL 리턴 
Node *list_search(List *pList, int data)
{

	pList->pCurrent = pList->pHead;
	while (pList->pCurrent->pNext != NULL)
	{
		pList->pCurrent = pList->pCurrent->pNext;
		if (pList->pCurrent->data == data)
			return pList->pCurrent;   // 데이터 값과같다면 탐색 good , 노드리턴 
	}

	//int d;
	//list_init_iter(pList);
	//while (list_hasNext(pList))
	//{
	//	d = list_next(pList); // Node의 data값을 d에 담음.
	//	if (d == data)  // 찾으려는 데이터와 d의 값이 같다면
	//	{
	//		return pList->pCurrent; // 노드 포인터를 리턴 
	//	}
	//}
	return NULL; // data 값을 못찾으면 NULL 리턴 
}