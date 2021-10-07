#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
#include "ListStack.h"
#include "ListQueue.h"
// 전역 변수
#define MAX_EXPR_LENGTH  100
#define MAX_TOKEN_LENGTH 10

#define TRUE 1
#define FALSE 0

// 연산자 우선순위 정보
// + -   * /
const int PRECED_PLUS = 2;
const int PRECED_MINUS = 2;
const int PRECED_MUL = 3;   // +, - 보다는 우선순위 높아야 함
const int PRECED_DIV = 3;

void test()
{
	Stack stack;
	Queue queue;

	char arr[][20] = {
		"hello student",
		"안녕하세요",
		"반갑습니다."
	};

	char buf[20];

	stack_init(&stack);
	queue_init(&queue);

	stack_push(&stack, arr[0]);
	stack_push(&stack, arr[1]);
	stack_push(&stack, arr[2]);
	
	stack_pop(&stack, buf); printf("pop : %s\n", buf);
	stack_pop(&stack, buf); printf("pop : %s\n", buf);
	stack_pop(&stack, buf); printf("pop : %s\n", buf);

	printf("\n\n");

	queue_destroy(&queue);
	stack_destroy(&stack);

	queue_enq(&queue, arr[0]);
	queue_enq(&queue, arr[1]);
	queue_enq(&queue, arr[2]);

	queue_deq(&queue, buf); printf("pop : %s\n", buf);
	queue_deq(&queue, buf); printf("pop : %s\n", buf);
	queue_deq(&queue, buf); printf("pop : %s\n", buf);
}

// 연산자 우선순위 리턴
int getPreced(char* op)
{
	if (!strcmp, ("+", op)) return PRECED_PLUS;
	if (!strcmp, ("-", op)) return PRECED_MINUS;
	if (!strcmp, ("*", op)) return PRECED_MUL;
	if (!strcmp, ("/", op)) return PRECED_DIV;
	
	return 0;	// 괄호나 기타 기호가 들어오면 무조건 0을 리턴 
}

// 연산자 우선순위 비교
// 리턴값: 0 -> 같다.   음수 -> op1 < op2   양수 -> op1 > op2 
int comOp(char* op1, char* op2)
{
	return getPreced(op1) - getPreced(op2);
}

// 숫자(실수)인지 확인 ( 숫자면 operand , 아니면 operate 
int isNumber(char *str)
{
	char *ep = NULL;	//end pointer : 정상적으로 파싱이 끝나면 "숫자"끝을 가리킴.
	double d = strtod(str , &ep);

	if (!ep || *ep)
		return FALSE; // 숫자가 아님.

	return TRUE;   // 숫자 확인
}

// infix expr 의 토큰 분리 --> tokQueue
void exprTokenizer(char* expr, Queue *tokQueue)
{
	char *delim = " \t"; // delimeter는 공백과 탭
	char *sepOP = "+-*/(){}[]";  // 구분자의 경우를 늘리기 위해
	char *sepNum = "0123456789."; // ""			""

	char *pBuf[MAX_TOKEN_LENGTH];
	int i; // for문 돌리기 위해

	 // 1. 공백 단위로 토큰 분리 

	 // 2. 분리된 토큰 안에서 연산자 , 피연산자 , 괄호 추출 ----> queue

	char *ptr;
	ptr = strtok(expr, delim); //  // 1. 공백 단위로 토큰 분리 
	while (ptr != NULL)
	{
		//printf("%s\n", ptr);		// 확인용
		
		int n; // strspn 결과를 담음
		char *p = ptr; // ptr이 가리키는 것을 똑같이 가리키지만, 복사본을 만들어서 토큰을 따로 뽑아낸다.

		 // 2. 분리된 토큰 안에서 연산자 , 피연산자 , 괄호 추출 ----> queue
		while (*p != '\0')
		{
			//숫자로 시작하는지 ,. 연산자로 시작하는지 체크 . ex): 10.3 + , ex): -(4+9)

			// 1) 숫자로 시작
			n = strspn(p, sepNum);
			if (n > 0) // 숫자라면
			{
				strncpy(pBuf, p, n); // n자리 만큼 문자열 복사.
				pBuf[n] = '\0'; // strncpy는 딱 n개 만큼 복사하기 때문에 '\0'를 넣어줘야한다.

				//printf("%s\n", pBuf); // 테스트용 

				queue_enq(tokQueue, pBuf); // 피연산자 (숫자) 토큰을 집어넣기
				p += n; // 문자열 포인터는 n만큼 이동
			}

			//2) 연산자로 시작
			n = strspn(p, sepOP);
			if (n > 0) // 연산자 라면 n은 0보다 값이 큼 !!
			{
				for (i = 0; i < n; i++)
				{
					sprintf(pBuf, "%c", p[i]);	// 연산자 토큰 분리하기
					//printf("%s\n", pBuf); // 테스트용
					queue_enq(tokQueue, pBuf);
				}
				p += n; // 문자열 포인터는 n만큼 이동
			}
		}//end whil

		ptr = strtok(NULL, delim);  // 다음 토큰
	}
}

