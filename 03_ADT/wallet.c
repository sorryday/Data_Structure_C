#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#include "wallet.h"
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.

/*지갑의 기능*/			// 기능
void wlt_init(wallet *p)// 지갑 초기화
{
	printf("지갑을 초기화 합니다\n");
	p->bill1000 = 0;
	p->coin500 = 0;
}
void wlt_put_coin(wallet *p, int coinnum)// 동전 삽입
{
	p->coin500 += coinnum;
	printf("동전 %d 개 삽입되어 %d개가 되었습니다.\n", coinnum, p->coin500);
}
int wlt_take_coin(wallet *p, int coinnum)// 동전 추출, 동전이 2개인데 3개를 빼낼 수 없는 경우를 정수를 리턴
{
	if (p->coin500 < coinnum)
	{
		printf("동전 갯수가 부족하여 %d개를 출력 할 수 없습니다.\n",coinnum);
		return Fall; // 추출 실패
	}

	p->coin500 -= coinnum;
	printf("동전 %d개 추출 되어 %d 개가 되었습니다.\n",
		coinnum, p->coin500);
	return Success;
}
void wlt_put_bill(wallet *p, int billnum)// 지폐 삽입
{
	p->bill1000 += billnum;
	printf("지폐 %d개 가 삽입 되어 %d개가 되었습니다.\n", billnum, p->bill1000);

}
int wlt_take_bill(wallet *p, int billnum)// 지폐 추출 , 지폐를 ""			""				""
{
	if (p->bill1000 < billnum)
	{
		printf("지폐 갯수가 부족하여 %d개를 출력 할 수 없습니다.\n", billnum);
		return Fall;
	}
	p->bill1000 -= billnum;
	printf("지폐 %d 개가 추출 되어 %d개가 되었습니다.\n", billnum, p->bill1000);
}
int wlt_balance(wallet *p)// 지갑 내 잔액확인 , 잔액을 정수로 리턴
{

	return (p->bill1000 * 1000) + (p->coin500 * 500);
}
