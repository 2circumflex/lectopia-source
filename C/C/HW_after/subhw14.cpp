#include <stdio.h>
#pragma warning (disable:4996)

int input();
void output(int);
int main()
{	
	int su;

	while(1)
	{
		su = input();
		output(su);
	}

	return 0;
}

int input()
{
	int su;
	printf("# 정수값을 입력하시오 : ");
	scanf("%d", &su);

	return su;
}

void output(int su)
{
	int hap=0, i;

	for(i=1; i<=su; i++)
	{
		hap += i;
	}

	printf("1부터 %d까지의 합은 %d입니다\n\n", su, hap);
}