// infix 로 된 tokQueue 에서 postfix 방식으로 postQueue 에 enqueue

void InfixToPostfix(Queue *tokQueue, Queue *postQueue)
{
	char pTopBuf[MAX_TOKEN_LENGTH]; // 스택의 top에 push/pop 할 데이터를 담는 버퍼
	char token[MAX_TOKEN_LENGTH];

	Stack opStack;		// operator 스택
	stack_init(&opStack);

	//shauting yard 알고리즘.
	while (!queue_is_empty(tokQueue))
	{
		queue_deq(&tokQueue, token); // 큐 --> token 

		// 1. 토큰이 operand 이면 ?
		if (isNumber(token))
		{
			queue_enq(postQueue, token); // 숫자면 토큰을 그냥 담음
		}
		// 2. operand가 아닐 경우.
		else
		{
			char op = token[0]; //연산자 추출 ( 연산자는 한글자라는 전제를 깔고 가자 ! )

			switch(op)
			{
			    // 1) 연산자 
			case '+':
			case '-':
			case '*':
			case '/':
				// stack을 peek 하여 자신(op)보다 우선순위가 같거나 큰 연산자라면
				// pop 하여 queue(postQueue) 에 넣기 

				while (stack_peek(&opStack, pTopBuf))
				{
					if (comOp(pTopBuf, token) < 0) // pTopBuf[0] 의 우선순위가 token 보다 작다면
						break;

					else // 우선순위가 같거나 크면 , pop하여 enqueue 하기 !!
					{
						stack_pop(&opStack, pTopBuf); // pop하여
						queue_enq(postQueue, pTopBuf); // enq하기 
					}

				}

				stack_push(&opStack, token); // 최종적으로 자기 자신이 push

				break;

				// 2) 여는 괄호
			case '{':
			case '[':
			case '(':

				stack_push(&opStack, token); // 여는 괄호는 무조건 push 

				break;

				// 3) 닫는 괄호 : 닫는 괄호는 push하지 않고 처리하기.
			case '}':
				while (stack_pop(&opStack, pTopBuf))
				{
					if (!strcmp(pTopBuf, '{')) // "("를 pop하면 종료
						break;

					queue_enq(postQueue, pTopBuf);
				}
				break;
			case ']':
				while (stack_pop(&opStack, pTopBuf))
				{
					if (!strcmp(pTopBuf, '[')) // "("를 pop하면 종료
						break;

					queue_enq(postQueue, pTopBuf);
				}
				break;
			case ')':
				// ')' 까지 pop 하기 .
				while (stack_pop(&opStack, pTopBuf))
				{
					if (!strcmp(pTopBuf, '(')) // "("를 pop하면 종료
						break;
					
					queue_enq(postQueue, pTopBuf);
				}
				break;
			} // switch
		} // else
	}//while

	// 토큰을 다 뽑아낸뒤 , 스택에 남아있는 operator는 전부 pop 하여 enq하기 
	while (!stack_is_empty(&opStack))
	{
		stack_pop(&opStack, pTopBuf); // pop 하여 
		queue_enq(postQueue, pTopBuf); // enq 하기 
	}

	stack_destroy(&opStack);
}

