#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.
int main()
{
	/*char str[40] = "This is c ds";
	printf("str= %s\n", str);

	char *delim = "i "; // delimeter : ������  , �̷������� �ϸ�  i �� " " �� �� �������Ͱ� ��.
	char *ptr = strtok(str, delim); // ù��° ��ū�� �����͸� ������ , �� ������ �ٲ�����Ե�..
									// ��ū ���ڿ� ������ ���� , ���̻� �߶� ��ū�� ���ٸ�
									// NULL�� ����.
	//printf("%s\n", ptr);
	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);  //  
	}
	printf("str= %s\n", str);*/

	{
		/*char str[40] = "2019��-02-20 12:55:44";

		char *delim = " :-";
		char *ptr = strtok(str, delim);
		
		while (ptr != NULL)
		{
			printf("%s\n", ptr);
			ptr = strtok(NULL, delim);
		}*/
	}

		char str[40] = "20 + 4 * ( 100 - 21 )";
		char *delim = " ";
		char *ptr = strtok(str, delim);

		while (ptr != NULL)
		{
			printf("%s\n", ptr);
			ptr = strtok(NULL, delim);
		}

		printf("\n strspnn()---------------\n");      // strspn
		{
			char *str ="100 + 20";
			char delimNum = "0123456789.";
			char delimop = "+-*/(){}[]";

			printf("%d\n", strspn(str, delimop));   // (�ΰ��� �Ű������� ���ϴµ� , delimop�ȿ� �ִ� ���ڿ��߿� str�� � �ִ��� Ȯ���ϰ�
													// ������ ����ϴ� �Լ� . �� �� ���߿� delimop�ȿ� �ִ� ���ڿ��� ���� ���ڰ� str�� ���� 
													// ��� �����ϰ� ������ ����Ѵ�.
		}
}
								