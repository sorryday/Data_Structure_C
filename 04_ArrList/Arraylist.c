#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
#include "ArrayList.h"

// 리스트 초기화

void list_init(List * pList)
{
	pList->numdata = 0; // 데이터의 개수 : 0개
	pList ->curPosition = -1;					// curposition은 0보다는 항상 한단계 적은 -1이 좋음.
	memset(pList->arr, 0, sizeof(pList->arr));	// 배열 초기화
	printf("리스트 초기화\n");
}
// 리스트 제거
void list_distory(List*pList)
{
	pList->numdata = 0;
	printf("리스트 제거 \n");
}

int list_add(List * pList, Data data) // int로 한이유  ? : 성공 or 실패 값을 반환하기 위해
{
	//리스트에 빈공간이 있는지 확인 ( 예외 처리 )
	if (pList->numdata >= 4)
	{
		printf("데이터 추가 불가 : 리스트에 빈 공간이 없습니다.\n");
		return 0;
	}

	pList->arr[pList->numdata] = data;
	printf("[%d]번째 데이터 %d가 추가가 되었습니다.\n", pList->numdata, data);
	(pList->numdata)++;
	return 1;

}


void list_init_iter(List * pList)	//데이터 초기화 
{
	pList->curPosition = -1;
}

int list_hasNext(List*pList)
{
	if (pList->curPosition + 1 < pList->numdata) // curPosition 값이 남아있는 데이터보다 작은경우
		return Success;							 // 아직 뽑아낼 수 있는 데이터가 있다는 말!!!.

	return Fail;
}

Data list_next(List*pList)
{
	pList->curPosition++;
	return pList->arr[pList->curPosition];
}

//n번째를 data로 수정
int list_set(List*pList, int n, Data data)
{
	if (n >= pList->numdata)
	{
		printf("%d 번째 데이터 수정 실패 \n",n);
		return Fail;
	}

	printf("%d 번째 데이터 수정 : %d --> %d\n", n, pList->arr[n], data);
	pList->arr[n] = data;
	return Success;
}

//데이터의 개수-> 리턴
int list_length(List *pList)
{
	return pList->numdata;
}

// 데이터 조회 , n번째 데이터 값 읽기
int list_get(List*pList, int n, Data *pData)
{
	if (n >= pList->numdata)
		return Fail;

	*pData = pList->arr[n];		// 데이터값 call by Reference 

}

// n번째 데이터 삭제
int list_remove(List*pList, int n)
{
	//배열이니까 중간 데이터 삭제 하면 뒤의 것들 당겨 와야함.
	if (n >= pList->numdata)
	{
		printf("%d 번째 데이터 삭제 실패 \n", n);
		return Fail;
	}

	int i;
	for (i = n; i < pList->numdata - 1; i++)
	{
		pList->arr[i] = pList->arr[i + 1];
	}

	pList->numdata--;	//리스트 length 감소
	printf("%d번째 데이터 삭제\n", n);
	return Success;
}