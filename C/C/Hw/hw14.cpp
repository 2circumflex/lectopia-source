/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : Pay 계산하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int hour, chour, gpay, tx, npay;


	while(1)
	{
		printf("* 1주일간의 근무시간을 입력하시오 : ");
		scanf("%d", &hour);
				
		if(hour>40)
		{
			chour = hour - 40;
			chour = (int)(chour * 3000 * 1.5);
			gpay = 40 * 3000 + chour;		
		}
		else
		{
			gpay = hour * 3000;
		}

		if(gpay > 100000)
		{
			tx = 15000 + (int)((gpay - 100000) * 0.25);				
			npay = gpay - tx;
		}
		else
		{
			tx = (int)(gpay * 0.15);
			npay = gpay - tx;
		}
	
		printf("# 총수입 : %6d원\n", gpay);
		printf("# 세  금 : %6d원\n", tx);
		printf("# 실수입 : %6d원\n\n", npay);
	}

	return 0;
}