#ifndef  __BST_H__
#define  __BST_H__

#include "BinaryTree.h"

#define SUCCESS 1
#define FAIL 0

//���� ���� Ž�� Ʈ���� ���� �� �ʱ�ȭ
void bst_make_init(BTreeNode **ppRoot);

// ���� Ž�� Ʈ���� ������� ������ ���� (insert)
int bst_insert(BTreeNode **ppRoot, BTData data);

// ���� Ž�� Ʈ���� ������� ������ Ž�� (search)
BTreeNode *bst_search(BTreeNode *pRoot, BTData data);

#endif // ! __BST_H__
