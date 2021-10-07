#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#include "BinaryTree.h"
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.

void printData(BTData data)
{
	printf("DATA : %d ", data);
}

int main(int argc , char**argv)
{
	BTreeNode *bt1 = btree_make_node();
	BTreeNode *bt2 = btree_make_node();
	BTreeNode *bt3 = btree_make_node();
	BTreeNode *bt4 = btree_make_node();

	btree_set_data(bt1, 1);
	btree_set_data(bt2, 2);
	btree_set_data(bt3, 3);
	btree_set_data(bt4, 4);

	btree_make_left(bt1, bt2);
	btree_make_right(bt1, bt3);
	btree_make_left(bt2, bt4);

// bt1의 데이터는??
	printf("bt1 : %d\n", btree_Get_data(bt1));

// bt1의 left의 데이터는 ?
	printf("bt1-left 데이터 : %d\n", btree_Get_data(btree_get_left(bt1)));

// bt1의 left의 left데이터는?
	printf("bt1-left-left : %d \n", btree_Get_data(btree_get_left(btree_get_left(bt1))));

// traversing 
	printf("Preorder: ");
	btree_preorder_traverse(bt1,printData);
	printf("\n");

	printf("inorder: ");
	btree_inorder_traverse(bt1, printData);
	printf("\n");

	printf("posteorder: ");
	btree_postorder_traverse(bt1, printData);
	printf("\n\n");


	printf("Level-order : ");
	btree_levelorder_traverse(bt1, printData);
	printf("\n"); // 결과는 1 2 3 4 5 6 이 나와야함 

// 삭제
	btree_delete(bt1);

	printf("아무키나 입력하시면 프로그램이 종료됩니다.\n");
	_getch();
	return 0;
}