#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
int main(int argc, char**argv)
{
	//time �Լ� ( for ���� ���ư��� �ð��� ����!!! ) 
	{
		time_t start, end;
		int i, j;
		int sum = 0;
		printf("time() ��������� \n");
		start = time(NULL); // ���� ����

		for (i = 0; i < 100000; i++)
		{
			for (j = 0; j < 10000; j++)
			{
				sum += i * j;
			}
		}
		end = time(NULL); // �ð� ���� �� 
		double result = (double)(end - start); // ��� �ð� ���
		printf("%f sec\n", result);
	}

	//�ð� ���� : clock () ���
	{
		clock_t start, end; // ( clock ����ü ������ ms ���� ���� int�� �� ���ۿ� ����.
		int i, j;
		int sum = 0;
		printf("clock �ð� ���� ���� \n");	
		start = clock(); // �ð� ���� ���� 
		for (i = 0; i < 100000; i++)
		{
			for (j = 0; j < 10000; j++)
			{
				sum += i * j;
			}
		}
		end = clock(); // �ð� ���� ��
		long result = end - start;
		printf("%ld ms\n ", result);
	}

	//slee() �ð� ���� 
	{
		clock_t start, end; // ( clock ����ü ������ ms ���� ���� int�� �� ���ۿ� ����.
		int i, j;
		int sum = 0;

		printf("clock �ð� ���� ���� \n");
		start = clock(); // �ð� ���� ���� 
		
		_sleep(5000); // 5��

		end = clock(); // �ð� ���� ��
		long result = end - start;
		printf("%ld ms\n ", result);
	}
}