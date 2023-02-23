/* 날짜 : 2012년 2월 17일   
   작성자 : 이로운   
   프로그램의 기능 : 현금 3500원으로 크림빵(500원), 새우깡(700원), 콜라(400원) 사기 */
#include <stdio.h>
int main()
{	
	int i,j,k, cream=500, kang=700, coke=400, money=3500;

	for(i=1; i<(money/cream); i++)
	{
		for(j=1; j<(money/kang); j++)
		{
			for(k=1; k<(money/coke); k++)
			{
				if( (cream*i)+(kang*j)+(coke*k) == money )
				{
					printf("크림빵(%d개), 새우깡(%d개), 콜라(%d개)\n", i, j, k);
				}				
			}
		}
	}
	printf("어떻게 구입하시겠습니까?\n");

	return 0;
}