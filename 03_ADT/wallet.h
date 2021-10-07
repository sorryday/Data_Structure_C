#pragma once /// ifndef 와 같은 기능을함.
/*
	지갑의 추상 자료형
*/

/*지갑의 데이터 */
#define Success 1
#define Fall 0

typedef struct wallet		//자료
{
	int coin500; //500원 동전 개수
	int bill1000; // 1000원 지폐 개수.
	
}wallet;

/*지갑의 기능*/			// 기능
void wlt_init(wallet *p);// 지갑 초기화
void wlt_put_coin(wallet *p, int coinnum);// 동전 삽입
int wlt_take_coin(wallet *p, int coinnum);// 동전 추출, 동전이 2개인데 3개를 빼낼 수 없는 경우를 정수를 리턴
void wlt_put_bill(wallet *p, int billnum);// 지폐 삽입
int wlt_take_bill(wallet *p, int billnum);// 지폐 추출 , 지폐를 ""			""				""
int wlt_balance(wallet *p);// 지갑 내 잔액확인 , 잔액을 정수로 리턴
