#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.

/* 
	함수 포인터 ( function pointer)
	 - 배열 이름만 포인터가 아닌 함수 이름도 포인터다.
	 - 덧셈 함수여도 값이 넘어갈 때 10,20이 binary 코드로 넘어간다.
	 - 결국 메모리에 잡히게 되고 함수도 결국은 메모리에 잡혀서 포인터가 된다. ( 마찬가지로 함수도 각각의 주소가 존재 한다 .)
*/
void Plus(int a, int b)		
{
	printf("덧셈 : %d + %d = %d\n", a, b, a + b);

}

void Minus(int a, int b)
{
	printf("뺄셈 : %d - %d = %d\n", a, b, a - b);

}

void Mul(int a, int b)
{
	printf("곱셈 : %d * %d = %d\n", a, b, a * b);

}

void Div(int a, int b)
{
	printf("나눗셈 : %d / %d = %d\n", a, b, a / b);

}
int main(int argc , char**argv)
{

	{
		Plus(10, 20); // 함수 호출

		printf("plus --> %p\n", Plus);

		(*Plus)(30, 40); // 함수 포인터를 이용한 함수 호출 ,  사실상 위의 함수 호출을 할 때 컴퓨터는 이렇게 바꿔서 인식한다.

		int *p; // int * 포인터 p 선언 .

		// 함수 포인터 변수 선언 가능 !!!
		// 리턴 타입 , 매개 변수 타입 으로도 가능 !! 

		void(*fnop)(int, int); // 함수 포인터 선언 방법 , void 리턴하고 (int,int) 매개변수 받는 함수에 대한 함수 포인터 선언 !!
		fnop = Plus;		   // 함수 포인터 대입 가능.

		(*fnop)(70, 100);		//fnop로 plus 함수 호출 가능.

	}
	printf("\n");
	{
		/*함수 포인터의 이점
		  동작을 나중(실행시간)에 정할 수 있다. --> late-binding
		  컴파일하는 시간에 정하는것이 아닌 실행하는 시간에 정할 수 있음. */

		int op;
		printf("동작번호 입력하세요 0:+ , 1:- , 2: * ,3:/ ");
		scanf("%d", &op);

		int a = 30, b = 10;
		int i;
		for (i = 0; i < 5; i++) // 컴파일 하는 시점에서 '특정'함수가 실행 되도록 바인딩 하는것.==Early binding  
		{						// 단점은 프로그램이 돌 때 마다 조건문을 계속 생각 해야 해서 그 시간만큼의 delay가 생김
			if (op == 0)
				Plus(a, b);

			else if (op == 1)
				Minus(a, b);

			else if (op == 1)
				Mul(a, b);

			else if (op == 1)
				Div(a, b);
		}

		//반면 .. 함수 포인터 변수 선언
		void(*fnaction)(int, int);
		
		// 함수 포인터 배열 
		void(*fnoparr[])(int, int) = {Plus,Minus,Mul,Div};

		// op <-- 0~3
		fnaction = fnoparr[op];

		for (i = 0; i < 5; i++)
		{
			(*fnaction)(a, b);    //사용자가 입력하는 순간 동작하게 되는 과정 
		}						  // fnaction을 수행 하지만 컴파일 시점에서는 알수 없음.
	}							  // -->late binding						


	printf("아무키나 입력하시면 프로그램이 종료됩니다.\n");
	_getch();
	return 0;

}