#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환
#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock .. 시간, 날짜 함수
#include "BinarySearchTree.h"

#pragma warning(disable:4996)

void printNode(BTData data)
{
	printf("%d\n", data);
}

int main(int argc, char**argv)
{
	BTreeNode *pRoot; // bst의 root

	bst_make_init(&pRoot); // bst 초기화

	bst_insert(&pRoot, 12);
	bst_insert(&pRoot, 8);
	bst_insert(&pRoot, 17);
	
	btree_levelorder_traverse(pRoot, printNode);

	//printf("%d\n",bst_search(pRoot, 5)->data);
	btree_delete(&pRoot);  // bst 삭제

	return 0;
}
