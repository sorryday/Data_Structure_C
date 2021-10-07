#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�
#include "LinkedListStruct.h"
#include "BinarySearchTree.h"
#pragma warning(disable:4996)

//���� ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode **ppRoot)
{
	*ppRoot = NULL;
}
// ���� Ž�� Ʈ���� ������� ������ ���� (insert)
int bst_insert(BTreeNode **ppRoot, BTData data)
{
	BTreeNode *parentNode = NULL; // �θ� ���
	BTreeNode *CurNode = *ppRoot; // currnet node : �ϴ� root���� ����.
	BTreeNode *newNode = NULL; // ���� ������ ��� 

	// ���ο� ��尡 �߰��� ��ġ�� ã�Ƽ� -->�θ� ��带 ã�ٴٴ� �ǹ�.
	while (CurNode != NULL)
	{
		if (data == btree_Get_data(CurNode))
			return FAIL; // BST�� ������ �ߺ��� ������� ����.

		parentNode = CurNode; // �ϴ� �θ��带 current�� ���� 

		if (btree_Get_data(CurNode) > data) // �����Ϸ��� data�� �� �۴ٸ� left���̵�
			CurNode = btree_get_left(CurNode);

		else                                // �����Ϸ��� data�� �� �۴ٸ� left
			CurNode = btree_get_right(CurNode);
	}//while

	// while ���� ���� ���� ���� ����尡 ���Ե� parent�� ������.
	// ��! ù��° ����� ��� parent�� NULL�� ��������.

	// �� ��� ����
	newNode = btree_make_node; // �� ��� ����
	btree_set_data(newNode, data);// �� ��忡 ������ ����

	// parentNode �� ����� �߰� 
	if (parentNode != NULL)
	{
		if (data < btree_Get_data(parentNode))
			btree_make_left(parentNode, newNode);

		else
			btree_make_right(parentNode, newNode);
	}
	else     // �� ��尡 root ��尡 �Ǵ� ���
	{
		*ppRoot = newNode; // root ���� ����
	}
	return SUCCESS;
}

// ���� Ž�� Ʈ���� ������� ������ Ž�� (search)
BTreeNode *bst_search(BTreeNode *pRoot, BTData data)
{
	BTreeNode *CurNode = pRoot; //root ���� Ž�� ����
	BTData CurData; // curNode�� ������ 
	
	while (CurNode != NULL)
	{
		CurData = btree_Get_data(CurNode);

		if (data == CurData)
			return CurNode; // Ž�� ���� !! ��� ���� 

		if (data < CurData)			// curNode ���� ������ left�� �̵�
			CurNode = btree_get_left(CurNode);

		else if (data >CurData)                       // curNode ���� ������ left�� �̵�
			CurNode = btree_get_right(CurNode);
	}
	return NULL; // �����͸� ��ã�Ҵٴ� �ǹ� .
}