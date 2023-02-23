/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : 관광용 레저카 이용료, 거스름돈 계산 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int km, tot, money, change;
	
	while(1)
	{
		printf("레저카를 사용한 거리를 KM 단위로 입력하세요 : ");
		scanf("%d", &km);
				
		tot = km * 500 + (int)((km * 500) * 0.1);
		printf("총 이용료 : %d원\n", tot);
		printf("이용료 정산을 위해 지불한 금액을 원단위로 입력하세요 : ");
		scanf("%d", &money);
		change = money - tot;
		printf("거스름돈 : %d원\n\n", change);
	}

	return 0;
}