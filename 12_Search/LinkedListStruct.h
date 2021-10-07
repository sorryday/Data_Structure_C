#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/*
	LinkedList 의 ADT
*/
#define SUCCESS 1
#define FAIL 0

typedef int Data; // int 형으로 

// 노드 타입 정의
typedef struct _node
{
	Data data;    // 데이터 포인터
	struct _node *pNext;   // 다음 노드 포인터
} Node;

// Linked List 타입 정의
typedef struct _linkedlist
{
	Node *pHead;   // 시작 노드
	Node *pTail;   // 끝 노드

	Node *pCurrent;    // iteration 용
	int numData;     // 노드의 개수
} LinkedList;

typedef LinkedList List;

/* Linked List 의 동작 */
void list_init(List* pList);// 리스트 초기화
void list_destroy(List* pList);// 리스트 제거

int list_add(List* pList, Data data);// 데이터 data 추가 ★데이터는 포인터로
int list_remove(List* pList, int n);// n번째 데이터 삭제
int list_set(List* pList, int n, Data data);// n번째를 data로 수정 ★데이터는 포인터
int list_length(List* pList);// 데이터 개수 -> 리턴

void list_init_iter(List* pList);// 데이터 조회 (iteration)  초기화**
int list_hasNext(List* pList);// 데이터 조회 : 다음 데이터 있나?**
Data list_next(List* pList);// 데이터 조회 : 다음 데이터 추출 ★ **리턴값은 포인터로

int list_get(List* pList, int n, Data *pData);// 데이터 조회 : n번째 데이터 값 읽기

// current 이동 -> n번째 노드로 이동  **
int list_move_current(List *pList, int n);


// 주어진 pList에서 특정 데이터가 담긴 노드를 탐색해서 리턴하는 함수
// 없으면 NULL 리턴 
Node *list_search(List *pList, int data); 

#endif