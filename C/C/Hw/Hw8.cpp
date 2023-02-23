/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 날 수를 입력 받아 그 값을 주와 날수로 변환하는 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int day;

	printf("*날수를 입력하시오 : ");
	scanf("%d", &day);

	printf("%d일은 %d주 %d일 입니다\n", day, day/7, day%7);	

	return 0;
}