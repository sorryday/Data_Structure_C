#pragma once /// ifndef �� ���� �������.
/*
	������ �߻� �ڷ���
*/

/*������ ������ */
#define Success 1
#define Fall 0

typedef struct wallet		//�ڷ�
{
	int coin500; //500�� ���� ����
	int bill1000; // 1000�� ���� ����.
	
}wallet;

/*������ ���*/			// ���
void wlt_init(wallet *p);// ���� �ʱ�ȭ
void wlt_put_coin(wallet *p, int coinnum);// ���� ����
int wlt_take_coin(wallet *p, int coinnum);// ���� ����, ������ 2���ε� 3���� ���� �� ���� ��츦 ������ ����
void wlt_put_bill(wallet *p, int billnum);// ���� ����
int wlt_take_bill(wallet *p, int billnum);// ���� ���� , ���� ""			""				""
int wlt_balance(wallet *p);// ���� �� �ܾ�Ȯ�� , �ܾ��� ������ ����
