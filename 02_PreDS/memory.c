#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.

/*
	메모리
	메모리 누수 ( memory leak ) 주의 !!... : 메모리가 없어서 프로그램이 죽는 경우

*/
int main(int argc , char**argv)
{
	{
		int len = 1000000;
		int * arr = (int*)malloc(sizeof(int)*len);  //동적으로 메모리 할당, 사용 후 항상 반납해야함. 단위는 byte

		printf("arr[0] = %d\n", arr[0]);
		
		// 메모리를 할당 받았으면 무조건 초기화 해주는게 좋음.
		memset(arr, 0, sizeof(int)*len);// 초기화 해주는 함수 , ( 누구를 초기화 할건지 , 몇으로 초기화 할건지 , 얼마만큼 초기화 할건지 )
		printf("arr[0] = %d\n", arr[0]);

		// 메모리 반납.
		free(arr); //메모리 반납 . 반드시 해야함

		printf("메모리 프로파일링 시작 - 아무키나 누르면 시작합니다\n");
		//메모리 프로파일링 : 계속 프로그램을 돌려서 메모리의 사용량을 측정 하는것. 주된 목적은 메모리 누수가 발생 되는 것을 확인하여 막기 위해.
		//					 스냅샷을 찍어서 전과 비교하여 얼마나 메모리 사용량이 증가 했는지 알 수있음.
		_getch();
		{
			int len = 100000;
			int *arr;
			
			int i;
			for (i = 0; i < 100; i++) 
			{
				arr = (int*)malloc(sizeof(int)*len); // free도 안한 상태에서  for 문이 계속 돌기때문에 돌때 마다 4백만이 계속 할당됨...
				_sleep(10); // 0.01초 단위의 delay 발생 

				free(arr);
			}
		}
	}

	// TODO : 코드작성 
	printf("아무키나 입력하시면 프로그램이 종료됩니다.\n");
	_getch();
	return 0;

}