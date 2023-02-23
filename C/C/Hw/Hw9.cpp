/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 이름을 영문으로 입력 받아 다양한 형태로 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	char ename[20];
	
	printf("이름을 입력하시오 : ");
	scanf("%s", ename);

	printf("\"%s\"\n", ename);
	printf("\"%20s\"\n", ename);
	printf("\"%-20s\"\n", ename);

	return 0;
}