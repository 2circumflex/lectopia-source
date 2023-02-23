/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 정수값을 입력 받은 후 8진수와 16진수로 출력 진법을 나타내는 접두어도 함께 출력 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int su;

	printf("정수값을 입력하세요 : ");
	scanf("%d", &su);

	printf("입력된 값은 8진수로 %#o 입니다.\n", su);
	printf("입력된 값은 16진수로 %#x 입니다.\n", su);

	return 0;
}