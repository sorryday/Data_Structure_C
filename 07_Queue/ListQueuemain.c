#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#include "ListQueue.h"
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
// ���� ����... 5�� �����°ɷ� ���� 1,2,3,4�� ���� ������ �ϳ��� ��忡 ����̴°� ����
int main(int argc , char**argv)
{
	// Queue ���� �� �ʱ�ȭ

	Queue q;
	Data data;

	queue_init(&q); // ť �ʱ�ȭ

	// ������ �ֱ� == enqueue
	queue_enq(&q, 1);
	queue_enq(&q, 2);
	queue_enq(&q, 3);
	queue_enq(&q, 4);
	queue_enq(&q, 5);

	// ������ ������ == dequeue
	while (!queue_is_empty(&q))
	{
		
		queue_deq(&q, &data);
		printf("%d ", data);
	}

	queue_destroy(&q); // ť ���� 


	printf("�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	_getch();
	return 0;

}