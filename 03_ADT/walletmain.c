#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include <conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include <time.h>  //clock ... �ð� ��¥ �Լ� ..
#include "wallet.h"
#pragma warning (disable:4996) // 4996���� �����ϴ� ���.
int main(int argc , char**argv)
{
	wallet mywallet; // ���� ������ ����.

	wlt_init(&mywallet); // ���� �ʱ�ȭ
	wlt_put_coin(&mywallet, 2); // ���� ���� : 500*2
	wlt_put_bill(&mywallet, 1); // ���� ���� : 1000*1

	printf("�ܾ� Ȯ�� : %d \n", wlt_balance(&mywallet));

	printf("�ܾ� %d\n", wlt_balance(&mywallet));

	wlt_take_coin(&mywallet, 2);
	wlt_take_bill(&mywallet, 2);

	printf("�ܾ� : %d\n", wlt_balance(&mywallet));

	_getch();
	return 0;
}