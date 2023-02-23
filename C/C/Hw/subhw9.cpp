/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : 그날 생산한 고무줄의 양과 고객이 요청한 묶음 단위를 입력 받아 포장단위에 맞게 몇개를 포장하고 몇 개의 고무줄이 낱개로 남았는지 출력하시오 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int tot, cus;
	
	while(1)
	{
		printf("오늘 생산된 노란 고무줄의 수량 : ");
		scanf("%d", &tot);
				
		printf("고객이 요청한 묶음 단위 : ");
		scanf("%d", &cus);

		printf("오늘 생산된 노란 고무줄을 %d개단위로 포장하면 총 %d개의 묶음을 만들고 %d개의 고무줄이 낱개로 남습니다.\n\n", cus, tot/cus, tot%cus);
	}

	return 0;
}