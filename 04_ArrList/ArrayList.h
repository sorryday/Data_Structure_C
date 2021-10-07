#pragma once /// ifndef 와 같은 기능을함.
#define _ARRAY_LISTH__
#define Success 1
#define Fail 0
/*ArrayList 의 ADT ( 추상 데이터 타입 ) */

typedef int Data;	//데이터는 int 

#define List_Len 4
typedef struct _ArrayList
{
	Data arr[List_Len];		// 데이터(들) 
	int numdata;			//list 안의 현재 데이터 개수
	int curPosition;			//iteration
}_ArrayList;

typedef _ArrayList List;

// 리스트 초기화

void list_init(List * pList);

// 리스트 제거.
void list_distory(List*pList);
// 데이터 추가
int list_add(List * pList, Data data);
// N번째 데이터 삭제
int list_remove(List * pList, int n);
// 데이터 수정
int list_set(List*pList, int n, Data data);
//n번째를 data로 수정

// 데이터 현개 개수를 리턴
int list_length(List *pList);


// 데이터 조회(iteration) : 초기화
void list_init_iter(List * pList);
// 데이터 조회 : 다음 데이터가 존재하나?
int list_hasNext(List*pList);
// 데이터 조회 : 다음 데이터를 추출
Data list_next(List*pList);
// 데이터 조회 : n번째 데이터 값 읽기.
int list_get(List*pList, int n, Data *pData);  // 예외사항이 항상 있기 때문에 경우의 수를 항상 생각해야함.
int list_remove(List*pList, int n);