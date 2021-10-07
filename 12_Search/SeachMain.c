#include <stdio.h>
#include <stdlib.h>  // malloc, rand, atoi... 동적메모리, 난수, 문자열 변환
#include <string.h>  // memcpy, strcpy  메모리블럭, 문자열 함수
#include <conio.h>   // _getch, putch ..  MS기반 C 비표준 함수
#include <time.h>    // clock .. 시간, 날짜 함수
#include "LinkedListStruct.h"
#include "BinarySearchTree.h"
#pragma warning(disable:4996)

#define LEN 1000

void genIncSorted(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		arr[i] = i; //0 부터 n-1까지 값을 갖고있는 배열 -->arr 에 대입.
	
}

// ***배열 섞기.(shuffle)
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

// **배열을 list에 추가
void genList(List *pList, int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		list_add(pList, arr[i]);
	}
}

typedef void* fnSearch(void*, int);

// 배열 -> bSt에 넣기
void genBST(BTreeNode **ppRoot, int arr[],int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		bst_insert(ppRoot, arr[i]);
	}
}

// 찾는데 걸리는 시간 체크
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
	printf("%s (%d/%d 개 탐색) 수행 결과 : %ld ms\n", 
			title,cnt,n,end-start);
}

int main(int argc, char**argv)
{
	// 배열 생성
	int srcArr[LEN];   // 원본 배열 
	int workArr[LEN];  // 작업 배열 


	genIncSorted(srcArr, LEN); // 0~ LEN -1
	memcpy(workArr, srcArr, sizeof(int)*LEN);
	shuffleArr(workArr, LEN);

	List list;

	list_init(&list);

	genList(&list, workArr, LEN);
	chkTimeLapArray(list_search, &list, srcArr, LEN, "리스트 탐색");

	BTreeNode *pRoot; // bst의 root
	bst_make_init(&pRoot); // bst 초기화
	genBST(&pRoot, workArr, LEN);
	chkTimeLapArray(bst_search, &list, srcArr, LEN, "bst 탐색");

	//Node *pNode=list_search(&list, 500); // 500이란 값을 찾음.

	//if (pNode != NULL)
		//printf("탐색 성공 : %d \n", pNode->data);
	
	//else
		//printf("탐색 실패\n");

	list_destroy(&list);
}