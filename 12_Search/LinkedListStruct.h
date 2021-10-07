#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

/*
	LinkedList �� ADT
*/
#define SUCCESS 1
#define FAIL 0

typedef int Data; // int ������ 

// ��� Ÿ�� ����
typedef struct _node
{
	Data data;    // ������ ������
	struct _node *pNext;   // ���� ��� ������
} Node;

// Linked List Ÿ�� ����
typedef struct _linkedlist
{
	Node *pHead;   // ���� ���
	Node *pTail;   // �� ���

	Node *pCurrent;    // iteration ��
	int numData;     // ����� ����
} LinkedList;

typedef LinkedList List;

/* Linked List �� ���� */
void list_init(List* pList);// ����Ʈ �ʱ�ȭ
void list_destroy(List* pList);// ����Ʈ ����

int list_add(List* pList, Data data);// ������ data �߰� �ڵ����ʹ� �����ͷ�
int list_remove(List* pList, int n);// n��° ������ ����
int list_set(List* pList, int n, Data data);// n��°�� data�� ���� �ڵ����ʹ� ������
int list_length(List* pList);// ������ ���� -> ����

void list_init_iter(List* pList);// ������ ��ȸ (iteration)  �ʱ�ȭ**
int list_hasNext(List* pList);// ������ ��ȸ : ���� ������ �ֳ�?**
Data list_next(List* pList);// ������ ��ȸ : ���� ������ ���� �� **���ϰ��� �����ͷ�

int list_get(List* pList, int n, Data *pData);// ������ ��ȸ : n��° ������ �� �б�

// current �̵� -> n��° ���� �̵�  **
int list_move_current(List *pList, int n);


// �־��� pList���� Ư�� �����Ͱ� ��� ��带 Ž���ؼ� �����ϴ� �Լ�
// ������ NULL ���� 
Node *list_search(List *pList, int data); 

#endif