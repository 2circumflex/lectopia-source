#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
int input();
int prime_number(int);
int main() 
{
	int num, i, cnt=0;

	num = input();

	printf("1~%d까지의 소수값은 다음과 같습니다.\n", num);

	for(i=1; i<=num; i++)
	{
		if(prime_number(i) == 1)
		{
			printf("%-5d ", i);			
			cnt++;

			if(cnt%5==0)	printf("\n");
		}
	}

	printf("\n1~%d까지의 총 소수는 %d개 입니다.\n", num, cnt);

	return 0;
}

int input()
{
	int num;

	printf("* 정수값 하나를 입력하시오  : ");
	scanf("%d", &num);	

	return num;
}

int prime_number(int n)
{
	int i;

	if(n==1)	return 0;

	for(i=1; i<=sqrt((double)n); i++)
	{
		if(i!=1)
		{
			if(n%i==0)
			{
				return 0;
			}
		}
	}
	return 1;
}