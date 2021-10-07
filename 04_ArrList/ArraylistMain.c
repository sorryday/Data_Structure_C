#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#include "ArrayList.h" 
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.

/* 항상 프로그래밍 시 큰 구조를 만들고 세부적인것을 추가하는 것이 좋음.
   함수에서 인자를 받을 때 그 인자가 null인지 , 초기화가 되있는지 확인해야함 !!*/
// 디버깅 중 조사식에서 특정 변수를 볼 수 있음.

// 리스트 출력 도우미함수
void printfList(List*pList)
{
	list_init_iter(pList);	// iteration 초기화
	printf("[");
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}

	printf("]\n");
}

int main(int argc , char**argv)
{
		List myList;			//리스트
		list_init(&myList);		//리스트 생성, 초기화

		printfList(&myList);
		list_add(&myList, 100); //데이터 추가
		printfList(&myList);

		list_add(&myList, 50); //데이터 추가
		printfList(&myList);

		list_add(&myList, 100); //데이터 추가
		printfList(&myList);

		list_add(&myList, 20); //데이터 추가
		printfList(&myList);

		list_add(&myList, 45); //데이터 추가
		printfList(&myList);

		list_add(&myList, 170); //데이터 추가
		printfList(&myList);

		// 데이터 수정
		list_set(&myList, 0, 40);	// 0번째 데이터 값을 40으로 수정
		list_set(&myList, 1, 30);	// 1번째 데이터 값을 30으로 수정
		list_set(&myList, 4, 20);	// 수정 실패 : 4번째는 없음.. ( 0~3 )까지 존재 할 뿐 
		printfList(&myList);

		// 데이터 개수(length)
		printf("데이터 갯수는 %d\n", list_length(&myList));

		// 데이터 조회
		Data data;
		if (list_get(&myList, 0, &data))
			printf("0번째 : %d\n", data);
		if (list_get(&myList, 6, &data))
			printf("6번째 : %d\n", data);
		if (list_get(&myList, 2, &data))
			printf("2번째 : %d\n", data);

		// 데이터 삭제
		list_remove(&myList, 2);
		printfList(&myList);

		list_remove(&myList, 2);
		printfList(&myList);

		list_remove(&myList, 0);
		printfList(&myList);
		list_remove(&myList, 0);
		list_remove(&myList, 0);
		list_remove(&myList, 0);
		printfList(&myList);

		list_distory(&myList);	//리스트 제거

	printf("아무키나 입력하시면 프로그램이 종료됩니다.\n");
	_getch();
	return 0;
}