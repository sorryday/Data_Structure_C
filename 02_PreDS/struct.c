#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.

/*
	구조체. size 
*/

int main(int argc , char**argv)
{
	{
		typedef struct _student
		{
		int age;		//4byte
		char gender;	//1 "
		}student;

		student stu1;	//5>?????

		printf("size or student = %d\n ", sizeof(stu1)); // 결과는 8 byte???
		//byte padding : 구조체에서 메모리를 잡을 때 가장 큰 byte 값을 가지고 변수의 갯수에 따라 잡게됨
		//				 단 !! 변수가 선언되는 순서에 따라 구조체가 잡는 메모리의 차이가 크다.
		//				 메모리를 잡을 때 변수의 순서대로 메모리를 잡는것이 아니라 가장 큰 메모리를 먼저 잡고 변수를 순서대로 잡는다.			
	}   
							
	{
		struct Student
		{
			//char grade;				// 이 경우는 int가 가장 크므로 4를 먼저 잡아서 age를 잡고, char를 잡기 위해 4를 잡고 , 
			//char gender;				// 3이 남아서 gender를 잡는다 . 따라서 이 경우는 8byte
			//int age;
			char grade;
			int age;
			char gender;				//두개가 메모리 잡는 방식은 완전히 다르다. 이경우는 int 잡기 위해 4 , char를 잡기위해 4 , 또 char를
		};								// 잡기 위해 4 . 이 경우는 12byte가 됨.
		struct Student stu;
		printf("size or student = %d\n ", sizeof(stu)); //?? 다르다 .. 왜?
	}

	printf("아무키나 입력하시면 프로그램이 종료됩니다.\n");
	_getch();
	return 0;

}