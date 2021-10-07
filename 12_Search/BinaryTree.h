#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

/* BINARY Tree ������ */
typedef int BTData;

typedef struct _bTreeNode 
{
	BTData data;
	struct _bTreeNode *pLeft; // left tree ���
	struct _bTreeNode *pRight; // right tree ��� 
	
}BTreeNode;

/* BINARY Tree ����*/

// Ʈ�� ��� ����
BTreeNode *btree_make_node();

// Ư�� ��� ������ �б�
BTData btree_Get_data(BTreeNode *bt);

// ��忡 ������ ����
void btree_set_data(BTreeNode *bt ,BTData data);

// left sub tree , right sub tree ������ ��������
BTreeNode * btree_get_left(BTreeNode *bt);
BTreeNode * btree_get_right(BTreeNode *bt);

// left�� sub tree �����ϱ� , right�� sub tree �����ϱ� 
void btree_make_left(BTreeNode *main, BTreeNode *sub);
void btree_make_right(BTreeNode *main, BTreeNode *sub);

// Ʈ�� ����(Ư�� ��� ����)
void btree_delete(BTreeNode *bt);

typedef void fnVisitNode(BTData data);	// �Լ� Ÿ�� ���� ,�� ��带 visit �ϰ� ������ �Լ� 


//Traverse
void btree_preorder_traverse(BTreeNode *bt, fnVisitNode action);
void btree_inorder_traverse(BTreeNode *bt , fnVisitNode atcion);
void btree_postorder_traverse(BTreeNode *bt, fnVisitNode atcion);

void btree_levelorder_traverse(BTreeNode *bt, fnVisitNode atcion); // TODO

#endif 