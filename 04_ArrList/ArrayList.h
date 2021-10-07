#pragma once /// ifndef �� ���� �������.
#define _ARRAY_LISTH__
#define Success 1
#define Fail 0
/*ArrayList �� ADT ( �߻� ������ Ÿ�� ) */

typedef int Data;	//�����ʹ� int 

#define List_Len 4
typedef struct _ArrayList
{
	Data arr[List_Len];		// ������(��) 
	int numdata;			//list ���� ���� ������ ����
	int curPosition;			//iteration
}_ArrayList;

typedef _ArrayList List;

// ����Ʈ �ʱ�ȭ

void list_init(List * pList);

// ����Ʈ ����.
void list_distory(List*pList);
// ������ �߰�
int list_add(List * pList, Data data);
// N��° ������ ����
int list_remove(List * pList, int n);
// ������ ����
int list_set(List*pList, int n, Data data);
//n��°�� data�� ����

// ������ ���� ������ ����
int list_length(List *pList);


// ������ ��ȸ(iteration) : �ʱ�ȭ
void list_init_iter(List * pList);
// ������ ��ȸ : ���� �����Ͱ� �����ϳ�?
int list_hasNext(List*pList);
// ������ ��ȸ : ���� �����͸� ����
Data list_next(List*pList);
// ������ ��ȸ : n��° ������ �� �б�.
int list_get(List*pList, int n, Data *pData);  // ���ܻ����� �׻� �ֱ� ������ ����� ���� �׻� �����ؾ���.
int list_remove(List*pList, int n);