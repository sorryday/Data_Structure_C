#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#include "wallet.h"
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.

/*������ ���*/			// ���
void wlt_init(wallet *p)// ���� �ʱ�ȭ
{
	printf("������ �ʱ�ȭ �մϴ�\n");
	p->bill1000 = 0;
	p->coin500 = 0;
}
void wlt_put_coin(wallet *p, int coinnum)// ���� ����
{
	p->coin500 += coinnum;
	printf("���� %d �� ���ԵǾ� %d���� �Ǿ����ϴ�.\n", coinnum, p->coin500);
}
int wlt_take_coin(wallet *p, int coinnum)// ���� ����, ������ 2���ε� 3���� ���� �� ���� ��츦 ������ ����
{
	if (p->coin500 < coinnum)
	{
		printf("���� ������ �����Ͽ� %d���� ��� �� �� �����ϴ�.\n",coinnum);
		return Fall; // ���� ����
	}

	p->coin500 -= coinnum;
	printf("���� %d�� ���� �Ǿ� %d ���� �Ǿ����ϴ�.\n",
		coinnum, p->coin500);
	return Success;
}
void wlt_put_bill(wallet *p, int billnum)// ���� ����
{
	p->bill1000 += billnum;
	printf("���� %d�� �� ���� �Ǿ� %d���� �Ǿ����ϴ�.\n", billnum, p->bill1000);

}
int wlt_take_bill(wallet *p, int billnum)// ���� ���� , ���� ""			""				""
{
	if (p->bill1000 < billnum)
	{
		printf("���� ������ �����Ͽ� %d���� ��� �� �� �����ϴ�.\n", billnum);
		return Fall;
	}
	p->bill1000 -= billnum;
	printf("���� %d ���� ���� �Ǿ� %d���� �Ǿ����ϴ�.\n", billnum, p->bill1000);
}
int wlt_balance(wallet *p)// ���� �� �ܾ�Ȯ�� , �ܾ��� ������ ����
{

	return (p->bill1000 * 1000) + (p->coin500 * 500);
}
