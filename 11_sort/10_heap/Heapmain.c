#include <stdio.h>

#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ

#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�

#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�

#include <time.h>    // clock .. �ð�, ��¥ �Լ�

#pragma warning(disable:4996)

#include "Heap.h"



int compPriority(HData d1, HData d2)

{

	return d2 - d1;   // min-heap ���� ����

	//return d1 - d2;   // max-heap ���� ����

}



int main(int argc, char **argv)

{

	Heap heap;

	heap_init(&heap, compPriority);



	heap_insert(&heap, 9);

	heap_insert(&heap, 20);

	heap_insert(&heap, 76);

	heap_insert(&heap, 30);

	heap_insert(&heap, 1000);

	heap_insert(&heap, 200);

	heap_insert(&heap, -30);

	// -30 9 20 30 76 200 1000

	while (!heap_is_empty(&heap))

		printf("%d ", heap_delete(&heap));  // delete ���� �ָ�









	printf("\n�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�\n");

	_getch();

	return 0;

} // end main()