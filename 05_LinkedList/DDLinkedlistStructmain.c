#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�
#pragma warning(disable:4996)
#include "DLinkedListStruct.h"

	/*

	*/
	// ������ ���
	void printData(Data *pData)
	{
		printf("%s/%d��/%c, ",
			pData->szName, pData->age, pData->grade);
	}

	// ����Ʈ ���
	void printList(List *pList)
	{
		list_init_iter(pList);  // forwarding iteration �ʱ�ȭ
		printf("[");
		while (list_hasNext(pList))
		{
			printData(list_next(pList));
		}
		printf("]");

		list_init_backward(pList); // ** backward iteration �ʱ�ȭ
		printf("[");
		while (list_hasPrev(pList))
		{
			printData(list_pPrev(pList));
		}
		printf("]\n");
	}

	int main(int argc, char **argv)
	{
		Data stu[] = {
			{"ȫ�浿", 20, 'A'},
			{"������", 34, 'B'},
			{"����", 30, 'D'},
			{"������", 23, 'E'},
			{"�ڼ���", 77, 'C'},
			{"����Ŭ", 38, 'C'}
		};

		List myList;
		list_init(&myList);    // ����Ʈ ���� & �ʱ�ȭ

		// ������ �߰�
		printList(&myList);
		list_add(&myList, stu + 0);   //  stu + 0 �� &stu[0]
		printList(&myList);
		list_add(&myList, stu + 1);
		printList(&myList);
		list_add(&myList, stu + 2);
		printList(&myList);
		list_add(&myList, stu + 3);
		printList(&myList);
		list_add(&myList, stu + 4);
		printList(&myList);

		// ������ ����
		list_set(&myList, 0, stu + 5);
		list_set(&myList, 2, stu + 5);
		printList(&myList);

		// ������ ����
		printf("������ ������ %d\n", list_length(&myList));

		// ������ ��ȸ 
		Data data;
		if (list_get(&myList, 0, &data))  printData(&data);
		if (list_get(&myList, 6, &data))  printData(&data);
		if (list_get(&myList, 4, &data))  printData(&data);
		printf("\n");

		// ������ ����
		//list_remove(&myList, 0);
		//list_remove(&myList, 3);
		//printList(&myList);
		//list_remove(&myList, 0);
		//list_remove(&myList, 1);
		//printList(&myList);
		//list_remove(&myList, 0);
		//list_remove(&myList, 0);  // ����� ����
		//printList(&myList);    // empty list


		list_destroy(&myList);  // ����Ʈ ����

		printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�\n");
		_getch();
		return 0;
	} // end main()

