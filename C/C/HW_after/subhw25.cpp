#include <stdio.h>
int main() 
{ 
	int pay = 3500;
	int cream = 500;
	int kang = 700;
	int coke = 400;

	int i,j,k;

	printf("현재 당신이 소유하고 있는 금액 : %d원\n", pay);

	for(i=1; i<=((pay-kang-coke)/cream); i++)
	{
		for(j=1; j<=((pay-cream-coke)/kang); j++)
		{
			for(k=1; k<=((pay-cream-kang)/coke); k++)
			{
				if((cream*i)+(kang*j)+(coke*k)==pay)
				{
					printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", i,j,k);
				}
			}
		}
	}
	printf("어떻게 구입하시겠습니까?\n");

	return 0;
} 