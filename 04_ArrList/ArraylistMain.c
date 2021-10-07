#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#include "ArrayList.h" 
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.

/* �׻� ���α׷��� �� ū ������ ����� �������ΰ��� �߰��ϴ� ���� ����.
   �Լ����� ���ڸ� ���� �� �� ���ڰ� null���� , �ʱ�ȭ�� ���ִ��� Ȯ���ؾ��� !!*/
// ����� �� ����Ŀ��� Ư�� ������ �� �� ����.

// ����Ʈ ��� ������Լ�
void printfList(List*pList)
{
	list_init_iter(pList);	// iteration �ʱ�ȭ
	printf("[");
	while (list_hasNext(pList))
	{
		printf("%d ", list_next(pList));
	}

	printf("]\n");
}

int main(int argc , char**argv)
{
		List myList;			//����Ʈ
		list_init(&myList);		//����Ʈ ����, �ʱ�ȭ

		printfList(&myList);
		list_add(&myList, 100); //������ �߰�
		printfList(&myList);

		list_add(&myList, 50); //������ �߰�
		printfList(&myList);

		list_add(&myList, 100); //������ �߰�
		printfList(&myList);

		list_add(&myList, 20); //������ �߰�
		printfList(&myList);

		list_add(&myList, 45); //������ �߰�
		printfList(&myList);

		list_add(&myList, 170); //������ �߰�
		printfList(&myList);

		// ������ ����
		list_set(&myList, 0, 40);	// 0��° ������ ���� 40���� ����
		list_set(&myList, 1, 30);	// 1��° ������ ���� 30���� ����
		list_set(&myList, 4, 20);	// ���� ���� : 4��°�� ����.. ( 0~3 )���� ���� �� �� 
		printfList(&myList);

		// ������ ����(length)
		printf("������ ������ %d\n", list_length(&myList));

		// ������ ��ȸ
		Data data;
		if (list_get(&myList, 0, &data))
			printf("0��° : %d\n", data);
		if (list_get(&myList, 6, &data))
			printf("6��° : %d\n", data);
		if (list_get(&myList, 2, &data))
			printf("2��° : %d\n", data);

		// ������ ����
		list_remove(&myList, 2);
		printfList(&myList);

		list_remove(&myList, 2);
		printfList(&myList);

		list_remove(&myList, 0);
		printfList(&myList);
		list_remove(&myList, 0);
		list_remove(&myList, 0);
		list_remove(&myList, 0);
		printfList(&myList);

		list_distory(&myList);	//����Ʈ ����

	printf("�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	_getch();
	return 0;
}