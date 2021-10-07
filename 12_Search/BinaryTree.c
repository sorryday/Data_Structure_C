#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
#include "BinaryTree.h"
#include "ListQueue.h"
/* BINARY Tree 동작*/

// 트리 노드 생성
BTreeNode *btree_make_node()
{
	BTreeNode *newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->pLeft = NULL;
	newNode->pRight = NULL;
	newNode->data = 0;
}

// 특정 노드 데이터 읽기
BTData btree_Get_data(BTreeNode *bt)
{
	return bt->data;
}

// 노드에 데이터 쓰기
void btree_set_data(BTreeNode *bt, BTData data)
{
	bt->data = data;  
}

// left sub tree , right sub tree 정보를 가져오기
BTreeNode * btree_get_left(BTreeNode *bt)
{
	return bt->pLeft;
}
BTreeNode * btree_get_right(BTreeNode *bt)
{
	return bt->pRight;
}

// left에 sub tree 연결하기 , right에 sub tree 연결하기 
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

//트리 삭제 ( 특정 노드를 기준 ) , !!! 트리를 지울 때 자기자신을 지우기 전에 left, right 부터 지워야함.
void btree_delete(BTreeNode *bt)
{
	if (bt == NULL)
		return;

	btree_delete(bt->pLeft);		// left 삭제
	btree_delete(bt->pRight);		// Right 삭제

	printf("노드 삭제 : %d\n", bt->data);	// 삭제 확인 용 
	free(bt);		// 자기자신 삭제
}

//Traverse
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action)
{
	if (bt == NULL)
	{
		return; // 재귀종료
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
		return; // 재귀종료
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
		return; // 재귀종료
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

	//먼저 root를 enq
	queue_enq(&q, bt);

	while (!queue_is_empty)
	{
		// 1.dequeue하여 visit
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