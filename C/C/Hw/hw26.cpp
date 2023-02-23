/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 소수 출력하기 */
#include <stdio.h>
#include <math.h>
#pragma warning (disable : 4996)
int input();
void prime_number(int);
int main()
{
	int num;

	num = input();

	prime_number(num);	

	return 0;
}
int input()
{
	int su;
	
	printf("*정수값 하나를 입력하시오 : ");
	scanf("%d", &su);
	
	return su;
}

void prime_number(int num)
{
	int i, j, ox, add=0;
	
	for(i=2; i<=num; i++)
	{		
		ox = 0;
		for(j=2; j<=sqrt((double)i); j++)
		{
			if(i%j==0)
			{
				ox = 1;
				break;
			}			
		}
		if(ox==0)
		{
			add++;
			printf("%-5d", i);

			if(add%5==0)
			{
				printf("\n");
			}
		}
	}
	printf("\n1~%d까지의 총 소수는 %d개 입니다.\n", num, add);
	
	return;
}
