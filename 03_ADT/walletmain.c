#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include <conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include <time.h>  //clock ... 시간 날짜 함수 ..
#include "wallet.h"
#pragma warning (disable:4996) // 4996에러 무시하는 헤더.
int main(int argc , char**argv)
{
	wallet mywallet; // 지갑 데이터 생성.

	wlt_init(&mywallet); // 지갑 초기화
	wlt_put_coin(&mywallet, 2); // 동전 삽입 : 500*2
	wlt_put_bill(&mywallet, 1); // 지폐 삽입 : 1000*1

	printf("잔액 확인 : %d \n", wlt_balance(&mywallet));

	printf("잔액 %d\n", wlt_balance(&mywallet));

	wlt_take_coin(&mywallet, 2);
	wlt_take_bill(&mywallet, 2);

	printf("잔액 : %d\n", wlt_balance(&mywallet));

	_getch();
	return 0;
}