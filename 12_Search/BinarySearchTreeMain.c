#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�
#include "BinarySearchTree.h"

#pragma warning(disable:4996)

void printNode(BTData data)
{
	printf("%d\n", data);
}

int main(int argc, char**argv)
{
	BTreeNode *pRoot; // bst�� root

	bst_make_init(&pRoot); // bst �ʱ�ȭ

	bst_insert(&pRoot, 12);
	bst_insert(&pRoot, 8);
	bst_insert(&pRoot, 17);
	
	btree_levelorder_traverse(pRoot, printNode);

	//printf("%d\n",bst_search(pRoot, 5)->data);
	btree_delete(&pRoot);  // bst ����

	return 0;
}
