/* 날짜 : 2012년 2월 9일   
   작성자 : 이로운   
   프로그램의 기능 : 10진수를 입력 받아 2진수로 출력하는 프로그램 */
#include <stdio.h>
#pragma warning (disable : 4996)
int input(short *);
void output(short);
int main()
{
	int res;
	short su;

	while(1)
	{
		res = input(&su);

		if(res == -1)
		{
			break;
		}
		else
		{
			output(su);
		}
	}

	return 0;
}

void output(short num)
{
	int i=0;
	short res;
	unsigned short sh = 0x8000;
	printf("\n%hd(10) = ", num);
	
	while(i<16)
	{
		res = num & sh;
		sh = sh>>1;

		if(res == 0)
		{
			printf("0");
		}
		else
		{
			printf("1");
		}
		i++;
	}
	printf("(2)\n\n");
	
	return;
}

int input(short *su)
{
	int res;

	printf("* 10진수 정수를 입력하시오 : ");	
	fflush(stdin);
	res = scanf("%hd", su);

	while(res == 0)
	{
		printf("잘못 입력하셨습니다. 다시 입력하십시오 : ");
		fflush(stdin);
		res = scanf("%hd", su);

		if(res == -1)
		{
			break;
		}
	}

	return  res;
}