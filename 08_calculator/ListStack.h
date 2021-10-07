#ifndef __STACK_H__#ifndef __STACK_H__
#define __STACK_H__

#define SUCCESS 1
#define FAIL 0

/* ������ ������ */
#ifndef __NODE_DATA__
#define __NODE_DATA__
typedef char Data;

typedef struct _node
{
	Data *str;
	struct _node *pNext;
} Node;
#endif
typedef struct _listStack
{
	Node *pTop;
} ListStack;

typedef ListStack Stack;


/* ������ ����(���) */

void stack_init(Stack *pStack);  //���� �ʱ�ȭ
void stack_destroy(Stack *pStack);  // ���� ����

int stack_is_empty(Stack *pStack);  // ������ ������� Ȯ��

int stack_push(Stack *pStack, Data *pData);   // ��top�� ������ �ֱ�
int stack_pop(Stack *pStack, Data *pData);   // top �� ������ ������
int stack_peek(Stack *pStack, Data *pData);  // top �� ������ �̸� ����

#endif