#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.

/*
	�޸�
	�޸� ���� ( memory leak ) ���� !!... : �޸𸮰� ��� ���α׷��� �״� ���

*/
int main(int argc , char**argv)
{
	{
		int len = 1000000;
		int * arr = (int*)malloc(sizeof(int)*len);  //�������� �޸� �Ҵ�, ��� �� �׻� �ݳ��ؾ���. ������ byte

		printf("arr[0] = %d\n", arr[0]);
		
		// �޸𸮸� �Ҵ� �޾����� ������ �ʱ�ȭ ���ִ°� ����.
		memset(arr, 0, sizeof(int)*len);// �ʱ�ȭ ���ִ� �Լ� , ( ������ �ʱ�ȭ �Ұ��� , ������ �ʱ�ȭ �Ұ��� , �󸶸�ŭ �ʱ�ȭ �Ұ��� )
		printf("arr[0] = %d\n", arr[0]);

		// �޸� �ݳ�.
		free(arr); //�޸� �ݳ� . �ݵ�� �ؾ���

		printf("�޸� �������ϸ� ���� - �ƹ�Ű�� ������ �����մϴ�\n");
		//�޸� �������ϸ� : ��� ���α׷��� ������ �޸��� ��뷮�� ���� �ϴ°�. �ֵ� ������ �޸� ������ �߻� �Ǵ� ���� Ȯ���Ͽ� ���� ����.
		//					 �������� �� ���� ���Ͽ� �󸶳� �޸� ��뷮�� ���� �ߴ��� �� ������.
		_getch();
		{
			int len = 100000;
			int *arr;
			
			int i;
			for (i = 0; i < 100; i++) 
			{
				arr = (int*)malloc(sizeof(int)*len); // free�� ���� ���¿���  for ���� ��� ���⶧���� ���� ���� 4�鸸�� ��� �Ҵ��...
				_sleep(10); // 0.01�� ������ delay �߻� 

				free(arr);
			}
		}
	}

	// TODO : �ڵ��ۼ� 
	printf("�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	_getch();
	return 0;

}