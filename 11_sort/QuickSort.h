#ifndef __QUICK_SORT_H__
#define __QUICK_SORT_H__

void QuickSort(int arr[], int left, int right); // 재귀적으로 퀵정렬 수행 
int partition(int arr[], int left, int right); // 배열 정렬 영역 쪼갤 지점을 리턴 
void Swap(int arr[], int idx1, int idx2); // 배열 두개값 바꾸기 

void QuickSortMain(int arr[], int n); // main() 에서 사용할 함수 


#endif // !__QUICK_SORT_H__
