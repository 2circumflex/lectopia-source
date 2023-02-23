/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : ASCII code를 입력받아 ASCII code에 해당하는 문자를 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int as;

	printf("(입력형태)\n");
	printf("ASCII code값을 입력하시오 : ");
	scanf("%d", &as);

	printf("(출력결과)\n");
	printf("%d은 '%c'의 ASCII code 입니다.\n", as, as);	

	return 0;
}