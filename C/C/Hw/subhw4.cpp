/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 화씨온도를 입력 받고 섭씨 온도를 계산하여 출력하기, 섭씨온도는 소수점 이하 첫째자리까지 출력 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	double hwac, subc;

	printf("화씨 온도를 입력하세요 : ");
	scanf("%lf", &hwac);

	subc = 5.0 / 9.0 * (hwac - 32.0);

	printf("섭씨 온도는 %.1lf 도 입니다.\n", subc);

	return 0;
}