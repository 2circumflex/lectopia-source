/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 두 정수를 입력 받아 합, 차, 곱, 몫의 값을 출력하는 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int a, b;

	printf("(입력형태)\n");
	printf("두개의 정수를 입력하시오 : ");
	scanf("%d %d", &a, &b);

	printf("(출력결과)\n");
	printf("%d+%d = %d\n", a, b, a+b);
	printf("%d-%d = %d\n", a, b, a-b);
	printf("%d*%d = %d\n", a, b, a*b);
	printf("%d/%d = %.2lf\n", a, b, (double)a/(double)b);	

	return 0;
}