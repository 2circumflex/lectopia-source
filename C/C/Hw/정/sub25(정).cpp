// subhw25  현금으로 크림빵, 새우깡, 콜라 구입하기
// 프로그래머 : 렉토피아 정혜경 강사


#include<stdio.h>
#include<conio.h>

int main()
{
	int i,j,k;
	long money=3500;
	
	for(i=1; i*500<=money; i++)
	{
		for(j=1; j*700<=money; j++)
		{
			for(k=1; k*400<=money; k++)
			{
				if((i*500+j*700+k*400)==money) // 세가지 물건의 가격을 조합한 금액이 3500원 이면 내용을 출력함.
				{ 
					printf("크림빵(%d개), 새우깡(%d봉지), 콜라(%d병) \n", i,j,k);
				}
			}
		}
	}
	printf("어떻게 구입하시겠습니까?\n");
    return 0;

}