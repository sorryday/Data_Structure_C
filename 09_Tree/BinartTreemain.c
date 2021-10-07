#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#include "BinaryTree.h"
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.

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

// bt1�� �����ʹ�??
	printf("bt1 : %d\n", btree_Get_data(bt1));

// bt1�� left�� �����ʹ� ?
	printf("bt1-left ������ : %d\n", btree_Get_data(btree_get_left(bt1)));

// bt1�� left�� left�����ʹ�?
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
	printf("\n"); // ����� 1 2 3 4 5 6 �� ���;��� 

// ����
	btree_delete(bt1);

	printf("�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	_getch();
	return 0;
}