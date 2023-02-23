/* 날짜 : 2012년 2월 7일   
   작성자 : 이로운   
   프로그램의 기능 : 정수값을 입력받아 그 숫자 만큼 별(*)을 출력하되 한줄에 5개씩 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

void output(int);
int input();
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
	int num;
	
	printf("# 정수값을 입력하세요 : ");
	scanf("%d", &num);

	return num;
}

void output(int num)
{
	int fstar = num/5;
	int nstar = num%5;
	while(fstar > 0)
	{
		printf("*****\n");
		fstar--;
	}
	while(nstar > 0)
	{
		printf("*");
		nstar--;
	}
	printf("\n");

	return;
}