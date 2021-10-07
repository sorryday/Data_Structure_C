#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
#include "ListStack.h"
#include "ListQueue.h"
// ���� ����
#define MAX_EXPR_LENGTH  100
#define MAX_TOKEN_LENGTH 10

#define TRUE 1
#define FALSE 0

// ������ �켱���� ����
// + -   * /
const int PRECED_PLUS = 2;
const int PRECED_MINUS = 2;
const int PRECED_MUL = 3;   // +, - ���ٴ� �켱���� ���ƾ� ��
const int PRECED_DIV = 3;

void test()
{
	Stack stack;
	Queue queue;

	char arr[][20] = {
		"hello student",
		"�ȳ��ϼ���",
		"�ݰ����ϴ�."
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

// ������ �켱���� ����
int getPreced(char* op)
{
	if (!strcmp, ("+", op)) return PRECED_PLUS;
	if (!strcmp, ("-", op)) return PRECED_MINUS;
	if (!strcmp, ("*", op)) return PRECED_MUL;
	if (!strcmp, ("/", op)) return PRECED_DIV;
	
	return 0;	// ��ȣ�� ��Ÿ ��ȣ�� ������ ������ 0�� ���� 
}

// ������ �켱���� ��
// ���ϰ�: 0 -> ����.   ���� -> op1 < op2   ��� -> op1 > op2 
int comOp(char* op1, char* op2)
{
	return getPreced(op1) - getPreced(op2);
}

// ����(�Ǽ�)���� Ȯ�� ( ���ڸ� operand , �ƴϸ� operate 
int isNumber(char *str)
{
	char *ep = NULL;	//end pointer : ���������� �Ľ��� ������ "����"���� ����Ŵ.
	double d = strtod(str , &ep);

	if (!ep || *ep)
		return FALSE; // ���ڰ� �ƴ�.

	return TRUE;   // ���� Ȯ��
}

// infix expr �� ��ū �и� --> tokQueue
void exprTokenizer(char* expr, Queue *tokQueue)
{
	char *delim = " \t"; // delimeter�� ����� ��
	char *sepOP = "+-*/(){}[]";  // �������� ��츦 �ø��� ����
	char *sepNum = "0123456789."; // ""			""

	char *pBuf[MAX_TOKEN_LENGTH];
	int i; // for�� ������ ����

	 // 1. ���� ������ ��ū �и� 

	 // 2. �и��� ��ū �ȿ��� ������ , �ǿ����� , ��ȣ ���� ----> queue

	char *ptr;
	ptr = strtok(expr, delim); //  // 1. ���� ������ ��ū �и� 
	while (ptr != NULL)
	{
		//printf("%s\n", ptr);		// Ȯ�ο�
		
		int n; // strspn ����� ����
		char *p = ptr; // ptr�� ����Ű�� ���� �Ȱ��� ����Ű����, ���纻�� ���� ��ū�� ���� �̾Ƴ���.

		 // 2. �и��� ��ū �ȿ��� ������ , �ǿ����� , ��ȣ ���� ----> queue
		while (*p != '\0')
		{
			//���ڷ� �����ϴ��� ,. �����ڷ� �����ϴ��� üũ . ex): 10.3 + , ex): -(4+9)

			// 1) ���ڷ� ����
			n = strspn(p, sepNum);
			if (n > 0) // ���ڶ��
			{
				strncpy(pBuf, p, n); // n�ڸ� ��ŭ ���ڿ� ����.
				pBuf[n] = '\0'; // strncpy�� �� n�� ��ŭ �����ϱ� ������ '\0'�� �־�����Ѵ�.

				//printf("%s\n", pBuf); // �׽�Ʈ�� 

				queue_enq(tokQueue, pBuf); // �ǿ����� (����) ��ū�� ����ֱ�
				p += n; // ���ڿ� �����ʹ� n��ŭ �̵�
			}

			//2) �����ڷ� ����
			n = strspn(p, sepOP);
			if (n > 0) // ������ ��� n�� 0���� ���� ŭ !!
			{
				for (i = 0; i < n; i++)
				{
					sprintf(pBuf, "%c", p[i]);	// ������ ��ū �и��ϱ�
					//printf("%s\n", pBuf); // �׽�Ʈ��
					queue_enq(tokQueue, pBuf);
				}
				p += n; // ���ڿ� �����ʹ� n��ŭ �̵�
			}
		}//end whil

		ptr = strtok(NULL, delim);  // ���� ��ū
	}
}

// infix �� �� tokQueue ���� postfix ������� postQueue �� enqueue

void InfixToPostfix(Queue *tokQueue, Queue *postQueue)
{
	char pTopBuf[MAX_TOKEN_LENGTH]; // ������ top�� push/pop �� �����͸� ��� ����
	char token[MAX_TOKEN_LENGTH];

	Stack opStack;		// operator ����
	stack_init(&opStack);

	//shauting yard �˰���.
	while (!queue_is_empty(tokQueue))
	{
		queue_deq(&tokQueue, token); // ť --> token 

		// 1. ��ū�� operand �̸� ?
		if (isNumber(token))
		{
			queue_enq(postQueue, token); // ���ڸ� ��ū�� �׳� ����
		}
		// 2. operand�� �ƴ� ���.
		else
		{
			char op = token[0]; //������ ���� ( �����ڴ� �ѱ��ڶ�� ������ ��� ���� ! )

			switch(op)
			{
			    // 1) ������ 
			case '+':
			case '-':
			case '*':
			case '/':
				// stack�� peek �Ͽ� �ڽ�(op)���� �켱������ ���ų� ū �����ڶ��
				// pop �Ͽ� queue(postQueue) �� �ֱ� 

				while (stack_peek(&opStack, pTopBuf))
				{
					if (comOp(pTopBuf, token) < 0) // pTopBuf[0] �� �켱������ token ���� �۴ٸ�
						break;

					else // �켱������ ���ų� ũ�� , pop�Ͽ� enqueue �ϱ� !!
					{
						stack_pop(&opStack, pTopBuf); // pop�Ͽ�
						queue_enq(postQueue, pTopBuf); // enq�ϱ� 
					}

				}

				stack_push(&opStack, token); // ���������� �ڱ� �ڽ��� push

				break;

				// 2) ���� ��ȣ
			case '{':
			case '[':
			case '(':

				stack_push(&opStack, token); // ���� ��ȣ�� ������ push 

				break;

				// 3) �ݴ� ��ȣ : �ݴ� ��ȣ�� push���� �ʰ� ó���ϱ�.
			case '}':
				while (stack_pop(&opStack, pTopBuf))
				{
					if (!strcmp(pTopBuf, '{')) // "("�� pop�ϸ� ����
						break;

					queue_enq(postQueue, pTopBuf);
				}
				break;
			case ']':
				while (stack_pop(&opStack, pTopBuf))
				{
					if (!strcmp(pTopBuf, '[')) // "("�� pop�ϸ� ����
						break;

					queue_enq(postQueue, pTopBuf);
				}
				break;
			case ')':
				// ')' ���� pop �ϱ� .
				while (stack_pop(&opStack, pTopBuf))
				{
					if (!strcmp(pTopBuf, '(')) // "("�� pop�ϸ� ����
						break;
					
					queue_enq(postQueue, pTopBuf);
				}
				break;
			} // switch
		} // else
	}//while

	// ��ū�� �� �̾Ƴ��� , ���ÿ� �����ִ� operator�� ���� pop �Ͽ� enq�ϱ� 
	while (!stack_is_empty(&opStack))
	{
		stack_pop(&opStack, pTopBuf); // pop �Ͽ� 
		queue_enq(postQueue, pTopBuf); // enq �ϱ� 
	}

	stack_destroy(&opStack);
}

// infix expr ����� ���ڿ��� �޾Ƽ� evaluate �� ����� ����
double calcExpr(char *expr)
{
	double result = 0;   // ���� �����

	Queue tokQueue; //expr ���� ������ ��ū���� ���� queue �ϳ� ����
	Queue postQueue; //postfix�� ��ȯ�� ��ū���� ����  queue �ϳ� ���� 
	Stack evalStack;  // ��ū���� ������ ����� ����
	
	queue_init(&tokQueue);	// �ʱ�ȭ
	queue_init(&postQueue);
	stack_init(&evalStack);
	 
	char pBuf[MAX_TOKEN_LENGTH];	// ��ū�� �ӽ� ����
	char *token = pBuf;

	// 1. infix ���ڿ� -> ��ū �и� ( tokQueue )
	exprTokenizer(expr, &tokQueue);

	// 2. infix ��ū�� -> postfix�� ��ȯ ( postQueue ) 
	InfixToPostfix(&tokQueue, &postQueue);

	// 3. postfix ��ū -> ��� --> result 
	while (!queue_is_empty(&postQueue))
	{
		queue_deq(&postQueue, token);
		
		// operand �̸� push , operate �̸� �ΰ��� pop �Ͽ� ������ �ٽ� psuh
		if (isNumber(token))
		{
			stack_push(&evalStack, token);
		}
		else
		{
			char op = token[0];

			stack_pop(&evalStack, token); // ���� pop �Ѱ� ���� �ǿ�����
			double right = atof(token);	// ���� �ǿ����� , atof -> ���ڸ� �Ǽ��� ��ȯ
			stack_pop(&evalStack, token);
			double left = atof(token);  // ���� �ǿ�����.

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

			sprintf(pBuf, "%.2lf", result); // �Ҽ��� 2�ڸ� ���ڿ��� ����
			stack_push(&evalStack, pBuf);
		}// end switch
	}// end while

	// ���� �������� �����ִ� �Ѱ��� ���� ������� ��� ��.
	stack_pop(&evalStack, pBuf);
	result = atof(pBuf); // double�� ����ȯ 

	queue_destroy(&tokQueue); // ����
	queue_destroy(&postQueue);
	stack_destroy(&evalStack);

	return result;
}

int main(int argc , char**argv)
{
	// �׽�Ʈ �� infix ���ĵ�
	char test_expr[][MAX_EXPR_LENGTH] = {
		"1 - ( 2 + 3 + ( 4 - 5 * 6 ) * 7 ) + 8 * 9",
		// �� post��� : 1 2 3 + 4 5 6 * - 7 * + - 8 9 * +
		//  ��� ���� ���  250

	"24 + 4 - 15 * 8 / ( 2 + 5 * 2 - 8 ) + 4"
	// �� post��� : 24 4 + 15 8 * 2 5 2 * + 8 - / - 4 +
	// ��� ���� ���  2
	};

	char expr[MAX_EXPR_LENGTH];
	while (1)
	{
		printf(">"); // ������Ʈ
		gets_s(expr, MAX_EXPR_LENGTH - 1); // ���Ⱑ ���Ե� ���ڿ� �ޱ�

		if (!strcmp(expr, "exit"));
		break;

		printf("%.2lf\n", calcExpr(expr));
		
	}

	printf("�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	_getch();
	return 0;
}