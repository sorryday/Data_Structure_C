#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... �� ���Ե� ���
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms ��� c ��ǥ�� �Լ� -> �ٸ� os ���� ��� �Ұ�..)
#include < time.h>  //clock ... �ð� ��¥ �Լ� ..
#pragma warning (disable:4996)  // 4996���� �����ϴ� ���.

/*
	����ü. size 
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

		printf("size or student = %d\n ", sizeof(stu1)); // ����� 8 byte???
		//byte padding : ����ü���� �޸𸮸� ���� �� ���� ū byte ���� ������ ������ ������ ���� ��Ե�
		//				 �� !! ������ ����Ǵ� ������ ���� ����ü�� ��� �޸��� ���̰� ũ��.
		//				 �޸𸮸� ���� �� ������ ������� �޸𸮸� ��°��� �ƴ϶� ���� ū �޸𸮸� ���� ��� ������ ������� ��´�.			
	}   
							
	{
		struct Student
		{
			//char grade;				// �� ���� int�� ���� ũ�Ƿ� 4�� ���� ��Ƽ� age�� ���, char�� ��� ���� 4�� ��� , 
			//char gender;				// 3�� ���Ƽ� gender�� ��´� . ���� �� ���� 8byte
			//int age;
			char grade;
			int age;
			char gender;				//�ΰ��� �޸� ��� ����� ������ �ٸ���. �̰��� int ��� ���� 4 , char�� ������� 4 , �� char��
		};								// ��� ���� 4 . �� ���� 12byte�� ��.
		struct Student stu;
		printf("size or student = %d\n ", sizeof(stu)); //?? �ٸ��� .. ��?
	}

	printf("�ƹ�Ű�� �Է��Ͻø� ���α׷��� ����˴ϴ�.\n");
	_getch();
	return 0;

}