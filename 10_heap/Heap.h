#ifndef __HEAP_H__
#define __HEAP_H__
#define SUCCESS 1
#define FAIL 0

/* heap 의 데이터 */
#define HEAP_LEN  100

typedef int HData;

// d1 의 우선순위가 높다면 0보다 큰 값을 리턴
// d2 의 우선순위가 높다면 0보다 작은 값 리턴
// d1 과 d2 가 우선순위가 같다면 0 리턴
typedef int fnPriorityComp(HData d1, HData d2);

typedef struct _heap
{
	fnPriorityComp *comp;  // 비교함수 (함수포인터)
	HData heapArr[HEAP_LEN];  // 배열 로 구현하는 heap

	int numData;   // heap 안의 데이터 개수
} Heap;

/* heap 의 동작 */
void heap_init(Heap *ph, fnPriorityComp pc);  // 힙초기화
int heap_is_empty(Heap *ph);   // 힙이 비어있나요?
void heap_insert(Heap *ph, HData data);  // 힙에 데이터 추가
HData heap_delete(Heap *ph);   // 힙에서 root 삭제 & 리턴

#endif