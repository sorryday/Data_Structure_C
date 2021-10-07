#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
#define Max_Leng 4

typedef struct IterArray
{
	int arr[Max_Leng];
	int curPosition;	//iterate ���� (iterate���� ���� ������ �� �� ���� ����Ŵ.)
}IterArray;

//iterator �ʱ�ȭ
void iter_init(IterArray *p)
{
	printf("Iterator �ʱ�ȭ\n");
	p->curPosition = -1;	// iterate�� ���� �� �� �ε����� Ȱ�� �� ������ ��ĭ ������ �ؼ� �ʱ�ȭ ���ִ°��� ����.!!!!
}

// ���� ������ �����Ͱ� �ֳ���??
int iter_hasNext(IterArray *p)
{
	if (p->curPosition + 1 < Max_Leng) 
	{
		return 1; // ���� �����Ͱ� ����.
	}
	else
	{
		printf("���̻� ������ �����Ͱ� �����ϴ�.\n");
		return 0; // ���� , ���� �����Ͱ� ����.
	}
}
// ���� �����͸� �����ϳ���?
int iter_next(IterArray *p)
{
	p->curPosition++; // position �� next�� �̵�
	return p->arr[p->curPosition];
}

int main(int argc , char**argv)
{
	IterArray data = { {10, 20, 30, 40}, -1}; // ���� iterate�� ��� ��ȸ�� ������
	iter_init(&data);

	while (iter_hasNext(&data))			// ����� : ������ �� break ����Ʈ�� �ɾ� ���α׷��� ���� ���¸� �� �� �ִ� ��� 
	{
		printf("%d ", iter_next(&data));
	}
	printf("\n");

	printf("�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	_getch();
	return 0;
}