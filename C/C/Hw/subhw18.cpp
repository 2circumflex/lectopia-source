/* 날짜 : 2012년 2월 10일   
   작성자 : 이로운   
   프로그램의 기능 : 키보드로부터 양수를 입력 받고 그때까지 입력된 숫자의 합을 출력하기 */
#include <stdio.h>
#pragma warning (disable : 4996)
int input();
void output(int);
int main()
{
	int num, sum=0;

	while(1)
	{
		num = input();

		if(num < 0)	{ break;}
		
		sum += num;

		output(sum);
	}	

	return 0;
}

int input()
{
	int su;
	printf("양수를 입력하세요 : ");
	scanf("%d", &su);

	return su;
}

void output(int n)
{
	printf("지금까지 입력된 값의 합 : %d\n", n);

	return;
}