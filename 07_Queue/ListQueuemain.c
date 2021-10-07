#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#include "ListQueue.h"
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
// 오류 있음... 5만 나오는걸로 봐선 1,2,3,4가 들어가긴 하지만 하나의 노드에 덮어쓰이는것 같음
int main(int argc , char**argv)
{
	// Queue 생성 및 초기화

	Queue q;
	Data data;

	queue_init(&q); // 큐 초기화

	// 데이터 넣기 == enqueue
	queue_enq(&q, 1);
	queue_enq(&q, 2);
	queue_enq(&q, 3);
	queue_enq(&q, 4);
	queue_enq(&q, 5);

	// 데이터 꺼내기 == dequeue
	while (!queue_is_empty(&q))
	{
		
		queue_deq(&q, &data);
		printf("%d ", data);
	}

	queue_destroy(&q); // 큐 제거 


	printf("아무키나 입력하시면 프로그램이 종료됩니다.\n");
	_getch();
	return 0;

}