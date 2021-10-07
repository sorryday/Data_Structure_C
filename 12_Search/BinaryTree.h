#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/* BINARY Tree 데이터 */
typedef int BTData;

typedef struct _bTreeNode 
{
	BTData data;
	struct _bTreeNode *pLeft; // left tree 노드
	struct _bTreeNode *pRight; // right tree 노드 
	
}BTreeNode;

/* BINARY Tree 동작*/

// 트리 노드 생성
BTreeNode *btree_make_node();

// 특정 노드 데이터 읽기
BTData btree_Get_data(BTreeNode *bt);

// 노드에 데이터 쓰기
void btree_set_data(BTreeNode *bt ,BTData data);

// left sub tree , right sub tree 정보를 가져오기
BTreeNode * btree_get_left(BTreeNode *bt);
BTreeNode * btree_get_right(BTreeNode *bt);

// left에 sub tree 연결하기 , right에 sub tree 연결하기 
void btree_make_left(BTreeNode *main, BTreeNode *sub);
void btree_make_right(BTreeNode *main, BTreeNode *sub);

// 트리 삭제(특정 노드 기준)
void btree_delete(BTreeNode *bt);

typedef void fnVisitNode(BTData data);	// 함수 타입 선언 ,각 노드를 visit 하고 수행할 함수 


//Traverse
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action);
void btree_inorder_traverse(BTreeNode *bt , fnVisitNode atcion);
void btree_postorder_traverse(BTreeNode *bt, fnVisitNode atcion);

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode atcion); // TODO

#endif 