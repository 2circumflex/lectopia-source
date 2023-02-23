/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 입력 받은 정수의 2배의 값과 제곱의 값을 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int su;

	printf("(입력형태)\n");
	printf("한 개의 정수를 입력하시오 : ");
	scanf("%d", &su);

	printf("(출력결과)\n");
	printf("%d의 2배수 => %d\n", su, su*2);
	printf("%d의 제곱  => %d\n", su, su*su);

	return 0;
}