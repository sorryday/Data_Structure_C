#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.

/* 
	�Լ� ������ ( function pointer)
	 - �迭 �̸��� �����Ͱ� �ƴ� �Լ� �̸��� �����ʹ�.
	 - ���� �Լ����� ���� �Ѿ �� 10,20�� binary �ڵ�� �Ѿ��.
	 - �ᱹ �޸𸮿� ������ �ǰ� �Լ��� �ᱹ�� �޸𸮿� ������ �����Ͱ� �ȴ�. ( ���������� �Լ��� ������ �ּҰ� ���� �Ѵ� .)
*/
void Plus(int a, int b)		
{
	printf("���� : %d + %d = %d\n", a, b, a + b);

}

void Minus(int a, int b)
{
	printf("���� : %d - %d = %d\n", a, b, a - b);

}

void Mul(int a, int b)
{
	printf("���� : %d * %d = %d\n", a, b, a * b);

}

void Div(int a, int b)
{
	printf("������ : %d / %d = %d\n", a, b, a / b);

}
int main(int argc , char**argv)
{

	{
		Plus(10, 20); // �Լ� ȣ��

		printf("plus --> %p\n", Plus);

		(*Plus)(30, 40); // �Լ� �����͸� �̿��� �Լ� ȣ�� ,  ��ǻ� ���� �Լ� ȣ���� �� �� ��ǻ�ʹ� �̷��� �ٲ㼭 �ν��Ѵ�.

		int *p; // int * ������ p ���� .

		// �Լ� ������ ���� ���� ���� !!!
		// ���� Ÿ�� , �Ű� ���� Ÿ�� ���ε� ���� !! 

		void(*fnop)(int, int); // �Լ� ������ ���� ��� , void �����ϰ� (int,int) �Ű����� �޴� �Լ��� ���� �Լ� ������ ���� !!
		fnop = Plus;		   // �Լ� ������ ���� ����.

		(*fnop)(70, 100);		//fnop�� plus �Լ� ȣ�� ����.

	}
	printf("\n");
	{
		/*�Լ� �������� ����
		  ������ ����(����ð�)�� ���� �� �ִ�. --> late-binding
		  �������ϴ� �ð��� ���ϴ°��� �ƴ� �����ϴ� �ð��� ���� �� ����. */

		int op;
		printf("���۹�ȣ �Է��ϼ��� 0:+ , 1:- , 2: * ,3:/ ");
		scanf("%d", &op);

		int a = 30, b = 10;
		int i;
		for (i = 0; i < 5; i++) // ������ �ϴ� �������� 'Ư��'�Լ��� ���� �ǵ��� ���ε� �ϴ°�.==Early binding  
		{						// ������ ���α׷��� �� �� ���� ���ǹ��� ��� ���� �ؾ� �ؼ� �� �ð���ŭ�� delay�� ����
			if (op == 0)
				Plus(a, b);

			else if (op == 1)
				Minus(a, b);

			else if (op == 1)
				Mul(a, b);

			else if (op == 1)
				Div(a, b);
		}

		//�ݸ� .. �Լ� ������ ���� ����
		void(*fnaction)(int, int);
		
		// �Լ� ������ �迭 
		void(*fnoparr[])(int, int) = {Plus,Minus,Mul,Div};

		// op <-- 0~3
		fnaction = fnoparr[op];

		for (i = 0; i < 5; i++)
		{
			(*fnaction)(a, b);    //����ڰ� �Է��ϴ� ���� �����ϰ� �Ǵ� ���� 
		}						  // fnaction�� ���� ������ ������ ���������� �˼� ����.
	}							  // -->late binding						


	printf("�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	_getch();
	return 0;

}