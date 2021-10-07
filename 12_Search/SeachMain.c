#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... �����޸�, ����, ���ڿ� ��ȯ
#include <string.h>  // memcpy, strcpy  �޸𸮺�, ���ڿ� �Լ�
#include <conio.h>   // _getch, putch ..  MS��� C ��ǥ�� �Լ�
#include <time.h>    // clock .. �ð�, ��¥ �Լ�
#include "LinkedListStruct.h"
#include "BinarySearchTree.h"
#pragma warning(disable:4996)

#define LEN 1000

void genIncSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		arr[i] = i; //0 ���� n-1���� ���� �����ִ� �迭 -->arr �� ����.
	
}

// ***�迭 ����.(shuffle)
void shuffleArr(int arr[], int n)
{
	int i;
	if (n > 1)
	{
		for (i = 0; i < n - 1; i++)
		{
			int j = i + rand() / (RAND_MAX / (n - i) + 1);
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
}

// **�迭�� list�� �߰�
void genList(List *pList, int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		list_add(pList, arr[i]);
	}
}

typedef void* fnSearch(void*, int);

// �迭 -> bSt�� �ֱ�
void genBST(BTreeNode **ppRoot, int arr[],int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		bst_insert(ppRoot, arr[i]);
	}
}

// ã�µ� �ɸ��� �ð� üũ
void chkTimeLapArray(fnSearch search, void *collection, int arr[],int n, char *title) 
{
	int cnt = 0;
	int i;
	clock_t start, end;

	start = clock();

	for (i = 0; i < n; i++)
	{
		if (search(collection, arr[i]) != NULL)
			cnt++;
	}

	end = clock();
	printf("%s (%d/%d �� Ž��) ���� ��� : %ld ms\n", 
			title,cnt,n,end-start);
}

int main(int argc, char**argv)
{
	// �迭 ����
	int srcArr[LEN];   // ���� �迭 
	int workArr[LEN];  // �۾� �迭 


	genIncSorted(srcArr, LEN); // 0~ LEN -1
	memcpy(workArr, srcArr, sizeof(int)*LEN);
	shuffleArr(workArr, LEN);

	List list;

	list_init(&list);

	genList(&list, workArr, LEN);
	chkTimeLapArray(list_search, &list, srcArr, LEN, "����Ʈ Ž��");

	BTreeNode *pRoot; // bst�� root
	bst_make_init(&pRoot); // bst �ʱ�ȭ
	genBST(&pRoot, workArr, LEN);
	chkTimeLapArray(bst_search, &list, srcArr, LEN, "bst Ž��");

	//Node *pNode=list_search(&list, 500); // 500�̶� ���� ã��.

	//if (pNode != NULL)
		//printf("Ž�� ���� : %d \n", pNode->data);
	
	//else
		//printf("Ž�� ����\n");

	list_destroy(&list);
}