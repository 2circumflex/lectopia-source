/* 날짜 : 2012년 2월 6일   
   작성자 : 이로운   
   프로그램의 기능 : 놀이동산 입장객의 나이와 인원수를 입력 받아 입장료를 계싼하여 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

int main()
{
	int age, su, tot, tmoney, per;
	
	while(1)
	{
		printf("입장객의 나이를 입력하시오 : ");
		scanf("%d", &age);

		printf("입장객의 수를 입력하시오 : ");
		scanf("%d", &su);

		if(age >= 56 || age<=7)
		{
			tmoney = 500;
		}
		else if(age >=20)
		{
			tmoney = 1500;
		}
		else if(age >=14)
		{
			tmoney = 1000;
		}
		else if(age >=8)
		{
			tmoney = 700;
		}
		

		if(su>=5)
		{
			per = (int)(tmoney * su * 0.1);
			tmoney = tmoney * su;
			tot = tmoney - per;
		}
		else
		{
			tmoney = tmoney * su;
			per = 0;
			tot = tmoney - per;
		}

		printf("입장료 => %d원\n", tmoney);
		printf("할인금액 => %d원\n", per);
		printf("결제금액 => %d원\n\n", tot);
	}

	return 0;
}