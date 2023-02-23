/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : 지하철요금 계신하는 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int su, pay, cho;
	
	while(1)
	{
		printf("역수를 입력하시오 : ");
		scanf("%d", &su);

		if(su!=0 && su<=5)
		{
			printf("요금 : 600원\n\n");
		}
		else if(su<=10)
		{
			printf("요금 : 800원\n\n");
		}
		else if(su>10)
		{
			cho = su - 10;
			
			if(cho%2 !=0)
			{
				pay = 800 + (cho/2) * 100 + 100;
			}
			else
			{
				pay = 800 + (cho/2) * 100;
			}
			printf("요금 : %d원\n\n", pay);
		}
	}

	return 0;
}