#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환
#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock .. 시간, 날짜 함수
#include "LinkedListStruct.h"
#include "BinarySearchTree.h"
#pragma warning(disable:4996)

//최초 이진 탐색 트리의 생성 및 초기화
void bst_make_init(BTreeNode **ppRoot)
{
	*ppRoot = NULL;
}
// 이진 탐색 트리를 대상으로 데이터 저장 (insert)
int bst_insert(BTreeNode **ppRoot, BTData data)
{
	BTreeNode *parentNode = NULL; // 부모 노드
	BTreeNode *CurNode = *ppRoot; // currnet node : 일단 root부터 시작.
	BTreeNode *newNode = NULL; // 새로 생성될 노드 

	// 새로운 노드가 추가될 위치를 찾아서 -->부모 노드를 찾겟다는 의미.
	while (CurNode != NULL)
	{
		if (data == btree_Get_data(CurNode))
			return FAIL; // BST는 데이터 중복을 허용하지 않음.

		parentNode = CurNode; // 일단 부모노드를 current로 세팅 

		if (btree_Get_data(CurNode) > data) // 삽입하려논 data가 더 작다면 left로이동
			CurNode = btree_get_left(CurNode);

		else                                // 삽입하려논 data가 더 작다면 left
			CurNode = btree_get_right(CurNode);
	}//while

	// while 문이 끝난 시점 에서 새노드가 삽입될 parent가 결정됨.
	// 단! 첫번째 노드인 경우 parent는 NULL로 남아있음.

	// 새 노드 생성
	newNode = btree_make_node; // 새 노드 생성
	btree_set_data(newNode, data);// 새 노드에 데이터 저장

	// parentNode 에 새노드 추가 
	if (parentNode != NULL)
	{
		if (data < btree_Get_data(parentNode))
			btree_make_left(parentNode, newNode);

		else
			btree_make_right(parentNode, newNode);
	}
	else     // 새 노드가 root 노드가 되는 경우
	{
		*ppRoot = newNode; // root 노드로 셋팅
	}
	return SUCCESS;
}

// 이진 탐색 트리를 대상으로 데이터 탐색 (search)
BTreeNode *bst_search(BTreeNode *pRoot, BTData data)
{
	BTreeNode *CurNode = pRoot; //root 부터 탐색 시작
	BTData CurData; // curNode의 데이터 
	
	while (CurNode != NULL)
	{
		CurData = btree_Get_data(CurNode);

		if (data == CurData)
			return CurNode; // 탐색 성공 !! 노드 리턴 

		if (data < CurData)			// curNode 보다 작으면 left로 이동
			CurNode = btree_get_left(CurNode);

		else if (data >CurData)                       // curNode 보다 작으면 left로 이동
			CurNode = btree_get_right(CurNode);
	}
	return NULL; // 데이터를 못찾았다는 의미 .
}