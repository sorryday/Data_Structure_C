#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
int main(int argc, char**argv)
{
	//time 함수 ( for 문이 돌아가는 시간을 측정!!! ) 
	{
		time_t start, end;
		int i, j;
		int sum = 0;
		printf("time() 측정기시장 \n");
		start = time(NULL); // 측정 시작

		for (i = 0; i < 100000; i++)
		{
			for (j = 0; j < 10000; j++)
			{
				sum += i * j;
			}
		}
		end = time(NULL); // 시간 측정 끝 
		double result = (double)(end - start); // 경과 시간 계산
		printf("%f sec\n", result);
	}

	//시간 측정 : clock () 사용
	{
		clock_t start, end; // ( clock 구조체 단위는 ms 단위 여서 int형 일 수밖에 없음.
		int i, j;
		int sum = 0;
		printf("clock 시간 측정 시작 \n");	
		start = clock(); // 시간 측정 시작 
		for (i = 0; i < 100000; i++)
		{
			for (j = 0; j < 10000; j++)
			{
				sum += i * j;
			}
		}
		end = clock(); // 시간 측정 끝
		long result = end - start;
		printf("%ld ms\n ", result);
	}

	//slee() 시간 지연 
	{
		clock_t start, end; // ( clock 구조체 단위는 ms 단위 여서 int형 일 수밖에 없음.
		int i, j;
		int sum = 0;

		printf("clock 시간 측정 시작 \n");
		start = clock(); // 시간 측정 시작 
		
		_sleep(5000); // 5초

		end = clock(); // 시간 측정 끝
		long result = end - start;
		printf("%ld ms\n ", result);
	}
}