/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 문자열을 입력 받아 문자열을 반만출력하기, 출력시 대괄호로 묶어서 출력하되 반쪽짜리 문자열 뒤에는 생략기호 */
#include <stdio.h>
#include <string.h>
#pragma warning (disable : 4996)

int main()
{
	char mj[20];

	printf("* 문자를 입력하시오 : ");
	scanf("%s", mj);

	 printf("[%*.*s. . .]\n", strlen(mj), strlen(mj)/2, mj);

	return 0;
}