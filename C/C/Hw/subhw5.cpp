/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : cm단위를 입력 받아 M단위와 cm 단위로 환산하여 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int cm;

	printf("cm단위로 입력하세요 : ");
	scanf("%d", &cm);
	
	printf("%dcm => %dM %dcm\n", cm, cm/1000, cm%1000);

	return 0;
}