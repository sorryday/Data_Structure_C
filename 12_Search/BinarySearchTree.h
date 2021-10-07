#ifndef  __BST_H__
#define  __BST_H__

#include "BinaryTree.h"

#define SUCCESS 1
#define FAIL 0

//최초 이진 탐색 트리의 생성 및 초기화
void bst_make_init(BTreeNode **ppRoot);

// 이진 탐색 트리를 대상으로 데이터 저장 (insert)
int bst_insert(BTreeNode **ppRoot, BTData data);

// 이진 탐색 트리를 대상으로 데이터 탐색 (search)
BTreeNode *bst_search(BTreeNode *pRoot, BTData data);

#endif // ! __BST_H__