// infix expr 연산식 문자열을 받아서 evaluate 한 결과값 리턴
double calcExpr(char *expr)
{
	double result = 0;   // 연산 결과값

	Queue tokQueue; //expr 에서 추출한 토큰들을 담을 queue 하나 생성
	Queue postQueue; //postfix로 변환된 토큰들을 담을  queue 하나 생성 
	Stack evalStack;  // 토큰을들 가지고 계산할 스택
	
	queue_init(&tokQueue);	// 초기화
	queue_init(&postQueue);
	stack_init(&evalStack);
	 
	char pBuf[MAX_TOKEN_LENGTH];	// 토큰용 임시 버퍼
	char *token = pBuf;

	// 1. infix 문자열 -> 토큰 분리 ( tokQueue )
	exprTokenizer(expr, &tokQueue);

	// 2. infix 토큰들 -> postfix로 변환 ( postQueue ) 
	InfixToPostfix(&tokQueue, &postQueue);

	// 3. postfix 토큰 -> 계산 --> result 
	while (!queue_is_empty(&postQueue))
	{
		queue_deq(&postQueue, token);
		
		// operand 이면 push , operate 이면 두개를 pop 하여 연산후 다시 psuh
		if (isNumber(token))
		{
			stack_push(&evalStack, token);
		}
		else
		{
			char op = token[0];

			stack_pop(&evalStack, token); // 먼저 pop 한게 우측 피연산자
			double right = atof(token);	// 우측 피연산자 , atof -> 문자를 실수로 변환
			stack_pop(&evalStack, token);
			double left = atof(token);  // 좌측 피연산자.

			switch (op)
			{
			case '+': 
				result = left + right;
				break;
			
			case '-':
				result = left - right;
				break;

			case '*':
				result = left * right;
				break;

			case '/':
				result = left / right;
				break;
			}

			sprintf(pBuf, "%.2lf", result); // 소수점 2자리 문자열로 저장
			stack_push(&evalStack, pBuf);
		}// end switch
	}// end while

	// 스택 마지막에 남아있는 한개의 값이 연산식의 결과 값.
	stack_pop(&evalStack, pBuf);
	result = atof(pBuf); // double로 형변환 

	queue_destroy(&tokQueue); // 삭제
	queue_destroy(&postQueue);
	stack_destroy(&evalStack);

	return result;
}

int main(int argc , char**argv)
{
	// 테스트 용 infix 수식들
	char test_expr[][MAX_EXPR_LENGTH] = {
		"1 - ( 2 + 3 + ( 4 - 5 * 6 ) * 7 ) + 8 * 9",
		// ↑ post결과 : 1 2 3 + 4 5 6 * - 7 * + - 8 9 * +
		//  산술 연산 결과  250

	"24 + 4 - 15 * 8 / ( 2 + 5 * 2 - 8 ) + 4"
	// ↑ post결과 : 24 4 + 15 8 * 2 5 2 * + 8 - / - 4 +
	// 산술 연산 결과  2
	};

	char expr[MAX_EXPR_LENGTH];
	while (1)
	{
		printf(">"); // 프롬프트
		gets_s(expr, MAX_EXPR_LENGTH - 1); // 띄어쓰기가 포함된 문자열 받기

		if (!strcmp(expr, "exit"));
		break;

		printf("%.2lf\n", calcExpr(expr));
		
	}

	printf("아무키나 입력하시면 프로그램이 종료됩니다.\n");
	_getch();
	return 0;
}