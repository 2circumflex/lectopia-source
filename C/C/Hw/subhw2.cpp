/* 날짜 : 2012년 2월 3일   
   작성자 : 이로운   
   프로그램의 기능 : 전기 사용량을 kw단위로 입력하면 사용 요금을 계산 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int sayong;
	double yogm;

	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%d", &sayong);

	yogm = 660 + 88.5 * (double)sayong;
	yogm = yogm + yogm * 0.09;
	
	printf("전기 사용요금은 %lf 원 입니다.\n", yogm);

	return 0;
}