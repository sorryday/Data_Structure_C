#ifndef __HEAP_H__

#define __HEAP_H__
#define SUCCESS 1
#define FAIL 0

/* heap �� ������ */
// #define HEAP_LEN  100

typedef int HData;
// d1 �� �켱������ ���ٸ� 0���� ū ���� ����
// d2 �� �켱������ ���ٸ� 0���� ���� �� ����
// d1 �� d2 �� �켱������ ���ٸ� 0 ����

typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	fnPriorityComp *comp;  // ���Լ� (�Լ�������)

	//HData heapArr[HEAP_LEN];  // �迭 �� �����ϴ� heap
	HData * heapArr; // �� ���Ŀ� ���� �迭 

	int numData;   // heap ���� ������ ����

} Heap;

/* heap �� ���� */

// void heap_init(Heap *ph, fnPriorityComp pc);  // ���ʱ�ȭ

void heap_init(Heap *ph, int len); // �� �ʱ�ȭ
void heap_destroy(Heap *ph);

int heap_is_empty(Heap *ph);   // ���� ����ֳ���?

void heap_insert(Heap *ph, HData data);  // ���� ������ �߰�

HData heap_delete(Heap *ph);   // ������ root ���� & ����

// heap ���� 
Heap *g_hp; // ���� ��� ��
void HeapSort(int arr[], int n);

#endif