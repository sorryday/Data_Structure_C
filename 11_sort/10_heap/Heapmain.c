#include <stdio.h>

#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환

#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수

#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수

#include <time.h>    // clock .. 시간, 날짜 함수

#pragma warning(disable:4996)

#include "Heap.h"



int compPriority(HData d1, HData d2)

{

	return d2 - d1;   // min-heap 으로 동작

	//return d1 - d2;   // max-heap 으로 동작

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

		printf("%d ", heap_delete(&heap));  // delete 순서 주목









	printf("\n아무키나 입력하시면 프로그램이 종료됩니다\n");

	_getch();

	return 0;

} // end main()