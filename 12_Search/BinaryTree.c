#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
#include "BinaryTree.h"
#include "ListQueue.h"
/* BINARY Tree ����*/

// Ʈ�� ��� ����
BTreeNode *btree_make_node()
{
	BTreeNode *newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	newNode->data = 0;
}

// Ư�� ��� ������ �б�
BTData btree_Get_data(BTreeNode *bt)
{
	return bt->data;
}

// ��忡 ������ ����
void btree_set_data(BTreeNode *bt, BTData data)
{
	bt->data = data;  
}

// left sub tree , right sub tree ������ ��������
BTreeNode * btree_get_left(BTreeNode *bt)
{
	return bt->pLeft;
}
BTreeNode * btree_get_right(BTreeNode *bt)
{
	return bt->pRight;
}

// left�� sub tree �����ϱ� , right�� sub tree �����ϱ� 
void btree_make_left(BTreeNode *main, BTreeNode *sub)
{
	if (main->pLeft != NULL)
	{
		btree_delete(main->pLeft);
	}
		main->pLeft = sub;
}
void btree_make_right(BTreeNode *main, BTreeNode *sub)
{
	if (main->pRight != NULL)
	{
		btree_delete(main->pLeft);
	}
	main->pRight = sub;
}

//Ʈ�� ���� ( Ư�� ��带 ���� ) , !!! Ʈ���� ���� �� �ڱ��ڽ��� ����� ���� left, right ���� ��������.
void btree_delete(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	btree_delete(bt->pLeft);		// left ����
	btree_delete(bt->pRight);		// Right ����

	printf("��� ���� : %d\n", bt->data);	// ���� Ȯ�� �� 
	free(bt);		// �ڱ��ڽ� ����
}

//Traverse
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL)
	{
		return; // �������
	}

	// C->L->R
	action(bt->data);
	btree_preorder_traverse(bt->pLeft, action);
	btree_preorder_traverse(bt->pRight, action);
}

void btree_inorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL)
	{
		return; // �������
	}

	// L->C->R
	btree_inorder_traverse(bt->pLeft, action);
	action(bt->data);
	btree_inorder_traverse(bt->pRight, action);
}

void btree_postorder_traverse(BTreeNode *bt, fnVisitNode action) 
{
	if (bt == NULL)
	{
		return; // �������
	}

	// L->R->C
	btree_postorder_traverse(bt->pLeft, action);
	btree_postorder_traverse(bt->pRight, action);
	action(bt->data);
}

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	Queue q;

	queue_init(&q);

	//���� root�� enq
	queue_enq(&q, bt);

	while (!queue_is_empty)
	{
		// 1.dequeue�Ͽ� visit
		BTreeNode *btCurrent;
		queue_deq(&q, &btCurrent);
		action(btCurrent->data);

		// 2.left->enq
		if (btCurrent->pLeft != NULL)
			queue_enq(&q, btCurrent->pLeft);

		// 3. right-> enq	
		if (btCurrent->pRight != NULL)
			queue_enq(&q, btCurrent->pRight);
	}

	queue_destroy(&q);	
}