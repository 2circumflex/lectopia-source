/* 날짜 : 2012년 7월 12일   
   작성자 : 이로운   
   프로그램의 기능 : 10진수를 입력 받아 2진수로 출력하는 프로그램 */
#include <stdio.h>
#pragma warning (disable:4996)

int input(short *);
void output(short);
int main()
{
	short jsu;
	int re;
	while(1)
	{
		re = input(&jsu);

		if(re == -1)
		{
			break;
		}
		else if(re == 0)
		{
			printf("잘못입력했음\n\n");
		}
		else if(re == 1)
		{
			output(jsu);
		}
	}

	return 0;
}

int input(short *su)
{
	int ch;
	printf("* 10진수 정수를 입력하시오 : ");
	ch = scanf("%hd", su);
	fflush(stdin);

	return ch;
}

void output(short su)
{
	int i;
	unsigned short a;
	printf("\n%hd(10) = ", su);
	
	for(i=15; i>=0; i--)
	{
		a = su & (0x0001<< i);
		printf("%hu", a>>i);
	}
	printf("(2)\n\n");
}