/* 날짜 : 2012년 2월 7일   
   작성자 : 이로운   
   프로그램의 기능 : 정수값을 입력받아 1부터 입력한 숫자까지의 총합을 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)

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
	int s;
	printf("# 정수값을 입력하시오 : ");
	scanf("%d", &s);

	return s;
}

void output(int num)
{
	int i=1, tot=0;

	while(i<=num)
	{
		tot += i;
		i++;
	}

	printf("1부터 %d까지의 합은 %d입니다.\n\n", num, tot);

	return;
}


