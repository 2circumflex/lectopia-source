/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 정수를 입력받아 그 정수보다 10만큼 큰 수까지 출력 */
#include <stdio.h>
#pragma warning (disable : 4996)
int input();
void output(int);
int main()
{
	int su;
	su = input();
	output(su);

	return 0;
}

int input()
{
	int su;
	printf("* 정수를 입력하시오 : ");
	scanf("%d", &su);
	return su;
}

void output(int num)
{
	int i;
	for(i=num; i<=num+10; i++)
	{
		printf("[%d] ", i);
	}
	printf("\n");

	return;
}