#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
#define Max_Leng 4

typedef struct IterArray
{
	int arr[Max_Leng];
	int curPosition;	//iterate 구현 (iterate에서 줄을 세웠을 때 맨 앞을 가리킴.)
}IterArray;

//iterator 초기화
void iter_init(IterArray *p)
{
	printf("Iterator 초기화\n");
	p->curPosition = -1;	// iterate를 구현 할 때 인덱스를 활용 할 때에는 한칸 전으로 해서 초기화 해주는것이 좋음.!!!!
}

// 다음 추출할 데이터가 있나요??
int iter_hasNext(IterArray *p)
{
	if (p->curPosition + 1 < Max_Leng) 
	{
		return 1; // 다음 데이터가 있음.
	}
	else
	{
		printf("더이상 추출할 데이터가 없습니다.\n");
		return 0; // 실패 , 다음 데이터가 없음.
	}
}
// 다음 데이터를 추출하나요?
int iter_next(IterArray *p)
{
	p->curPosition++; // position 을 next로 이동
	return p->arr[p->curPosition];
}

int main(int argc , char**argv)
{
	IterArray data = { {10, 20, 30, 40}, -1}; // 보통 iterate의 경우 일회성 데이터
	iter_init(&data);

	while (iter_hasNext(&data))			// 디버깅 : 컴파일 중 break 포인트를 걸어 프로그램의 동작 상태를 볼 수 있는 기능 
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	printf("아무키나 입력하시면 프로그램이 종료됩니다.\n");
	_getch();
	return 0;
}