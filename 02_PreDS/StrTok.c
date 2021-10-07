#include <stdio.h>
#include <stdlib.h>	 // malloc ,rand atoi ... 가 포함된 헤더
#include <string.h>	 //  memcpy,strcpy ...   ""
#include < conio.h>	 //  _getch , putch ... ( ms 기반 c 비표준 함수 -> 다른 os 에서 사용 불가..)
#include < time.h>  //clock ... 시간 날짜 함수 ..
#pragma warning (disable:4996)  // 4996에러 무시하는 헤더.
int main()
{
	/*char str[40] = "This is c ds";
	printf("str= %s\n", str);

	char *delim = "i "; // delimeter : 구분자  , 이런식으로 하면  i 와 " " 둘 다 딜리미터가 됨.
	char *ptr = strtok(str, delim); // 첫번째 토큰의 포인터를 리턴함 , 단 원본을 바꿔버리게됨..
									// 토큰 문자열 포인터 리턴 , 더이상 잘라낼 토큰이 없다면
									// NULL을 리턴.
	//printf("%s\n", ptr);
	while (ptr != NULL)
	{
		printf("%s\n", ptr);
		ptr = strtok(NULL, delim);  //  
	}
	printf("str= %s\n", str);*/

	{
		/*char str[40] = "2019년-02-20 12:55:44";

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

			printf("%d\n", strspn(str, delimop));   // (두개의 매개변수를 비교하는데 , delimop안에 있는 문자열중에 str에 몇개 있는지 확인하고
													// 갯수로 출력하는 함수 . 단 비교 도중에 delimop안에 있는 문자열에 없는 문자가 str에 나올 
													// 경우 종료하고 갯수를 출력한다.
		}
}
								