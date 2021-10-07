#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
#include "LinkedListStruct.h"

/*
	
*/
// 데이터 출력
void printData(Data *pData)
{
	printf("%s/%d살/%c, ",
		pData->szName, pData->age, pData->grade);
}

// 리스트 출력
void printList(List *pList)
{
	list_init_iter(pList);  // iteration 초기화
	printf("[");
	while (list_hasNext(pList))
	{
		printData(list_next(pList));
	}
	printf("]\n");
}

int main(int argc, char **argv)
{
	Data stu[] = {
		{"홍길동", 20, 'A'},
		{"김지원", 34, 'B'},
		{"허준", 30, 'D'},
		{"제시현", 23, 'E'},
		{"박수찬", 77, 'C'},
		{"마이클", 38, 'C'}
	};

	List myList;
	list_init(&myList);    // 리스트 생성 & 초기화

	// 데이터 추가
	printList(&myList);
	list_add(&myList, stu + 0);   //  stu + 0 ↔ &stu[0]
	printList(&myList);
	list_add(&myList, stu + 1);
	printList(&myList);
	list_add(&myList, stu + 2);
	printList(&myList);
	list_add(&myList, stu + 3);
	printList(&myList);
	list_add(&myList, stu + 4);
	printList(&myList);

	// 데이터 수정
	list_set(&myList, 0, stu + 5);
	list_set(&myList, 2, stu + 5);
	printList(&myList);

	// 데이터 개수
	printf("데이터 개수는 %d\n", list_length(&myList));

	// 데이터 조회 
	Data data;
	if (list_get(&myList, 0, &data))  printData(&data);
	if (list_get(&myList, 6, &data))  printData(&data);
	if (list_get(&myList, 4, &data))  printData(&data);
	printf("\n");

	// 데이터 삭제
	//list_remove(&myList, 0);
	//list_remove(&myList, 3);
	//printList(&myList);
	//list_remove(&myList, 0);
	//list_remove(&myList, 1);
	//printList(&myList);
	//list_remove(&myList, 0);
	//list_remove(&myList, 0);  // 지울게 없다
	//printList(&myList);    // empty list


	list_destroy(&myList);  // 리스트 제거

	printf("\n아무키나 입력하시면 프로그램이 종료됩니다\n");
	_getch();
	return 0;
} // end main()